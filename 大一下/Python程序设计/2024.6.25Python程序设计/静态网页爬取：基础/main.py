import requests
from requests.compat import urljoin
import bs4
header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36'}
html = requests.get("http://www.bnu.edu.cn",headers=header)
html.encoding='utf-8'
bsObj=bs4.BeautifulSoup(html.content,'lxml')
print(bsObj.a.attrs)
clink=bsObj.find('img')
print(clink)
print(clink['src'])
url='https://www.bnu.edu.cn/'
blink=bsObj.find('a',string='学部院系')  #限定了文字属性
blink = urljoin(url, blink['href'])
print(blink)
#获得图像
logo= requests.get(urljoin(url, clink['src']), headers=header)
with open(r'BNU-logo.png', 'wb') as f:
    f.write(logo.content)
with open('bnuai.html','wb') as f:
    f.write(html.content)