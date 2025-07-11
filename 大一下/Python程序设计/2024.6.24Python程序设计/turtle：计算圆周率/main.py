# 利用turtle库对上述过程进行可视化
from random import random
from turtle import *

dots = 100 * 100
ins = 0
speed(0)  # 最快龟速
tracer(1000)  # 每1000个动作更新一下屏幕
pensize(2)
for i in range(dots):
    x, y = random(), random()
    dis = pow(x ** 2 + y ** 2, 0.5)
    if dis <= 1:
        ins += 1
        pencolor('red')  # 圆里的颜色为红色
    else:
        pencolor('blue')  # 圆外的颜色为蓝色

    penup()
    goto(400 * x, 400 * y)
    pendown()
    dot()  # 画一个点

pi = 4 * ins / dots
penup()
goto(150, -50)
pendown()
pencolor('black')
write("圆周率pi={}".format(pi), align="left", \
      font=("Arial", 20, "bold"))
done()