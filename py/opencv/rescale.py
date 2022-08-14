import cv2 as cv

img = cv.imread('pic/horse.jpg')
cv.imshow('horse', img )
# 注释快捷键：ctrl+/
capture = cv.VideoCapture('video/ACR.mp4')

def rescaleFrame(frame, scale= 0.75):# 这个函数是一种缩放方法，适用于图像，视频，实时视频
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    # 注意这里的0和1参数
    
    dimensions = (width,height)
    # 圆括号，是矩阵的规模
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

resized_image = rescaleFrame(img)
cv.imshow('Image', resized_image)


def changRes(width,height):# 还有一种只适用于视频帧的缩放方法，只适用于实时视频
    capture.set(3,width)
    capture.set(4,height)

while True:
    isTrue, frame = capture.read()#isTrue是个bool值，反馈是否成功读取
    frame_resized = rescaleFrame(frame, scale= .2)# 可以选择添加scale参数，进行其他缩放比例
    cv.imshow('Video',frame)
    cv.imshow('Video Resized', frame_resized)
    if cv.waitKey(20) & 0xff==ord('d'):#按d就可以提前终止
        break

capture.release()
cv.destroyAllWindows()
cv.waitKey(0)
# 20:25下一个视频讲画图，添加文本