a=int(input("你想对谁求？"))
n=int(input("你想加几位？"))
s=0
if 0>=a or a>=10:
    print("你想加的有问题")
    exit(1)
for i in range(1,n+1):
    s+=(10**i-1)/9*a
print(f"结果是{s:.0f}")