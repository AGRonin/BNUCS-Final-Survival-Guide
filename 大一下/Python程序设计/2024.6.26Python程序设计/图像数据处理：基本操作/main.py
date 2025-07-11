from PIL import Image,ImageFont,ImageDraw,ImageFilter,ImageEnhance

def get_gif(imgs, filename):
    '''根据imgs中的所有图像生成gif动图，保存为名为filename的文件'''
    imgs[0].save(filename,
             save_all=True, #真会保存所有图片，否则只保存一张
             append_images=imgs, #imgs为存放对象们的列表
             duration=200,#GIF动图的间隔时间,单位为毫秒
             loop=0) #循环次数 0表示无限循环
    for i in imgs:
        i.close()
        
img=Image.open('../../课件/Day3/Images/BNU/9.jpg')
#print(img.mode,img.size)
#img.show()
big_pic=Image.new('RGB',(1200,1000),'white')
#big_pic.show()
img_scale=img.resize((400,500))
#img_scale.show()
img_rotate=img_scale.rotate(45)
#img_rotate.show()
img_gray=img_scale.convert('L')
#img_gray.show()
big_pic.paste(img_scale,(600,500))
#big_pic.show()

draw=ImageDraw.Draw(big_pic)
font=ImageFont.truetype("/System/Library/Fonts/PingFang.ttc",50)
draw.text((550,0),"标题",font=font,fill='red')
draw.rectangle([600,500,750,650],fill=(0,0,125),width=3)
draw.ellipse([(600,100),(800,180)],outline=(255,0,255),width=5)
#big_pic.show()

r,g,b=img_scale.split()
newr=r.point(lambda x:x*1.3)
img_red=Image.merge(img_scale.mode,(newr,g,b))
#img_red.show()

img_old=img_scale.copy()
for i in range(img_scale.width):
    for j in range(img_scale.height):
        r,g,b=img_scale.getpixel((i,j))
        R = int(0.394 * r + 0.768 * g + 0.188 * b)
        G = int(0.347 * r + 0.685 * g + 0.167 * b)
        B = int(0.273 * r + 0.536 * g + 0.132 * b)
        img_old.putpixel((i, j), (R, G, B))
#img_old.show()

img_contour=img_scale.filter(ImageFilter.CONTOUR)
#img_contour.show()
img_edge=img_scale.filter(ImageFilter.EDGE_ENHANCE)
#img_edge.show()
img_emboss=img_scale.filter(ImageFilter.EMBOSS)
#img_emboss.show()
img_medianblur=img_scale.filter(ImageFilter.MedianFilter(size=5))
#img_medianblur.show()

img_bright_enh=ImageEnhance.Brightness(img_scale)
#img_bright_enh.enhance(1.5).show("50% more brightness")
img_contrast_enh=ImageEnhance.Contrast(img_scale)
#img_contrast_enh.enhance(1.5).show()
img_color_enh=ImageEnhance.Color(img_scale)
img_color_enh.enhance(2).show()
