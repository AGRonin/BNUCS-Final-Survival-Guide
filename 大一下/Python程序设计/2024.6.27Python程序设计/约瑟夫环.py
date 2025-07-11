'''约瑟夫环问题'''
n,m=input().split()
n=int(n)
m=int(m)
x=[]
for i in range(1,n+1):
    x.append(i)
death=0
index=-1
while len(x)>0:
    index+=m
    index=index%len(x)
    print(x[index],end='')
    del x[index]
    index=index-1
    death=0
    if len(x)!=0:
        print(end=' ')
