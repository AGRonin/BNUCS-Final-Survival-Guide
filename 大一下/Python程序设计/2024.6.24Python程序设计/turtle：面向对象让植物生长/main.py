'''绘图示例4：面向对象示例，模拟三棵植物生长'''
from turtle import *
one=Turtle(shape='triangle',visible=False)
two=Turtle(shape='square',visible=False)
three=Turtle(shape='circle',visible=False)

one.pensize(3)
two.pensize(6)
three.pensize(9)

one.color('red')
two.color('green')
three.color('orange')

one.penup()
two.penup()
three.penup()

one.goto(-100,-300)
two.goto(0,-300)
three.goto(100,-300)

one.left(90)
two.left(90)
three.left(90)

one.showturtle()
two.showturtle()
three.showturtle()

one.pendown()
two.pendown()
three.pendown()

import random
for i in range(50):
    f=random.randint(0,10)
    s=random.randint(6,15)
    t=random.randint(10,20)

    fa=random.randint(-3,3)
    sa=random.randint(-5,5)
    ta=random.randint(-7,7)

    one.forward(f)
    two.forward(s)
    three.forward(t)

    one.left(fa)
    two.left(sa)
    three.left(ta)
done()