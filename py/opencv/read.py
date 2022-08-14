
import cv2 as cv

img = cv.imread('pic/horse.jpg')
#将图像以矩阵形式返回
cv.imshow('horse', img )

#输入分辨率更高的图片会只显示左上角

#总之，现在大图像会消失

cv.waitKey(0)

#0会等待无限长时间
#现在读取视频

capture = cv.VideoCapture(1)
# 如果是电脑自带摄像头，参数写0即可，多台则有编号

# 用whlie循环逐帧读取视频

# error: (-215:Assertion failed)代表视频读取到尽头了

while True:
    isTrue, frame = capture.read()#isTrue是个bool值，反馈是否成功读取
    cv.imshow('Video',frame)
    
    if cv.waitKey(20) & 0xff==ord('d'):#按d就可以提前终止
        break
capture.release()

cv.destroyAllWindows()

#12：59 下一讲是缩放图像