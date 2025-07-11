'''五科分数和统计并排序，n大！'''
n=int(input())
x=[]
for i in range(0,n):
    a=input().split()
    num=int(a[0]) + int(a[1]) + int(a[2]) + int(a[3]) + int(a[4])
    x.append(num)
printnum=0
for i in range(500,-1,-1):
    num=x.count(i)
    for j in range(0,num):
        printnum+=1
        print(i,end='')
        if printnum!=len(x):
            print(end=' ')
