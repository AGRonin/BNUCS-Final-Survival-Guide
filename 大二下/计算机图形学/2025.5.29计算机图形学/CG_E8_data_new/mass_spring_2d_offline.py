# https://www.cs.cmu.edu/~baraff/papers/sig98.pdf
# python mass_spring_2d_offline.py --use-ggui -a "cpu"
# python mass_spring_2d_offline.py -a "cpu"

import argparse

import numpy as np

import taichi as ti

@ti.data_oriented
class Cloth:
    def __init__(self, N):
        self.N = N  # 网格的大小
        self.NF = 2 * N**2  # 面的数量
        self.NV = (N + 1) ** 2  # 顶点的数量
        self.NE = 2 * N * (N + 1) + 2 * N * N  # 边的数量

        # 每个顶点的信息，其中速度方向、受力方向为二维信息
        self.pos = ti.Vector.field(2, ti.f32, self.NV)  # 顶点位置
        self.initPos = ti.Vector.field(2, ti.f32, self.NV)  # 初始顶点位置
        self.vel = ti.Vector.field(2, ti.f32, self.NV)  # 顶点速度
        self.force = ti.Vector.field(2, ti.f32, self.NV)  # 顶点受力
        self.mass = ti.field(ti.f32, self.NV)  # 顶点质量
        self.vel_1D = ti.ndarray(ti.f32, 2 * self.NV)  # 一维速度数组
        self.force_1D = ti.ndarray(ti.f32, 2 * self.NV)  # 一维受力数组
        self.b = ti.ndarray(ti.f32, 2 * self.NV)  # 右端项向量

        # 每个弹簧的信息，即相邻边的数目
        self.spring = ti.Vector.field(2, ti.i32, self.NE)  # 弹簧连接的顶点索引
        self.indices = ti.field(ti.i32, 2 * self.NE)  # 用于绘制的索引
        self.Jx = ti.Matrix.field(2, 2, ti.f32, self.NE)  # 位置雅可比矩阵
        self.Jv = ti.Matrix.field(2, 2, ti.f32, self.NE)  # 速度雅可比矩阵
        self.rest_len = ti.field(ti.f32, self.NE)  # 弹簧的初始长度

        # 力的参数
        self.ks = 1000.0  # 弹簧刚度系数
        self.kd = 0.5  # 阻尼系数
        self.kf = 1.0e5  # 固定点刚度系数
        self.gravity = ti.Vector([0.0, -2.0])  # 重力加速度

        self.init_pos()  # 初始化顶点位置
        self.init_edges()  # 初始化弹簧连接

        # 构造稀疏矩阵，用于后续求解
        self.MassBuilder = ti.linalg.SparseMatrixBuilder(2 * self.NV, 2 * self.NV, max_num_triplets=10000)  # 质量矩阵构造器
        self.DBuilder = ti.linalg.SparseMatrixBuilder(2 * self.NV, 2 * self.NV, max_num_triplets=10000)  # 阻尼矩阵构造器
        self.KBuilder = ti.linalg.SparseMatrixBuilder(2 * self.NV, 2 * self.NV, max_num_triplets=10000)  # 刚度矩阵构造器
        self.init_mass_sp(self.MassBuilder)  # 初始化质量矩阵
        self.M = self.MassBuilder.build()  # 构建质量矩阵
        self.fix_vertex = [self.N, self.NV - 1]  # 固定的顶点索引
        self.Jf = ti.Matrix.field(2, 2, ti.f32, len(self.fix_vertex))  # 固定点约束的雅可比矩阵

    # 初始化顶点位置和速度，位置为方格、速度为零、质量为1
    @ti.kernel
    def init_pos(self):
        for i, j in ti.ndrange(self.N + 1, self.N + 1):
            k = i * (self.N + 1) + j  # 计算顶点索引
            self.pos[k] = ti.Vector([i, j]) / self.N * 0.5 + ti.Vector([0.25, 0.25])  # 初始化顶点位置
            self.initPos[k] = self.pos[k]  # 保存初始位置
            self.vel[k] = ti.Vector([0, 0])  # 初始化速度为零
            self.mass[k] = 1.0  # 初始化质量为1

    # 初始化弹簧连接和初始长度，每个弹簧连接两个顶点（即相邻边）
    @ti.kernel
    def init_edges(self):
        pos, spring, N, rest_len = ti.static(self.pos, self.spring, self.N, self.rest_len)
        for i, j in ti.ndrange(N + 1, N):  # 水平弹簧
            idx, idx1 = i * N + j, i * (N + 1) + j
            spring[idx] = ti.Vector([idx1, idx1 + 1])  # 连接相邻顶点
            rest_len[idx] = (pos[idx1] - pos[idx1 + 1]).norm()  # 计算初始长度
        start = N * (N + 1)
        for i, j in ti.ndrange(N, N + 1):  # 垂直弹簧
            idx, idx1, idx2 = (
                start + i + j * N,
                i * (N + 1) + j,
                i * (N + 1) + j + N + 1,
            )
            spring[idx] = ti.Vector([idx1, idx2])  # 连接相邻顶点
            rest_len[idx] = (pos[idx1] - pos[idx2]).norm()  # 计算初始长度
        start = 2 * N * (N + 1)
        for i, j in ti.ndrange(N, N):  # 对角线弹簧1
            idx, idx1, idx2 = (
                start + i * N + j,
                i * (N + 1) + j,
                (i + 1) * (N + 1) + j + 1,
            )
            spring[idx] = ti.Vector([idx1, idx2])  # 连接对角顶点
            rest_len[idx] = (pos[idx1] - pos[idx2]).norm()  # 计算初始长度
        start = 2 * N * (N + 1) + N * N
        for i, j in ti.ndrange(N, N):  # 对角线弹簧2
            idx, idx1, idx2 = (
                start + i * N + j,
                i * (N + 1) + j + 1,
                (i + 1) * (N + 1) + j,
            )
            spring[idx] = ti.Vector([idx1, idx2])  # 连接对角顶点
            rest_len[idx] = (pos[idx1] - pos[idx2]).norm()  # 计算初始长度

    # 初始化顶点质量，并将质量矩阵的对角线赋值为顶点质量
    @ti.kernel
    def init_mass_sp(self, M: ti.types.sparse_matrix_builder()):
        for i in range(self.NV):
            mass = self.mass[i]  # 获取顶点质量
            M[2 * i + 0, 2 * i + 0] += mass  # 对角线赋值
            M[2 * i + 1, 2 * i + 1] += mass  # 对角线赋值

    @ti.func
    def clear_force(self):
        for i in self.force:
            self.force[i] = ti.Vector([0.0, 0.0])  # 清空所有顶点的受力

    # 每轮重新计算受力，不包括阻尼力，无能量损耗
    @ti.kernel
    def compute_force(self):
        self.clear_force()  # 清空受力
        # 对于每个质点，重力F=mg
        for i in self.force:
            self.force[i] += self.gravity * self.mass[i]  # 添加重力

        # 对于每个弹簧中的两个质点，弹簧内力F=-k*x
        for i in self.spring:
            idx1, idx2 = self.spring[i][0], self.spring[i][1]  # 获取弹簧两端顶点索引
            pos1, pos2 = self.pos[idx1], self.pos[idx2]  # 获取两端顶点位置
            dis = pos2 - pos1  # 计算位移
            force = self.ks * (dis.norm() - self.rest_len[i]) * dis.normalized()  # 计算弹簧力
            self.force[idx1] += force  # 添加弹簧力
            self.force[idx2] -= force  # 添加反向弹簧力
        # 固定点约束力（左上与右上两个固定点）
        self.force[self.N] += self.kf * (self.initPos[self.N] - self.pos[self.N])
        self.force[self.NV - 1] += self.kf * (self.initPos[self.NV - 1] - self.pos[self.NV - 1])

    # 三种雅可比矩阵：位置雅可比、速度雅可比和固定点雅可比
    @ti.kernel
    def compute_Jacobians(self):
        # 对于每个弹簧中的两个质点
        for i in self.spring:
            idx1, idx2 = self.spring[i][0], self.spring[i][1]  # 获取弹簧两端顶点索引
            pos1, pos2 = self.pos[idx1], self.pos[idx2]  # 获取两端顶点位置
            dx = pos1 - pos2  # 计算位移
            I = ti.Matrix([[1.0, 0.0], [0.0, 1.0]])  # 单位矩阵
            dxtdx = ti.Matrix([[dx[0] * dx[0], dx[0] * dx[1]], [dx[1] * dx[0], dx[1] * dx[1]]])  # dx的外积
            l = dx.norm()  # 计算长度
            if l != 0.0:
                l = 1.0 / l  # 取倒数
            self.Jx[i] = (I - self.rest_len[i] * l * (I - dxtdx * l**2)) * self.ks  # 位置雅可比矩阵
            self.Jv[i] = self.kd * I  # 速度雅可比矩阵

        # 固定点约束的雅可比矩阵
        self.Jf[0] = ti.Matrix([[-self.kf, 0], [0, -self.kf]])
        self.Jf[1] = ti.Matrix([[-self.kf, 0], [0, -self.kf]])

    # K<-位置雅各比矩阵，固定点雅各比矩阵
    @ti.kernel
    def assemble_K(self, K: ti.types.sparse_matrix_builder()):
        for i in self.spring:
            idx1, idx2 = self.spring[i][0], self.spring[i][1]  # 获取弹簧两端顶点索引
            for m, n in ti.static(ti.ndrange(2, 2)):
                K[2 * idx1 + m, 2 * idx1 + n] -= self.Jx[i][m, n]  # 组装刚度矩阵
                K[2 * idx1 + m, 2 * idx2 + n] += self.Jx[i][m, n]
                K[2 * idx2 + m, 2 * idx1 + n] += self.Jx[i][m, n]
                K[2 * idx2 + m, 2 * idx2 + n] -= self.Jx[i][m, n]
        for m, n in ti.static(ti.ndrange(2, 2)):
            K[2 * self.N + m, 2 * self.N + n] += self.Jf[0][m, n]  # 固定点刚度
            K[2 * (self.NV - 1) + m, 2 * (self.NV - 1) + n] += self.Jf[1][m, n]

    # D<-速度雅各比矩阵
    @ti.kernel
    def assemble_D(self, D: ti.types.sparse_matrix_builder()):
        for i in self.spring:
            idx1, idx2 = self.spring[i][0], self.spring[i][1]  # 获取弹簧两端顶点索引
            for m, n in ti.static(ti.ndrange(2, 2)):
                D[2 * idx1 + m, 2 * idx1 + n] -= self.Jv[i][m, n]  # 组装阻尼矩阵
                D[2 * idx1 + m, 2 * idx2 + n] += self.Jv[i][m, n]
                D[2 * idx2 + m, 2 * idx1 + n] += self.Jv[i][m, n]
                D[2 * idx2 + m, 2 * idx2 + n] -= self.Jv[i][m, n]

    # h：时间步长，dv：速度增量
    @ti.kernel
    def updatePosVel(self, h: ti.f32, dv: ti.types.ndarray()):
        for i in self.pos:
            self.vel[i] += ti.Vector([dv[2 * i], dv[2 * i + 1]])  # 更新速度
            self.pos[i] += h * self.vel[i]  # 更新位置

    @ti.kernel
    def copy_to(self, des: ti.types.ndarray(), source: ti.template()):
        for i in range(self.NV):
            des[2 * i] = source[i][0]  # 拷贝x分量
            des[2 * i + 1] = source[i][1]  # 拷贝y分量

    @ti.kernel
    def compute_b(
        self,
        b: ti.types.ndarray(),
        f: ti.types.ndarray(),
        Kv: ti.types.ndarray(),
        h: ti.f32,
    ):
        for i in range(2 * self.NV):
            b[i] = (f[i] + Kv[i] * h) * h  # 计算右端项

    # 根据论文结论，求解线性方程得到速度增量，进而更新位置和速度
    def update(self, h):
        self.compute_force()  # 计算受力

        ### 根据上一时刻的受力、速度和位置计算当前时刻每个质点的速度与位置
        self.compute_Jacobians()  # 计算雅可比矩阵

        # 组装全局系统
        self.assemble_D(self.DBuilder)  # 组装阻尼矩阵
        D = self.DBuilder.build()
        self.assemble_K(self.KBuilder)  # 组装刚度矩阵
        K = self.KBuilder.build()
        A = self.M - h * D - h**2 * K  # 构造系统矩阵

        self.copy_to(self.vel_1D, self.vel)  # 拷贝速度到一维数组
        self.copy_to(self.force_1D, self.force)  # 拷贝受力到一维数组

        # b = (force + h * K @ vel) * h
        Kv = K @ self.vel_1D  # 计算Kv
        self.compute_b(self.b, self.force_1D, Kv, h)  # 计算右端项b

        # 稀疏求解器，求解Ax=b中的x，即速度增量dv
        solver = ti.linalg.SparseSolver(solver_type="LDLT")
        solver.analyze_pattern(A)  # 分析矩阵模式
        solver.factorize(A)  # 分解矩阵
        # 求解线性系统
        dv = solver.solve(self.b)
        self.updatePosVel(h, dv)  # 更新位置和速度

    def display(self, gui, radius=5, color=0xFFFFFF):
        lines = self.spring.to_numpy()  # 获取弹簧连接
        pos = self.pos.to_numpy()  # 获取顶点位置
        edgeBegin = np.zeros(shape=(lines.shape[0], 2))  # 边的起点
        edgeEnd = np.zeros(shape=(lines.shape[0], 2))  # 边的终点
        for i in range(lines.shape[0]):
            idx1, idx2 = lines[i][0], lines[i][1]  # 获取弹簧两端顶点索引
            edgeBegin[i] = pos[idx1]  # 起点位置
            edgeEnd[i] = pos[idx2]  # 终点位置
        gui.lines(edgeBegin, edgeEnd, radius=2, color=0x0000FF)  # 绘制弹簧
        gui.circles(self.pos.to_numpy(), radius, color)  # 绘制顶点

    @ti.kernel
    def spring2indices(self):
        for i in self.spring:
            self.indices[2 * i + 0] = self.spring[i][0]  # 弹簧起点索引
            self.indices[2 * i + 1] = self.spring[i][1]  # 弹簧终点索引

    def displayGGUI(self, canvas, radius=0.01, color=(1.0, 1.0, 1.0)):
        self.spring2indices()  # 转换弹簧索引
        canvas.lines(self.pos, width=0.005, indices=self.indices, color=(0.0, 0.0, 1.0))  # 绘制弹簧
        canvas.circles(self.pos, radius, color)  # 绘制顶点


