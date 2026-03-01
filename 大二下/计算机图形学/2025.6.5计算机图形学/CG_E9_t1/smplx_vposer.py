# -*- coding: utf-8 -*-
# 设置文件编码为 UTF-8

# Max-Planck-Gesellschaft zur Förderung der Wissenschaften e.V. (MPG) is
# holder of all proprietary rights on this computer program.
# 版权声明，禁止未经授权使用

import os.path as osp  # 导入 os.path 并重命名为 osp，用于处理文件路径
import argparse  # 导入 argparse，用于解析命令行参数

import numpy as np  # 导入 numpy，用于数值计算
import torch  # 导入 PyTorch，用于张量操作和深度学习
import smplx  # 导入 smplx，用于加载和操作人体模型

# 定义主函数，包含模型加载、随机采样、输出处理和可视化
def main(model_folder,
         model_type='smplx',  # 模型类型，默认为 smplx
         ext='npz',  # 模型文件扩展名，默认为 npz
         gender='neutral',  # 模型性别，默认为中性
         plot_joints=False,  # 是否绘制关节点，默认为 False
         num_betas=10,  # 形状参数数量，默认为 10
         sample_shape=True,  # 是否随机采样形状，默认为 True
         sample_expression=True,  # 是否随机采样表情，默认为 True
         num_expression_coeffs=10,  # 表情参数数量，默认为 10
         plotting_module='pyrender',  # 可视化模块，默认为 pyrender
         use_face_contour=False):  # 是否使用面部轮廓，默认为 False

    # 使用 smplx 库创建人体模型
    model = smplx.create(model_folder, model_type=model_type,
                         gender=gender, use_face_contour=use_face_contour,
                         num_betas=num_betas,
                         num_expression_coeffs=num_expression_coeffs,
                         ext=ext)
    print(model)  # 打印模型信息

    torch.manual_seed(2333)  # 设置随机种子以保证结果可复现
    betas, expression = None, None  # 初始化形状和表情参数为 None
    if sample_shape:  # 如果需要随机采样形状
        betas = torch.randn([1, model.num_betas], dtype=torch.float32)  # 随机生成形状参数
        # body_pose = torch.full([1, 21, 3], 0.0, dtype=torch.float32)  # 初始化为固定值0.5
        # body_pose = torch.zeros([1, 21, 3], dtype=torch.float32) # 初始参数为0，关节点偏移=0
        body_pose = torch.randn([1, 21, 3], dtype=torch.float32)
    if sample_expression:  # 如果需要随机采样表情
        expression = torch.randn(
            [1, model.num_expression_coeffs], dtype=torch.float32)  # 随机生成表情参数

    # VPoser优化刚刚随机生成的body_pose
    expr_dir = osp.join(model_folder, 'vposer', 'V02_05') 
    #'TRAINED_MODEL_DIRECTORY'  in this directory the trained model along with the model code exist
    print(f'Loading VPoser from {expr_dir}')  # 打印加载 VPoser 的目录
    from human_body_prior.tools.model_loader import load_model
    from human_body_prior.models.vposer_model import VPoser
    vp, ps = load_model(expr_dir, model_code=VPoser,
                                remove_words_in_model_weights='vp_model.',
                                disable_grad=True)
    

    body_pose = body_pose.reshape(1, -1)
    body_poZ = vp.encode(body_pose).mean
    body_pose_rec = vp.decode(body_poZ)['pose_body'].contiguous().view(-1, 63)
    
    t = np.random.choice(len(body_pose))
    all_pose_body = torch.stack([body_pose[t], body_pose_rec[t]])

    # 使用模型生成输出，包括顶点和关节
    output = model(betas=betas, expression=expression, body_pose=body_pose_rec,
                   return_verts=True)
    vertices = output.vertices.detach().cpu().numpy().squeeze()  # 提取顶点数据并转换为 NumPy 数组
    joints = output.joints.detach().cpu().numpy().squeeze()  # 提取关节数据并转换为 NumPy 数组
    #print(output)
    #print(joints)

    # print('Vertices shape =', vertices.shape)  # 打印顶点数据的形状
    # print('Joints shape =', joints.shape)  # 打印关节数据的形状

    # 根据选择的可视化模块进行渲染
    if plotting_module == 'pyrender':
        import pyrender  # 导入 pyrender，用于渲染 3D 模型
        import trimesh  # 导入 trimesh，用于处理三角网格
        vertex_colors = np.ones([vertices.shape[0], 4]) * [0.3, 0.3, 0.3, 0.8]  # 设置顶点颜色
        tri_mesh = trimesh.Trimesh(vertices, model.faces,
                                   vertex_colors=vertex_colors)  # 创建三角网格

        mesh = pyrender.Mesh.from_trimesh(tri_mesh)  # 转换为 pyrender 的 Mesh 对象

        scene = pyrender.Scene()  # 创建渲染场景
        scene.add(mesh)  # 将网格添加到场景中

        if plot_joints:  # 如果需要绘制关节点
            sm = trimesh.creation.uv_sphere(radius=0.005)  # 创建小球表示关节点
            sm.visual.vertex_colors = [0.9, 0.1, 0.1, 1.0]  # 设置关节点颜色
            tfs = np.tile(np.eye(4), (len(joints), 1, 1))  # 创建关节点的变换矩阵
            tfs[:, :3, 3] = joints  # 设置关节点的位置
            joints_pcl = pyrender.Mesh.from_trimesh(sm, poses=tfs)  # 转换为 pyrender 的 Mesh 对象
            scene.add(joints_pcl)  # 将关节点添加到场景中

        pyrender.Viewer(scene, use_raymond_lighting=True)  # 使用 pyrender 渲染场景
    elif plotting_module == 'matplotlib':
        from matplotlib import pyplot as plt  # 导入 matplotlib，用于绘图
        from mpl_toolkits.mplot3d import Axes3D  # 导入 3D 绘图工具
        from mpl_toolkits.mplot3d.art3d import Poly3DCollection  # 导入 3D 多边形集合

        fig = plt.figure()  # 创建绘图窗口
        ax = fig.add_subplot(111, projection='3d')  # 添加 3D 子图

        mesh = Poly3DCollection(vertices[model.faces], alpha=0.1)  # 创建 3D 网格
        face_color = (1.0, 1.0, 0.9)  # 设置面颜色
        edge_color = (0, 0, 0)  # 设置边颜色
        mesh.set_edgecolor(edge_color)  # 应用边颜色
        mesh.set_facecolor(face_color)  # 应用面颜色
        ax.add_collection3d(mesh)  # 将网格添加到子图中
        ax.scatter(joints[:, 0], joints[:, 1], joints[:, 2], color='r')  # 绘制关节点

        if plot_joints:  # 如果需要绘制关节点
            ax.scatter(joints[:, 0], joints[:, 1], joints[:, 2], alpha=0.1)  # 绘制关节点
        plt.show()  # 显示绘图
    elif plotting_module == 'open3d':
        import open3d as o3d  # 导入 open3d，用于 3D 可视化

        mesh = o3d.geometry.TriangleMesh()  # 创建三角网格对象
        mesh.vertices = o3d.utility.Vector3dVector(
            vertices)  # 设置顶点数据
        mesh.triangles = o3d.utility.Vector3iVector(model.faces)  # 设置三角形数据
        mesh.compute_vertex_normals()  # 计算顶点法线
        mesh.paint_uniform_color([0.3, 0.3, 0.3])  # 设置网格颜色

        geometry = [mesh]  # 初始化几何对象列表
        if plot_joints:  # 如果需要绘制关节点
            joints_pcl = o3d.geometry.PointCloud()  # 创建点云对象
            joints_pcl.points = o3d.utility.Vector3dVector(joints)  # 设置关节点数据
            joints_pcl.paint_uniform_color([0.7, 0.3, 0.3])  # 设置关节点颜色
            geometry.append(joints_pcl)  # 将关节点添加到几何对象列表中

        o3d.visualization.draw_geometries(geometry)  # 使用 open3d 渲染几何对象
    else:
        raise ValueError('Unknown plotting_module: {}'.format(plotting_module))  # 抛出异常，提示未知的可视化模块

    import os  # 导入 os 模块，用于文件操作
    # 保存网格模型到文件
    output_dir = osp.join(model_folder, '..', 'output_meshes')  # 设置输出目录
    os.makedirs(output_dir, exist_ok=True)  # 创建输出目录（如果不存在）

    mesh_filename = osp.join(output_dir, f'{model_type}_mesh.obj')  # 设置输出文件名
    with open(mesh_filename, 'w') as f:  # 打开文件以写入
        for vertex in vertices:  # 遍历顶点数据
            f.write(f'v {vertex[0]} {vertex[1]} {vertex[2]}\n')  # 写入顶点数据到文件
        for face in model.faces + 1:  # 遍历面数据（OBJ 格式使用 1-based 索引）
            f.write(f'f {face[0]} {face[1]} {face[2]}\n')  # 写入面数据到文件

        print(f'Mesh saved to {mesh_filename}')  # 打印保存成功的信息

    # 导出关节点的变换矩阵为 pkl 文件
    import os
    output_dir = osp.join(model_folder, '..', 'output_poses')  # 设置输出目录
    os.makedirs(output_dir, exist_ok=True)  # 创建输出目录（如果不存在）

    import pickle  # 导入 pickle，用于序列化数据
    poses = {}

    poses['body_pose'] = body_pose_rec.detach().cpu().numpy()  # 提取身体姿态并展平


    print(poses['body_pose'].shape)
    #poses['global_orient'] = output.global_orient.detach().cpu().numpy().reshape(1, -1)  # 提取全局方向并展平
    poses['left_hand_pose'] = output.left_hand_pose.detach().cpu().numpy().reshape(1, -1)  # 提取左手姿态并展平
    poses['right_hand_pose'] = output.right_hand_pose.detach().cpu().numpy().reshape(1, -1)  # 提取右手姿态并展平
    poses['jaw_pose'] = output.jaw_pose.detach().cpu().numpy().reshape(1, -1)  # 提取下巴姿态并展平
    #poses['leye_pose'] = output.leye_pose.detach().cpu().numpy()  # 提取左眼姿态
    #poses['reye_pose'] = output.reye_pose.detach().cpu().numpy()  # 提取右眼姿态
    poses['expression'] = output.expression.detach().cpu().numpy()  # 提取表情参数
    poses['betas'] = betas.detach().cpu().numpy() if betas is not None else None  # 提取形状参数
    print(poses)
    #poses['joints'] = joints  # 添加关节数据
    #output = {'poses': poses, 'joints': joints}  # 创建输出字典，包含姿态和关节数据
    joints_filename = osp.join(output_dir, f'{model_type}_joints.pkl')  # 设置输出文件名
    with open(joints_filename, 'wb') as f:  # 打开文件以写入
        pickle.dump(poses, f)  # 序列化并保存变换矩阵

    # bpy.context.space_data.params.directory = "D:\\projects\\CG_E9_data\\output_poses\\smplx_joints.pkl"
    print(f'Transforms saved to {joints_filename}')  # 打印保存成功的信息

