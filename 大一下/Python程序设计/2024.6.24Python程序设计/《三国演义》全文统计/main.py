"""
1. 统计 《三国演义.txt》 中有多少个不同的文字，把字数打印出来；
2. 统计每一回（章节）的段落数量，并求出段落数最少、最多分别在第几回，以及平均段落数，打印所有结果；
3. 统计主要人物在全文中的出场次数，得到出场次数最多的10人，打印这些人名以及对应的出场次数。

对于任务3，分两步，第一步先只使用 《主要人员名单.txt》中的人名进行统计；
第二步，考虑古代人经常不称呼姓名而是称呼字，所以进一步把人（《人名与字.txt》）的字考虑进来
在统计时，无论是出现了人名还是出现了字，都算一次出场。
"""

#打开文件进行文件操作
with open('/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/三国演义.txt',encoding='utf-8') as f:
    threeKindomsText=f.read()
threeKindomsEveryLine=threeKindomsText.splitlines()

#已经读取并将其按照每一段进行分割。接下来统计文字
#建立文字列表
allCharacter=[]
for character in threeKindomsText:
    if character.isalpha() and character not in allCharacter:
        allCharacter.append(character)

#allCharacter中已经有了所有的字，接下来对第一项任务进行输出
print("《三国演义》中共有{}个不同的文字。下面是全部这些文字：".format(len(allCharacter)))
count=1
for i in allCharacter:
    print('{:<3}'.format(i),end='')
    if count%20==0:
        print()
    count=count+1
print()

#开始统计每章内段落数
paragraphNumberInEachChapter=[]
nowChapter=0
for line in threeKindomsEveryLine:
    if line=='********************':
        nowChapter=nowChapter+1
        paragraphNumberInEachChapter.append(-1)#这里是-1因为每回第一节是“第一回 ……”
        continue
    if nowChapter==0:
        continue
    paragraphNumberInEachChapter[nowChapter-1]=paragraphNumberInEachChapter[nowChapter-1]+1
print("\n接下来我将告诉你《三国演义》每一回都有多少段落：")
for i in range(1,nowChapter+1):
    print("第{:>3}回\t\t有{:>2}个段落".format(i,paragraphNumberInEachChapter[i-1]))
print("这是全部的回目。你来猜猜最少、最多的是哪回呢？平均一回又有多少段呢？")
print("最少的一回中有{}段，这样的回目有：".format(min(paragraphNumberInEachChapter)),end='')
for i in range(1,nowChapter+1):
    if paragraphNumberInEachChapter[i-1]==min(paragraphNumberInEachChapter):
        print(f"第{i}回",end=' ')
print()
print("最多的一回中有{}段，这样的回目有：".format(max(paragraphNumberInEachChapter)),end='')
for i in range(1,nowChapter+1):
    if paragraphNumberInEachChapter[i-1]==max(paragraphNumberInEachChapter):
        print(f"第{i}回",end=' ')
print()
print(f"平均一回有{sum(paragraphNumberInEachChapter)/len(paragraphNumberInEachChapter):.2f}段")

#接下来我们要统计主要人物的出场次数
#首先让我们导入主要人物名单
with open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/主要人员名单.txt",encoding='utf-8') as f:
    mainPersonText=f.read()
mainPersonEveryLine=mainPersonText.splitlines()
mainPersonNameDictionary=dict()
for line in mainPersonEveryLine:
    location=line.index('：')
    newline=line[location+1:]
    for name in newline.split('、'):
        mainPersonNameDictionary[name]=0

#创建完所有人的名单，接下来我们统计每个人出现的次数
for name in mainPersonNameDictionary:
    for paragraph in threeKindomsEveryLine:
        mainPersonNameDictionary[name]+=paragraph.count(name)

#对列表进行排序
timesOccuredList=list(mainPersonNameDictionary.values())
timesOccuredList.sort(reverse=True)
print("接下来我会告诉你罗贯中提到的最多的十个人：")
for i in timesOccuredList[0:10]:
    for people in mainPersonNameDictionary:
        if mainPersonNameDictionary[people]==i:
            if len(people)==2:
                print(f"{people[0]}  {people[1]}   出现了{i}次")
            else:
                print(f"{people}   出现了{i}次")
print("\n这时候就会有聪明的小朋友说了，古代人经常不称呼姓名而称呼字啊！你有没有把字也给统计进来呢？那让我们算上字再统计一遍吧！")

#下面我们要导入新的文件
with open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/人名与字.txt",encoding='utf-8') as f:
    styleAndNameText=f.read()
import re
styleAndNameList=re.split("：字|，|。",styleAndNameText)

mainPersonNameAndStyleDictionary = mainPersonNameDictionary.copy()
for name in mainPersonNameAndStyleDictionary:
    mainPersonNameAndStyleDictionary[name]=0
    if name in styleAndNameList:
        style=styleAndNameList[styleAndNameList.index(name)+1]
    for paragraph in threeKindomsEveryLine:
        mainPersonNameAndStyleDictionary[name]+=paragraph.count(name)
        mainPersonNameAndStyleDictionary[name] += paragraph.count(style)
#对列表进行排序
timesOccuredList=list(mainPersonNameAndStyleDictionary.values())
timesOccuredList.sort(reverse=True)
print("经过再次统计后，罗贯中提到的最多的十个人：")
for i in timesOccuredList[0:10]:
    for people in mainPersonNameAndStyleDictionary:
        if mainPersonNameAndStyleDictionary[people]==i:
            if len(people)==2:
                print(f"{people[0]}  {people[1]}   出现了{i}次")
            else:
                print(f"{people}   出现了{i}次")