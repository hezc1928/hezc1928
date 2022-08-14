import cv2 as cv

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
cv.imshow('Image', img)



# 转换为灰度图(gray scale)
gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
# cv.imshow ('Gray', gray )

# 如何模糊(blur)，可以降噪用。现在先讲高斯模糊

blur = cv.GaussianBlur(img, (3,3),cv.BORDER_DEFAULT)
# cv.imshow('Blur',blur)
# 经过缩放后有明显的模糊效果。可以通过增加内核大小来提高模糊效果，但是内核必须是奇数。
# blur_2 = cv.GaussianBlur(img, (99,99),cv.BORDER_DEFAULT)
# cv.imshow('Blur_2',blur_2)
# 对比用的第二项

# edge cascade 边缘级联 这里先用著名的canny边缘检测器
canny = cv.Canny(img , 125, 175)
# 如果处理对象是blur而不是img，则边缘会模糊，处理出的白线会变少。
# cv.imshow('Canny Edges',canny)

# 用结构化扩展图像
dilated = cv.dilate(canny, (7,7), iterations= 3)
# 操作对象，内核（不要求是奇数），迭代次数
# 增加迭代次数，边缘会变厚
# cv.imshow('Dilated', dilated)

# Eroding
eroded = cv.erode(dilated, (7,7), iterations= 1)
# cv.imshow('Eroded',eroded)

# Resize

resized = cv.resize(img, (500,500))
# 无视长宽比，直接压缩拉伸，还可以加 iterations= 参数
cv.imshow('Resized', resized)

# Cropping 裁剪
cropped = img[50:200,200:400]
# 先竖后横
cv.imshow('Cropped', cropped)

cv.waitKey(0)
# 44:13下一个视频讲平移旋转调整大小反转裁剪