# 质点-弹簧系统模拟，在本实验中将布料建模为弹簧质点系统
# cpu版本未设置深度测试与透视，渲染层次可能会有问题，但不影响物理模拟
# python mass_spring_3d_offline.py --use-ggui -a "gpu"
# python mass_spring_3d_offline.py -a "cpu"

# init后输出的为实际选择的渲染架构
import taichi as ti
# ti.init(arch=ti.cpu)  # Alternatively, ti.init(arch=ti.cpu)
# cpu gpu cuda vulkan metal opengl

# 解析命令行参数，设置渲染架构和是否使用GGUI
import argparse
import numpy as np
parser = argparse.ArgumentParser()
parser.add_argument("-g", "--use-ggui", action="store_true", help="Display with GGUI",
                    default=False)
parser.add_argument(
    "-a",
    "--arch",
    required=False,
    default="cpu",
    dest="arch",
    type=str,
    help="The arch (backend) to run this example on",
)
args, unknowns = parser.parse_known_args()

arch = args.arch
if arch in ["x64", "cpu", "arm64"]:
    ti.init(arch=ti.cpu)
elif arch in ["cuda", "gpu"]:
    ti.init(arch=ti.cuda)
else:
    raise ValueError("Only CPU and CUDA backends are supported for now.")

use_ggui = args.use_ggui


# 布料设置为n*n的质点网格，其中不同的n值会影响布料的精细程度
# 布料大小固定为1*1，n越大，布料越精细
n = 32
quad_size = 1.0 / n # 设置间隔

