import PIL
from PIL import Image

basewidth = 3000
img = Image.open('LenaRGB.bmp')
wpercent = (basewidth/float(img.size[0]))
hsize = int((float(img.size[1])*float(wpercent)))
img = img.resize((basewidth,hsize), PIL.Image.ANTIALIAS)
img.save('result.jpg')
