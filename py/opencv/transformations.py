import cv2 as cv
import numpy as np


ori = cv.imread('pic/sky.jpg')
# 默认读取为bgr图像

# cv.imshow('sky', ori )

def rescaleFrame(frame, scale= 0.2):# 这个函数是一种缩放方法，适用于图像，视频，实时视频
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    # 注意这里的0和1参数
    
    dimensions = (width,height)
    # 圆括号，是矩阵的规模
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

img = rescaleFrame(ori)
# cv.imshow('sky', img)

cv.waitKey(0)
# Translation 平移
def translate(img, x, y):
    transMat = np.float32([[1,0,x],[0,1,y]])
    dimensions = (img.shape[1], img.shape[0])
    # shape是img类的一个属性，第二位[1]是宽度，第一位[0]是高度
    return cv.warpAffine(img, transMat, dimensions)
# x向右，y向左；负号，反向

translated = translate(img,100,100)

# cv.imshow('Translated',translated)

# Rotation旋转
def rotate(img,angle,rotPoint = None):
    (height,width) = img.shape[:2]

    if rotPoint is None:
        rotPoint = (width//2,height//2)
    rotMat = cv.getRotationMatrix2D(rotPoint,angle, 1.0)
    dimensions = (width,height)
    return cv.warpAffine(img,rotMat,dimensions)

rotated = rotate(img, 45)
# 正角度逆时针
# cv.imshow('rotated', rotated)

rotated_rotated = rotate(rotated, 45)
# cv.imshow('Rotated Rotated',rotated_rotated)

# Resizing
resized = cv.resize(img,(500,500),interpolation= cv.INTER_CUBIC)

# cv.imshow('Resized',resized)
# Flipping
flip = cv.flip(img, 0)
# 第二项有0,-1,1,对应反转方向，-1是横竖全翻转
# cv.imshow('Flip', flip)

# cropping
cropped = img[200:400, 300:400]
cv.imshow('Cropped',cropped)

cv.waitKey(0)
# 57:06下一个视频讲识别轮廓