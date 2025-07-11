from pyecharts.charts import Line
import math
x=[-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10]
y1=[]
y2=[]
y3=[]
for i in x:
    t=i**2
    z=5*math.sin(i)
    y2.append(z)
    y1.append(t)
    t=5*math.cos(i)
    y3.append(t)
line=Line("二次函数图象")
line.add("数据点1",x,y1,mark_point=['max'])
line.add("数据点2",x,y2)
line.add("数据点3",x,y3)
line.render("二次函数图象.html")