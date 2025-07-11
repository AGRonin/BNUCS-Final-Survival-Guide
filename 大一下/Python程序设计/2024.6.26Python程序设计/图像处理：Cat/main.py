import numpy as np
from PIL import Image,ImageFont,ImageDraw,ImageFilter,ImageEnhance

#文件读取
img_cat=Image.open('Cat.jpg')

#pillow实现
img_pillow_flip_left_right=img_cat.transpose(Image.FLIP_LEFT_RIGHT)
img_pillow_flip_top_bottom=img_cat.transpose(Image.FLIP_TOP_BOTTOM)
img_pillow_flip_left_right.show()
img_pillow_flip_top_bottom.show()

r,g,b=img_cat.split()
newr=r.point(lambda x:255-x)
newg=g.point(lambda x:255-x)
newb=b.point(lambda x:255-x)
img_pillow_inverse_color=Image.merge(img_cat.mode,(newr,newg,newb))
img_pillow_inverse_color.show()

img_pillow_grey=img_cat.convert('L')
img_pillow_grey.show()

#numpy实现
size=img_cat.size

img_numpy_array=np.array(img_cat,dtype=int)
img_numpy_array=np.clip(img_numpy_array,0,255)
img_numpy_array_flip_left_right=np.flip(img_numpy_array,axis=1)
img_numpy_flip_left_right=Image.fromarray(img_numpy_array_flip_left_right.astype('uint8'))
img_numpy_array_flip_top_bottom=np.flip(img_numpy_array,axis=0)
img_numpy_flip_top_bottom=Image.fromarray(img_numpy_array_flip_top_bottom.astype('uint8'))

img_numpy_array_inverse_color=255-img_numpy_array
img_numpy_inverse_color=Image.fromarray(img_numpy_array_inverse_color.astype('uint8'))
img_numpy_flip_left_right.show()
img_numpy_flip_top_bottom.show()
img_numpy_inverse_color.show()

r,g,b=img_numpy_array[:,:,0],img_numpy_array[:,:,1],img_numpy_array[:,:,2]
grey=np.clip(r*0.299+g*0.587+b*0.114,0,255)
img_numpy_grey=Image.fromarray(grey.astype('uint8'))
img_numpy_grey.show()


#HSV图像
img_nsv=Image.new(mode='HSV',size=size,color=(0,0,100))
for i in range(img_cat.width):
    for j in range(img_cat.height):
        r,g,b=img_cat.getpixel((i,j))
        r=r/255
        g=g/255
        b=b/255
        v=max(r,g,b)
        if v!=0:
            s=(v-min(r,g, b))/v
            if s==0:
                h=0
            else:
                if v == r:
                    h = 60 * (g - b) / (v - min(r, g, b))
                elif v == g:
                    h = 120 + 60 * (b - r) / (v - min(r, g, b))
                elif v == b:
                    h = 60 * (r - g) / (v - min(r, g, b))
        else:
            s=0
            h=0
        h=h%360
        h=int(h)
        s=int(s*255)
        v=int(v*255)
        img_nsv.putpixel((i,j),(h,s,v))
img_nsv.show()

#mask图像
img_nsv_mask=Image.new(mode='HSV',size=size,color=(0,0,100))
for i in range(img_nsv.width):
    for j in range(img_nsv.height):
        h,s,v = img_nsv.getpixel((i, j))
        h=h%180
        if 80<=h<=120 or 150<=s<=255 or 150<=v<=255:
            h=0
            s=0
            v=255
        else:
            h=0
            s=0
            v=0
        img_nsv_mask.putpixel((i,j),(h,s,v))
img_nsv_mask.show()