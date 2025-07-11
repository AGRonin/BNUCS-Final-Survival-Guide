s=input()
char=0
dig=0
space=0
others=0
for i in s:
    if i.isalpha():
        char+=1
    elif i.isdigit():
        dig+=1
    elif i.isspace():
        space+=1
    else:
        others+=1
print("all={},char={},dig={},space={},others={}".format((char+dig+space+others),char,dig,space,others))
