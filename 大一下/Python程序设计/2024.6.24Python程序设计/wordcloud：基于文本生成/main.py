from wordcloud import *
import matplotlib.pyplot as plt
import numpy
from PIL import Image
# Generate a word cloud image
loveImage=numpy.array(Image.open("/Users/yangbowen/Desktop/本科/大一/大一下课程/Python程序设计/2024.6.24Python程序设计/《三国演义》词云统计/爱心图片.png"))
wc = WordCloud(background_color="pink",
               max_words=2000,font_path="/System/Library/Fonts/PingFang.ttc",repeat=True,mask=loveImage)
wc.generate("张瑾然:杨博文")
# show
plt.imshow(wc, interpolation='bilinear')
plt.axis("off")
plt.show()