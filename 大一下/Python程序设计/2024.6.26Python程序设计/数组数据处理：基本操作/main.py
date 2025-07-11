import numpy as np
a=np.ones((2,3))
#print(a)
b=np.diag((2,5,8))
#print(b)
c=np.eye(4)
#print(c)

d=np.array([[1,5,3],[0,4,6]])
#print(d)
lst=d.tolist()
#print(lst)

#print(d+5)
#print(np.sin(d))
#print(np.sqrt(d))

#print((d>3)&(d<6))
#print(d[(d>3)&(d<6)])
d[d>3]+=1
#print(d)

#print(a+d)
#print(a-d)
#print(a*d)
#print(a@d.T)

#print(d)
#print(d.sum())
#print(d.sum(axis=0))#对列求和
#print(d.sum(axis=1))#对行求和

#print(d.min())
#print(d.min(axis=0))
#print(d.argmin(axis=0))
#print(np.sort(d,axis=0))

"""处理数组"""
from PIL import Image
#img_pil=Image.open('WechatIMG2178.jpg')
img_pil=Image.open('../../课件/Day3/Images/moon.png')
img=np.array(img_pil,dtype=int)
img=np.clip(img,0,255)
img2_pil=Image.fromarray(img.astype('uint8'))
#img_pil.show()
#img2_pil.show()

r,g,b=img[:,:,0],img[:,:,1],img[:,:,2]
print(r)
newr=r*1.3
newr=np.clip(newr,0,255)
newr=newr.astype('uint8')
img_new=np.stack((b,g,newr),axis=2)
img3_pil=Image.fromarray(img_new.astype('uint8'))
img3_pil.show()

R= np.clip(r*0.394 + g*0.768 + b*0.188, 0, 255)
G= np.clip(r*0.347 + g*0.685 + b*0.167, 0, 255)
B= np.clip(r*0.273 + g*0.536 + b*0.132, 0, 255)
img_old = np.stack((B.astype('uint8'), G.astype('uint8'), R.astype('uint8')), axis=2)
img_all = np.hstack((img_new, img_old)) #水平组合
img4_pil = Image.fromarray(img_old.astype('uint8'))  #确保类型是uint8
img4_pil.show()