"""
利用wordcloud和jieba生成《三国演义》的词云：
1. 主要人物的词云；
2. 文中形容词的词云。
"""
import wordcloud
import jieba.posseg
import numpy
from PIL import Image
import re

#打开文件进行文件操作
with open('/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/三国演义.txt',encoding='utf-8') as f:
    threeKindomsText=f.read()
threeKindomsEveryLine=threeKindomsText.splitlines()

#接下来我们要统计主要人物的出场次数
#让我们导入主要人物名单
with open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/主要人员名单.txt",encoding='utf-8') as f:
    mainPersonText=f.read()
mainPersonEveryLine=mainPersonText.splitlines()
mainPersonNameAndStyleDictionary=dict()
for line in mainPersonEveryLine:
    location=line.index('：')
    newline=line[location+1:]
    for name in newline.split('、'):
        mainPersonNameAndStyleDictionary[name]=0

#下面我们要导入新的文件
with open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》全文统计/人名与字.txt",encoding='utf-8') as f:
    styleAndNameText=f.read()
styleAndNameList=re.split("：字|，|。",styleAndNameText)

for name in mainPersonNameAndStyleDictionary:
    if name in styleAndNameList:
        style=styleAndNameList[styleAndNameList.index(name)+1]
    for paragraph in threeKindomsEveryLine:
        mainPersonNameAndStyleDictionary[name]+=paragraph.count(name)
        mainPersonNameAndStyleDictionary[name] += paragraph.count(style)

#建立词云
zhugeliangImage=numpy.array(Image.open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》词云统计/诸葛亮图片.jpg"))
wc1=wordcloud.WordCloud(width=1000,height=1000,mask=zhugeliangImage,contour_width=3,contour_color='black',font_path="/System/Library/Fonts/PingFang.ttc",background_color='white')
wc1.fit_words(mainPersonNameAndStyleDictionary)
wc1.to_file("《三国演义》主要人物词云.png")

#接下来使用jieba对中文进行分词，找出形容词，并统计次数
allTheWordsWithPartOfSpeech=jieba.posseg.cut(threeKindomsText)
adjectiveWordsDictionary=dict()
for word,adj in allTheWordsWithPartOfSpeech:
    if adj=='a' and word not in adjectiveWordsDictionary:
        adjectiveWordsDictionary[word]=1
    elif adj=='a' and word in adjectiveWordsDictionary:
        adjectiveWordsDictionary[word]+=1

#建立词云
loveImage=numpy.array(Image.open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》词云统计/爱心图片.png"))
wc2=wordcloud.WordCloud(width=1000,height=1000,mask=loveImage,font_path="/System/Library/Fonts/PingFang.ttc",background_color='white')
wc2.fit_words(adjectiveWordsDictionary)
wc2.to_file("《三国演义》主要形容词词云.png")