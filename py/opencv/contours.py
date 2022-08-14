import cv2 as cv
import numpy as np
from numpy.lib.function_base import blackman
ori = cv.imread('pic/sky.jpg')


def rescaleFrame(frame, scale=0.2):  # 这个函数是一种缩放方法，适用于图像，视频，实时视频
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    # 注意这里的0和1参数

    dimensions = (width, height)
    # 圆括号，是矩阵的规模
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)


img = rescaleFrame(ori)
# cv.imshow('img', img)

blank = np.zeros(img.shape, dtype='uint8')
# cv.imshow('Blank', blank)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('Gray', gray)

blur = cv.GaussianBlur(img, (5, 5), cv.BORDER_DEFAULT)
# cv.imshow('Blur', blur)

# 轮廓和边缘是不同的，这次讲轮廓
canny = cv.Canny(img, 125, 175)
cv.imshow('Canny Edges', canny)

contours, hierarchies = cv.findContours(
    canny, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
print(f'{len(contours)} contour(s) found!')
# 这里的输出方法值得研究一下
# 如果添加blur步骤，找到的边界数会少很多。这里从4541降到了772

cv.drawContours(blank, contours, -1, (0, 0, 126), 2)
cv.imshow('Contours Drawn', blank)
# 同时输出Contours和Canny，我们可以发现这并不是完全相同的，也就是说轮廓和边缘不同。

ret, thresh = cv.threshold(gray, 125, 255, cv.THRESH_BINARY)
cv.imshow('Thresh', thresh)

# 查看图像并尝试将其二值化，注意最后d加cv.THRESH_BINARY参数，显然，我们还有_INV，可以反色

cv.waitKey(0)
# 1:12:54下一个视频开始高级部分 color space