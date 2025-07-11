from PIL import Image

img = Image.open('PieChart.jpg')
img_resized = img.resize((500, 400))

# 保存调整大小后的词云图像
img_resized.save('PieChart_500*400.jpg')