# 主程序入口
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='SMPL-X Demo')  # 创建命令行参数解析器

    # 添加命令行参数
    parser.add_argument('--model-folder', required=True, type=str,
                        help='The path to the model folder')  # 模型文件夹路径
    parser.add_argument('--model-type', default='smplx', type=str,
                        choices=['smpl', 'smplh', 'smplx', 'mano', 'flame'],
                        help='The type of model to load')  # 模型类型
    parser.add_argument('--gender', type=str, default='neutral',
                        help='The gender of the model')  # 模型性别
    parser.add_argument('--num-betas', default=10, type=int,
                        dest='num_betas',
                        help='Number of shape coefficients.')  # 形状参数数量
    parser.add_argument('--num-expression-coeffs', default=10, type=int,
                        dest='num_expression_coeffs',
                        help='Number of expression coefficients.')  # 表情参数数量
    parser.add_argument('--plotting-module', type=str, default='pyrender',
                        dest='plotting_module',
                        choices=['pyrender', 'matplotlib', 'open3d'],
                        help='The module to use for plotting the result')  # 可视化模块
    parser.add_argument('--ext', type=str, default='npz',
                        help='Which extension to use for loading')  # 模型文件扩展名
    parser.add_argument('--plot-joints', default=False,
                        type=lambda arg: arg.lower() in ['true', '1'],
                        help='The path to the model folder')  # 是否绘制关节点
    parser.add_argument('--sample-shape', default=True,
                        dest='sample_shape',
                        type=lambda arg: arg.lower() in ['true', '1'],
                        help='Sample a random shape')  # 是否随机采样形状
    parser.add_argument('--sample-expression', default=True,
                        dest='sample_expression',
                        type=lambda arg: arg.lower() in ['true', '1'],
                        help='Sample a random expression')  # 是否随机采样表情
    parser.add_argument('--use-face-contour', default=False,
                        type=lambda arg: arg.lower() in ['true', '1'],
                        help='Compute the contour of the face')  # 是否使用面部轮廓

    args = parser.parse_args()  # 解析命令行参数

    # 提取命令行参数并传递给主函数
    model_folder = osp.expanduser(osp.expandvars(args.model_folder))  # 展开路径中的环境变量和用户目录
    model_type = args.model_type  # 模型类型
    plot_joints = args.plot_joints  # 是否绘制关节点
    use_face_contour = args.use_face_contour  # 是否使用面部轮廓
    gender = args.gender  # 模型性别
    ext = args.ext  # 模型文件扩展名
    plotting_module = args.plotting_module  # 可视化模块
    num_betas = args.num_betas  # 形状参数数量
    num_expression_coeffs = args.num_expression_coeffs  # 表情参数数量
    sample_shape = args.sample_shape  # 是否随机采样形状
    sample_expression = args.sample_expression  # 是否随机采样表情

    # 调用主函数
    main(model_folder, model_type, ext=ext,
         gender=gender, plot_joints=plot_joints,
         num_betas=num_betas,
         num_expression_coeffs=num_expression_coeffs,
         sample_shape=sample_shape,
         sample_expression=sample_expression,
         plotting_module=plotting_module,
         use_face_contour=use_face_contour)
