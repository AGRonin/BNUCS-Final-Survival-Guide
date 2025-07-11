from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup
import time
"""
从前程无忧https://we.51job.com/pc/search?keyword=&searchType=2&sortType=0&metro= 网页出发，
利用selenium输入要搜索的职业，如python，选择两个城市（如北京+上海）作为工作地点、学历要求为本科+硕士+博士，
之后进行招聘信息的爬取，每条信息包含以下字段：职位名称、薪酬、工作经验、最低学历、公司福利、公司名称、
公司领域、公司类型、公司规模、职位信息，并保存为csv文件。

要求：工作地点、学历要求等均采用编程实现，不能手动实现；只爬取60条招聘信息（3页）即可；
"""

chrome_options=Options()
driver=webdriver.Chrome(options=chrome_options)
driver.implicitly_wait(5)
driver.get('https://we.51job.com/pc/search?keyword=&searchType=2&sortType=0&metro=')
windows=driver.window_handles

#找到搜索全文/职业名
searchPoint=driver.find_element(By.ID,"keywordInput")

#鼠标移动到搜索并点击
ActionChains(driver).move_to_element(searchPoint).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#输入“python”
searchPoint.send_keys("python")
time.sleep(0.5)
searchPoint.send_keys(Keys.ENTER)
time.sleep(0.5)

#鼠标移动到展开选项并点击
button = driver.find_element(By.XPATH, '//i[@data-v-da2512da and @class="e_icons"]')
ActionChains(driver).move_to_element(button).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#鼠标移动到全部城市并点击
allCity = driver.find_element(By.CLASS_NAME,"allcity")
ActionChains(driver).move_to_element(allCity).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#鼠标选择北京、上海
locateBeiJing = driver.find_element(By.XPATH, "//span[@title='北京']")
ActionChains(driver).move_to_element(locateBeiJing).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)
locateShangHai = driver.find_element(By.XPATH, "//span[@title='上海']")
ActionChains(driver).move_to_element(locateShangHai).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#鼠标选择确定
ok = driver.find_element(By.XPATH, '//button[@class="el-button el-button--primary"]/span[text()="确 定"]')
ActionChains(driver).move_to_element(ok).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#鼠标选择多选
multiChoice = driver.find_element(By.XPATH, '(//div[contains(@class, "mt mt_sal") and contains(., "多选")])[3]')
ActionChains(driver).move_to_element(multiChoice).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

#鼠标选择本科、硕士、博士，并点击确定
undergraduate = driver.find_element(By.XPATH,'//span[text()="本科"]')
ActionChains(driver).move_to_element(undergraduate).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)
master = driver.find_element(By.XPATH,'//span[text()="硕士"]')
ActionChains(driver).move_to_element(master).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)
PhD = driver.find_element(By.XPATH,'//span[text()="博士"]')
ActionChains(driver).move_to_element(PhD).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)
ok = driver.find_element(By.XPATH,'//span[@event-type="6" and @class="p_but and "text()="确定"]')
ActionChains(driver).move_to_element(ok).perform()
ActionChains(driver).click().perform()
time.sleep(0.5)

time.sleep(5)