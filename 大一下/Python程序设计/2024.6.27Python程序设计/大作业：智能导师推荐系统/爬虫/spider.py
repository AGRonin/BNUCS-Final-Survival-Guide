import requests
from bs4 import BeautifulSoup
from requests.compat import urljoin
import os
import re
from PIL import Image
url_list=['https://ai.bnu.edu.cn/xygk/szdw/zgj/index.htm','https://ai.bnu.edu.cn/xygk/szdw/fgj/index.htm','https://ai.bnu.edu.cn/xygk/szdw/zj/index.htm']
header = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0'}
link_list = []
total_list=[]
pic_list=[]
subtitle_list=['start']#文本文件的开头结尾标记
for url in url_list:
    html = requests.get(url, headers=header)
    bsObj = BeautifulSoup(html.content, 'lxml')
    section = bsObj.find('ul', class_="list_con01")
    links=section.find_all('a', href=True)
    for li in links:
        link_list.append(urljoin(url,li['href']))
for url in link_list:
    html = requests.get(url, headers=header)
    bsObj = BeautifulSoup(html.content, 'lxml')
    name=bsObj.find('div',class_='subPageTit')
    name=name.get_text().strip()
    top=bsObj.find('div',class_='top-bar').get_text().strip()
    topname = "./" + top
    if not os.path.exists(topname):
        os.mkdir(topname)
    dirname = topname+"/" + name
    if not os.path.exists(dirname):
        os.mkdir(dirname)
    content=bsObj.find('div',class_='tj-intro')
    picture=content.find('img')
    if picture:
        pic_url=picture.get('src')
        img_url = urljoin(url, pic_url)
        response = requests.get(img_url)
        response.raise_for_status()  # 确保请求成功
        img_name = "pic"
        img_path = os.path.join(dirname, img_name)
        if not os.path.exists(img_path):
            # 获取图片扩展名
            #ext = os.path.splitext(img_url)[1]  # 获取URL中的扩展名
            # 如果没有扩展名，使用默认扩展名
            ext = '.png'  # 默认扩展名
            img_name = f"pic{ext}"  # 添加扩展名
            img_path = os.path.join(dirname, img_name)
            # 确保路径存在并保存图片
            with open(img_path, 'wb') as file:
                file.write(response.content)
            #统一图片大小
            img=Image.open(img_path)
            new_img=img.resize((180,240))
            new_img.save(img_path)
    else:
        figure=open('./默认头像.png','rb')
        img_name = f"pic.png"  # 添加扩展名
        img_path = os.path.join(dirname, img_name)
        # 确保路径存在并保存图片
        with open(img_path, 'wb') as file:
            file.write(figure.read())
        # 统一图片大小
        img = Image.open(img_path)
        new_img = img.resize((180, 240))
        new_img.save(img_path)

    subtitles=content.find_all('h4')
    for subtitle in subtitles:
        if subtitle not in subtitle_list:
            subtitle_list.append(subtitle.get_text())
    text=content.get_text()
    if text:
        file_path = dirname + "/文本信息.txt"
        if not os.path.exists(file_path):
            # 文件不存在时才写入内容
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write('start\n'+text)#插入一个开始标记符
        with open(file_path,'r',encoding='utf-8')as f:
            content_txt=f.read()
        index_Dict={}
        n=0
        for subtitle in subtitle_list:
            if content_txt.find(subtitle)!=-1:
                if subtitle not in index_Dict:
                    index_Dict[subtitle]=content_txt.find(subtitle)
                    index_Dict=sorted(index_Dict.items(),key=lambda x:x[1])
                    index_Dict=dict(index_Dict)#记录每个subtitle出现的位置，其位置逐渐靠后
        for subtitle in subtitle_list:
            if content_txt.find(subtitle) != -1:
                keys=list(index_Dict)
                current_index=keys.index(subtitle)
                if current_index + 1 < len(keys):
                    next_key=keys[current_index+1]#找到下一个标题
                    body = content_txt[index_Dict[subtitle]:index_Dict[next_key]].strip()
                else:
                    body = content_txt[index_Dict[subtitle]:].strip()
                if content_txt.find(subtitle)!=-1:#若找不到title则为-1
                    # 替换文件名中的无效字符
                    safe_title = subtitle.replace("/", "_").replace("\\", "_").replace(":", "_").replace("*", "_").replace("?",
                                                                                                                        "_").replace(
                        '"', "_").replace("<", "_").replace(">", "_").replace("|", "_")
                    file_name = dirname +f"/{safe_title}.txt"
                    # 写入文件
                    with open(file_name, 'w', encoding='utf-8') as file:
                        file.write(body)
