l1 = [i**2 for i in range(5)]
print(l1)

l2 = [i**2 for i in range(5) if i%2==1]
print(l2)

l3 = [(i+j, i*j) for i in [10, 11] for j in [1,2,3]]
print(l3)

#解析式生成字典
d = {i[0]: i[1] for i in zip([1,2,3], ['a','b','c'])}
print(d)

#解析式生成集合
a = [1,2,5,2,8,1,4]
s = {i for i in a}
print(s)
print(set(a))

s2 = {i for i in a if i%2==0}
print(s2)