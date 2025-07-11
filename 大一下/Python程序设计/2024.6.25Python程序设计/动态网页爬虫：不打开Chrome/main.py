# 程序不弹出chrome浏览器，让它在后台操作
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import time

chrome_options = Options()
chrome_options.add_argument("--headless")  # define headless

driver = webdriver.Chrome(options=chrome_options)

driver.get('https://news.bnu.edu.cn/zx/bsrw/index.htm')  # 师大人物

time.sleep(5)

driver.save_screenshot("sreenshot2.png")  # 截屏  自行设置路径

with open("师大人物.html", 'w', encoding='utf-8') as f:  # 保存html源码，自行设置路径
    f.write(driver.page_source)  # page_source保存着网页源码

driver.quit()