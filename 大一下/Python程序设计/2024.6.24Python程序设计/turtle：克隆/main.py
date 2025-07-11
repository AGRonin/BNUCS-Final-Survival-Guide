'''绘图示例5：克隆'''
from turtle import *
p = Turtle()
p.pensize(2)
p.speed(1)
p.shape('turtle')
p.left(120)
p.fd(120)

q = p.clone()
q.fillcolor('green')
q.begin_fill()
q.left(70)
q.forward(20)
q.circle(-170,16)
q.circle(-170,-12)

q.left(60)
q.circle(-40,125)
q.right(50)
q.circle(-40,130)
q.end_fill()

for i in range(20):
    p.rt(2)
    p.circle(200,1)

q=p.clone()
q.fillcolor('green')
q.begin_fill()
q.right(70)
q.forward(20)
q.circle(-170,16)
q.circle(-170,-12)

q.left(60)
q.circle(-40,125)
q.right(50)
q.circle(-40,130)
q.end_fill()

for i in range(20):
    p.rt(2)
    p.circle(200,1)
done()