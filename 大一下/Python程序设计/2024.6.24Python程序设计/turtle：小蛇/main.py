'''绘图示例3：python小蛇'''
from turtle import *
clear()
setup(800, 1000, 0, 0)
penup()
goto(-250,-200)
pendown()
pensize(25)
pencolor('green')
seth(-40)
for i in range(3):
    circle(40, 80)
    circle(-40, 80)
circle(40, 80/2)
fd(40)
circle(16, 180)
fd(40 * 2/3)
done()