# 在原示例代码中代码中，时间步长由n设置，此处我们新定义N来手动设置时间步长
# dt = 4e-2 / n       # 设置时间步长
# substeps = int(1 / 60 // dt) # 设置每帧模拟的次数
N = 256
dt = 4e-2 / N       # 设置时间步长
substeps = int(1 / 60 // dt) # 设置每帧模拟的次数（并非实际运行结果）
print(f"Time step: {dt}, Substeps per frame: {substeps}")

# 力的固定信息
gravity = ti.Vector([0, -9.8, 0])   # 重力加速度9.8m/s^2
spring_Y = 3e4                      # 弹簧刚度
dashpot_damping = 1e4               # 内力的阻尼系数
drag_damping = 1                    # 震动的阻尼系数

# 球体设置为固定物体，用于碰撞检测
ball_radius = 0.3                   # 球体半径
ball_center = ti.Vector.field(3, dtype=float, shape=(1, ))
ball_center[0] = [0, 0, 0]          # 球体位置

# x为质点位置，v为质点速度
# 质点位置的三维分别为水平左右、垂直上下、屏幕内外
x = ti.Vector.field(3, dtype=float, shape=(n, n))
v = ti.Vector.field(3, dtype=float, shape=(n, n))

# 布料每个矩形分割为两个三角片
num_triangles = (n - 1) * (n - 1) * 2
indices = ti.field(int, shape=num_triangles * 3)
vertices = ti.Vector.field(3, dtype=float, shape=n * n)
colors = ti.Vector.field(3, dtype=float, shape=n * n)

bending_springs = False     # 不使用弯曲弹簧

# 初始化质点位置，初始速度为0
# 垂直位置固定为0.6（球体半径*2），整体水平位置随机偏移（0.05范围内）
@ti.kernel
def initialize_mass_points():
    # ti.random()返回[0, 1)之间的随机浮点数
    # random_offset = ti.Vector([ti.random() - 0.5, ti.random() - 0.5]) * 0.1
    random_offset = ti.Vector([0.0, 0.0])  # 不使用随机偏移，保持布料位置不变

    for i, j in x:
        x[i, j] = [
            i * quad_size - 0.5 + random_offset[0], 
            0.6,
            j * quad_size - 0.5 + random_offset[1]
        ]
        v[i, j] = [0, 0, 0]

# 初始化布料的三角网格
@ti.kernel
def initialize_mesh_indices():
    # 每个矩形被分解为2个三角片，顶点从0到n*n-1
    for i, j in ti.ndrange(n - 1, n - 1):
        quad_id = (i * (n - 1)) + j
        # 三角片1
        indices[quad_id * 6 + 0] = i * n + j
        indices[quad_id * 6 + 1] = (i + 1) * n + j
        indices[quad_id * 6 + 2] = i * n + (j + 1)
        # 三角片1
        indices[quad_id * 6 + 3] = (i + 1) * n + j + 1
        indices[quad_id * 6 + 4] = i * n + (j + 1)
        indices[quad_id * 6 + 5] = (i + 1) * n + j

    # 设置三角片颜色，便于观察质点的位置变化
    for i, j in ti.ndrange(n, n):
        if (i // 4 + j // 4) % 2 == 0:
            colors[i * n + j] = (0.22, 0.72, 0.52) # 绿色
        else:
            colors[i * n + j] = (1, 0.334, 0.52)   # 粉色

initialize_mesh_indices()

# 弹簧的偏移量，用于计算内力，只考虑距离小于等于2的质点
spring_offsets = []
for i in range(-2, 3):
    for j in range(-2, 3):
        if (i, j) != (0, 0) and abs(i) + abs(j) <= 2:
            spring_offsets.append(ti.Vector([i, j]))
print(spring_offsets)

# 用于进行弹簧质点系统的迭代
@ti.kernel # 并行计算所有最外层for循环
def substep():

    # 重力迭代
    for i in ti.grouped(x): # 分组向量，每个不同位置的元素并行计算
        v[i] += gravity * dt # 注意此处gravity为向量

    # 更新弹簧系统内部对质点的影响，将弹簧内力转变为速度
    for i in ti.grouped(x): # 分组向量，每个元素并行计算
        force = ti.Vector([0.0, 0.0, 0.0])
        for spring_offset in ti.static(spring_offsets):
            j = i + spring_offset
            if 0 <= j[0] < n and 0 <= j[1] < n:
                x_ij = x[i] - x[j]
                v_ij = v[i] - v[j]
                d = x_ij.normalized()   # 单位向量，方向
                current_dist = x_ij.norm()                      # 当前质点i、质点j之间的距离（大小）
                original_dist = quad_size * float(i - j).norm() # 原始布料内i、j的距离
                # 弹簧内力，根据胡克定律计算，F=-k*x，x为弹簧伸长量，即i、j间距离的变化量
                #   再根据当前方向，得到每个方向上的伸长量，进而得到每个方向的内力
                # 系数k为弹簧刚度，此处为spring_Y，并根据原始距离除法加权
                force += -spring_Y * d * (current_dist / original_dist - 1) 
                # 阻尼力，阻尼系数乘以相邻点在该点的速度投影，与弹簧的初始长度相关
                force += -v_ij.dot(d) * d * dashpot_damping * quad_size

        v[i] += force * dt # 更新受弹簧内力影响的速度

    # 更新质点本身的速度，并据此更新质点位置
    for i in ti.grouped(x): # 分组向量，每个元素并行计算
        # 弹簧本身的阻尼，弹簧存储的能量会随震动消失，乘法加权
        v[i] *= ti.exp(-drag_damping * dt)

        # 与刚性球体碰撞后，法线方向的速度分量变化，更新速度
        offset_to_center = x[i] - ball_center[0]   
        if offset_to_center.norm() <= ball_radius:
            normal = offset_to_center.normalized()      # 法线方向 
            v[i] -= min(v[i].dot(normal), 0) * normal   # 公式为v' = v - 2(v·n)n
        # 根据更新后的速度，更新质点位置

    for i in ti.grouped(x): # 分组向量，每个不同位置的元素并行计算
        x[i] += dt * v[i]

# 渲染，将布料作为三角网格，球体作为粒子
@ti.kernel
def update_vertices():
    for i, j in ti.ndrange(n, n):
        vertices[i * n + j] = x[i, j]
    
current_t = 0.0
initialize_mass_points()

from datetime import datetime
real_t = datetime.now()

import os
import shutil
if os.path.exists("results"):
    shutil.rmtree("results")
os.makedirs("results", exist_ok=True)  # 确保结果目录存在

if not use_ggui:
    res = (500, 500)
    print("Using Taichi GUI for rendering. Press ESC to exit.")
    gui = ti.GUI("Implicit Mass Spring System", res, 
                 show_gui=False, background_color=ti.rgb_to_hex((1, 1, 1)))  # 设置背景颜色为白色
    scene = ti.ui.Scene()
    camera = ti.ui.Camera()

    while gui.running:
        # 超过1.5s重置
        if current_t > 1.5:
            initialize_mass_points()
            current_t = 0

            delta_real_t = datetime.now() - real_t
            print(f"Time taken for 1.5s simulation: {delta_real_t.total_seconds()} seconds")
            real_t = datetime.now()
            break

        # 每帧模拟substeps次，并更新质点位置，随时间步长dt设置
        for i in range(substeps):
            substep()
            current_t += dt
        update_vertices()

        pose_offset = (0.5, 0.5)  # 居中显示
        #pose_off = (1, 1)
        #print(ball_center[0].xy)

        # 绘制球体
        gui.circle(pos=ball_center[0].xy+pose_offset, radius=int(ball_radius*res[0]), color=ti.rgb_to_hex((0.5, 0.42, 0.8) * 255))  # 球体颜色为紫色

        # 绘制三角形网格，只保留比球体更近的三角片
        # 批量处理三角面，显示为 gui.triangles
        triangle_positions1 = np.zeros((num_triangles, 2), dtype=float)
        triangle_positions2 = np.zeros((num_triangles, 2), dtype=float)
        triangle_positions3 = np.zeros((num_triangles, 2), dtype=float)
        # print(num_triangles, triangle_positions3.shape)
        triangle_colors = np.zeros((num_triangles, 3), dtype=float)
        for i in range(num_triangles):
            p1 = vertices[indices[i * 3 + 0]]
            p2 = vertices[indices[i * 3 + 1]]
            p3 = vertices[indices[i * 3 + 2]]

            triangle_positions1[i] = [p1.x + pose_offset[0], p1.y + pose_offset[1]]
            triangle_positions2[i] = [p2.x + pose_offset[0], p2.y + pose_offset[1]]
            triangle_positions3[i] = [p3.x + pose_offset[0], p3.y + pose_offset[1]]
            
            triangle_colors[i] = colors[indices[i * 3 + 0]]  # 转换为 RGB 颜色

            # 计算三角形中心位置
            center = (triangle_positions1[i] + triangle_positions2[i] + triangle_positions3[i]) / 3.0
            
            k = 2
            # 更新三角形顶点位置，使其放大 k 倍
            triangle_positions1[i] = center + (triangle_positions1[i] - center) * k
            triangle_positions2[i] = center + (triangle_positions2[i] - center) * k
            triangle_positions3[i] = center + (triangle_positions3[i] - center) * k
        # i=0
        # print(triangle_positions1[i], triangle_positions2[i], triangle_positions3[i], triangle_colors[i])

        gui.triangles(triangle_positions1, triangle_positions2, triangle_positions3, color=np.array([ti.rgb_to_hex(color) for color in triangle_colors]))
        
        print(f"Current time: {current_t:.3f} seconds")
        # gui.show()
        gui.show(f"results/{current_t:.3f}.png")
else:
    print("Using GGUI for rendering. Press ESC to exit.")
    # 图形化显示
    window = ti.ui.Window("301 mass-spring system", (500, 500),
                        vsync=True, show_window = False)
    canvas = window.get_canvas()
    canvas.set_background_color((1, 1, 1)) # 设置背景颜色为白色
    scene = ti.ui.Scene()
    camera = ti.ui.Camera()
    gui = window.get_gui()

    while window.running:
        # 超过1.5s重置
        if current_t > 1.5:
            initialize_mass_points()
            current_t = 0

            delta_real_t = datetime.now() - real_t
            print(f"Time taken for 1.5s simulation: {delta_real_t.total_seconds()} seconds")
            real_t = datetime.now()
            break

        # 每帧模拟substeps次，并更新质点位置，随时间步长dt设置
        for i in range(substeps):
            substep()
            current_t += dt
        update_vertices()

        # 相机位置设为3，观察点设为0
        camera.position(0.0, 0.0, 3)
        camera.lookat(0.0, 0.0, 0)
        scene.set_camera(camera)

        scene.point_light(pos=(0, 1, 2), color=(1, 1, 1))   # 设置点光源
        scene.ambient_light((0.5, 0.5, 0.5))                # 设置环境光

        # 设置mesh，vertices为质点位置（不断更新），indices为三角网格，colors为质点颜色
        scene.mesh(vertices,
                indices=indices,
                per_vertex_color=colors,
                two_sided=True)

        # 显示刚性球体
        scene.particles(ball_center, radius=ball_radius * 0.95, color=(0.5, 0.42, 0.8))

        canvas.scene(scene)
        # window.show()
        window.save_image(f"results/{current_t:.3f}.png")