for i in range(9,0,-1):
    for j in range(9,i,-1):
        print("      ",end=' ')
    for j in range(i,0,-1):
        print(f"{j}*{i}={i*j:>2}",end=' ')
    print()