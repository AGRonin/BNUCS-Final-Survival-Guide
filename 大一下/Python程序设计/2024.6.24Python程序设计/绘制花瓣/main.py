import turtle  # 导入绘图模块

n = int(input("请输入花瓣的数量："))  # input接收键盘输入，返回字符串
colors = input("请输入花瓣的颜色，各颜色间逗号隔开：").split(",")

print(n, colors)

colorsNum = len(colors)  # 颜色的数量

turtle.pensize(5)

for i in range(int(n)):
    if i == n - 1 and n % colorsNum == 1:  # 如果花瓣数量是颜色数量的整数倍+1，并且当前画最后一片花瓣
        turtle.pencolor(colors[1])
    else:
        turtle.pencolor(colors[i % colorsNum])
    turtle.circle(100)  # 画圆形花瓣
    turtle.left(360 / n)  # 向左转一个角度

turtle.done()
exit(1)