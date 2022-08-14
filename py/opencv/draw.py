import cv2 as cv
import numpy as np

blank = np.zeros((500,500,3),dtype = 'uint8')
# uint8对应图像数据类型
# 圆括号，是矩阵的规模，一个全为0的空矩阵对应纯黑图片
cv.imshow('Blank', blank)

# 画画过程：
# blank[200:300, 300:400] = 0,255,0 
# 绿色
# cv.imshow('Green',blank)
# blank[:] = 0,0,255 
# 红色
# 这一步看不懂，默认了rgb模式

cv.rectangle(blank, (0,0),(blank.shape[1]//2,blank.shape[0]//2),(0,255,0), thickness=cv.FILLED)
# 输入代码时可以看到自带的提示，起点 终点 颜色 边线宽度
# cv.FILLED可以填满内部,-1也可以
# shape[0]代表blank的第一个参数，对应长宽高
cv.imshow('Rectangle',blank)

cv.circle(blank,(250,250),40,(0,0,255),thickness= 3)
# 同上，自带提示，-1,cv.FILLED可以填满，坐标可以用shape[0]代替
cv.imshow('Circle',blank)

cv.line(blank,(100,250),(300,4000),(255,255,255), thickness=3 )
# 坐标可以超出边界
cv.imshow('Line',blank)

cv.putText(blank,'Hello',(225,225),cv.FONT_HERSHEY_TRIPLEX, 1.0,(0,255,0),2)
# cv自带字体
# 话太多了会溢出去不显示
cv.imshow('Text',blank)

cv.waitKey(0)
# 31:55下一个视频讲五个基本功能
