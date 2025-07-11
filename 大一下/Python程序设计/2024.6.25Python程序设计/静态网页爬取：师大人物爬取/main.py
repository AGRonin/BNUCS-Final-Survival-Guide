"""
在上述师大人物爬取的基础上，进一步爬取每位师大人物的报道，
把每一条报道中的文字保存为一个以报道标题命名的txt文件，同时把报道中的图片保存到本地。
注意：只需爬取前两页的报道，而且只爬两种网页格式的报道，
其中一种url以https://news.bnu.edu.cn/zx/bsrw/ 开头，
另一种url以https://mp.weixin.qq.com/s/ 开头。
"""

import requests
from bs4 import BeautifulSoup
from requests.compat import urljoin
import os
import re
#伪装成浏览器
header={'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/17.5 Safari/605.1.15'}
url='https://news.bnu.edu.cn/zx/bsrw/index.htm'
urlWeiXinList=[]
urlBNUNewsList=[]

#进行两次，读前两页，获取所有的链接
for i in range(1,3):
    #利用requests进行访问
    html=requests.get(url,headers=header)
    html.encoding='utf-8'

    #给bs进行解析
    bsObj=BeautifulSoup(html.content,'lxml')

    #观察网站，发现我们需要的URL在某位置
    lis=bsObj.find_all('div',class_="item-txt01")
    url1='https://news.bnu.edu.cn/zx/bsrw/'
    for li in lis:
        link=li.find('a')
        if "https://mp.weixin.qq.com/s/" in link['href']:
            urlWeiXinList.append(link['href'])
        elif "http://" in link['href'] or "https://" in link['href'] or "www." in link['href']:
            continue
        else:
            linkNew=urljoin(url1,link['href'])
            urlBNUNewsList.append(linkNew)
    #下一页
    nextlink=bsObj.find('a',class_="next")
    if nextlink!=None:
        url=urljoin(url1,nextlink['href'])
    else:
        url=None
        break

for linkArticle in urlBNUNewsList:
    html = requests.get(linkArticle, headers=header)
    html.encoding = 'utf-8'
    # 给bs进行解析
    bsObj = BeautifulSoup(html.content, 'lxml')
    articleTitle=bsObj.find('div',class_="articleTitle")
    #创建文件夹
    if articleTitle==None:
        print(linkArticle)
        break
    title=articleTitle.text.strip()
    if not os.path.exists(f"{title}"):
        os.mkdir(f"{title}")
    #写入文件
    with open(f"{title}/{title}.txt",'wt',encoding='utf-8') as f:
        f.write(title)
        f.write('\n')
        articleAuthor=bsObj.find('div', class_="articleAuthor").text.strip()
        articleAuthorList=articleAuthor.splitlines()
        for line in articleAuthorList:
            if line!="|" and line!="次":
                f.write(line)
                f.write("  ")
        f.write('\n')
        for paragraph in bsObj.find_all('p'):
            f.write(paragraph.text.strip())
            f.write('\n')
    #写入图片
    pictureAmount=0
    for paragraph in bsObj.find_all('p'):
        for img in paragraph.find_all('img'):
            imgSrc=img['src']
            url2=urljoin(url1,imgSrc)
            #获取图片
            htmlImage=requests.get(url2,headers=header)
            pictureAmount+=1
            if pictureAmount<10:
                pictureAmountStr='0'+str(pictureAmount)
            else:
                pictureAmountStr=str(pictureAmount)
            with open(f"{title}/IMG{pictureAmountStr}.{title}"+imgSrc[imgSrc.rfind('.'):],'wb') as f:
                f.write(htmlImage.content)

for linkArticle in urlWeiXinList:
    html = requests.get(linkArticle, headers=header)
    html.encoding = 'utf-8'
    # 给bs进行解析
    bsObj = BeautifulSoup(html.content, 'lxml')
    articleTitle=bsObj.find('h1',class_="rich_media_title")
    #创建文件夹
    if articleTitle==None:
        break
    title=articleTitle.text.strip()
    if not os.path.exists(f"{title}"):
        os.mkdir(f"{title}")
    #写入文件
    with open(f"{title}/{title}.txt",'wt',encoding='utf-8') as f:
        f.write(title)
        f.write('\n')
        articleAuthor=bsObj.find('div', class_="rich_media_meta_list").text.strip()
        articleAuthorList=articleAuthor.splitlines()
        for line in articleAuthorList:
            if line!="|" and line!="丨" and line!="次":
                f.write(line)
                f.write("  ")
        f.write('\n')
        for paragraph in bsObj.find_all('p'):
            f.write(paragraph.text.strip())
            f.write('\n')
    #写入图片
    pictureAmount=0
    content=bsObj.find_all('img',class_="rich_pages wxw-img")
    for img in content:
        imgSrc=img['data-src']
        #获取图片
        htmlImage=requests.get(imgSrc,headers=header)
        pictureAmount+=1
        if pictureAmount<10:
            pictureAmountStr='0'+str(pictureAmount)
        else:
            pictureAmountStr=str(pictureAmount)
        Format=imgSrc[imgSrc.rfind('=')+1:]
        if Format not in ["bmp","jpg","png","tif","gif","pcx","tga","exif","fpx","svg","psd","cdr","pcd","dxf","ufo","eps","ai","raw","WMF","webp","avif","apng","jpeg"]:
            Format="jpg"
        with open(f"{title}/IMG{pictureAmountStr}.{title}.{Format}",'wb') as f:
            f.write(htmlImage.content)