def main():
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

    h = 0.01  # 时间步长
    pause = False
    cloth = Cloth(N=10)

    current_t = 0.0
    from datetime import datetime
    real_t = datetime.now()

    import os
    import shutil
    if os.path.exists("results"):
        shutil.rmtree("results")
    os.makedirs("results", exist_ok=True)  # 确保结果目录存在

    use_ggui = args.use_ggui
    if not use_ggui:
        print("Using Taichi GUI for rendering. Press ESC to exit.")
        gui = ti.GUI("Implicit Mass Spring System", res=(1024, 1024),
                     show_gui=False)
        while gui.running:
            cloth.update(h)
            current_t += h

            cloth.display(gui)

            print(f"Current time: {current_t:.3f} seconds")
            # gui.show()
            gui.show(f"results/{current_t:.3f}.png")

            if(current_t >= 1.5): 
                delta_real_t = datetime.now() - real_t
                print(f"Time taken for 1.5s simulation: {delta_real_t.total_seconds()} seconds")
                real_t = datetime.now()
                break
    else:
        print("Using GGUI for rendering. Press ESC to exit.")
        window = ti.ui.Window("Implicit Mass Spring System", res=(1024, 1024),
                            show_window=False)
        while window.running:
            cloth.update(h)
            current_t += h

            canvas = window.get_canvas()
            cloth.displayGGUI(canvas)
            # window.show()
            window.save_image(f"results/{current_t:.3f}.png")

            if(current_t >= 1.5): 
                delta_real_t = datetime.now() - real_t
                print(f"Time taken for 1.5s simulation: {delta_real_t.total_seconds()} seconds")
                real_t = datetime.now()
                break

if __name__ == "__main__":
    main()