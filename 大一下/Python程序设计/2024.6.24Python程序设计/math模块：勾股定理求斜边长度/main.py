import math
a = float(input('请输入直角边长：'))
b = float(input('请输入另一条直角边长：'))
c = math.hypot(a, b)
print(f'对应的斜边长为{c}')