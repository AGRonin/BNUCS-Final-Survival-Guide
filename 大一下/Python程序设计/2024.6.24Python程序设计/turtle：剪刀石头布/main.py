import turtle
import random
print("石头剪刀布游戏开始，我要出拳了，请你按数字键1/2/3并回车：石头（1）、剪刀（2）、布（3）；如果不想玩了，可按'q'或'Q'键并回车退出游戏。",end='\n\n')
winNum,loseNum,drawNum=0,0,0
choice=["石头","剪刀","布"]
while True:
    playerChoice=input("你出拳：")
    if playerChoice in ('q','Q'):
        print("再见，下次玩！")
        break
    if playerChoice not in ('1','2','3'):
        print("请注意出拳规范，石头（1）、剪刀（2）、布（3），请重新输入。",end='')
        continue
    playerChoice=int(playerChoice)
    computerChoice=random.randint(1,3)
    print(f"玩家{choice[playerChoice-1]}，电脑{choice[computerChoice-1]}，")
    if playerChoice-computerChoice in (-1,2):
        print("玩家赢",end='\n\n')
        winNum=winNum+1
    elif playerChoice==computerChoice:
        print("平局",end='\n\n')
        drawNum=drawNum+1
    else:
        print("电脑赢",end='\n\n')
        loseNum=loseNum+1
sumNum=winNum+loseNum+drawNum
turtle.setup(1000,1000,0,0)
turtle.hideturtle()
turtle.speed(0)
turtle.color('red','yellow')
turtle.begin_fill()
turtle.circle(200)
turtle.end_fill()
turtle.pu()
turtle.goto(85,210)
turtle.pd()
turtle.color('black','black')
turtle.begin_fill()
turtle.circle(35)
turtle.end_fill()
turtle.pu()
turtle.goto(-85,210)
turtle.pd()
turtle.color('black','black')
turtle.begin_fill()
turtle.circle(35)
turtle.end_fill()
turtle.pu()
turtle.color('red')
turtle.pensize(3)
if winNum>loseNum:
    turtle.goto(84.86,140)
    turtle.pd()
    turtle.setheading(45)
    turtle.circle(120,-90)
elif winNum<loseNum:
    turtle.goto(-84.86,100)
    turtle.pd()
    turtle.setheading(45)
    turtle.circle(-120,90)
else:
    turtle.goto(-85,120)
    turtle.pd()
    turtle.goto(85,120)
turtle.pu()
turtle.goto(0,-80)
turtle.pd()
turtle.pencolor('black')
turtle.write(f"你一共玩了{sumNum}次，其中赢了{winNum}次，输了{loseNum}次，平局{drawNum}次。",align="center",font=("Baoli TC Regular",30,"bold"))#这里的字体是macOS中的字体“报隶”
turtle.done()