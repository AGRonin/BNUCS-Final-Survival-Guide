# 程序操纵chrome打开书摘-新浪读书网站网页，截图并保存网页内容，过10秒关闭
from selenium import webdriver
import time

driver = webdriver.Chrome()
driver.get('http://book.sina.com.cn/excerpt/')

time.sleep(5)

driver.save_screenshot("sreenshot1.png")  # 截屏  自行设置路径

print(driver.page_source)

with open("sinaBook.html", 'w', encoding='utf-8') as f:  # 保存html源码，自行设置路径
    f.write(driver.page_source)  # page_source保存着网页源码

driver.quit()