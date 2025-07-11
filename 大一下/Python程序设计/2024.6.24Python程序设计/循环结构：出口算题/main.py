import random

for i in range(1, 101):  # C语言：for (int i=1; i<101; i++)
    satisfied = False
    while not satisfied:
        a = random.randint(0, 99)
        b = random.randint(0, 99)
        c = random.choice(['+', '-'])
        satisfied = (((c == '+') and (a + b < 100) and (a % 10 + b % 10 > 10)) or ((c == '-') and (a - b > 0) and (a % 10 < b % 10)))
    print(f'{a:2}{c}{b:2}=', end='\t\t' if i % 4 != 0 else '\n')