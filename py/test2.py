import turtle  #引入一个绘图库
import math  #因为后面用到了根号，所以引入了math库
turtle.setup(650,350,200,200)  #确定画布的大小和位置
turtle.penup()  #提起画笔
turtle.pendown()  #放下画笔
turtle.pensize(7)  #设置画笔的粗细
turtle.pencolor("gold")  #设置画笔颜色
turtle.fillcolor('#33cc8c')  #设置填充颜色
turtle.seth(30)  #设置画笔绘制方向，参数值为直角坐标的角度
turtle.begin_fill()  #准备开始填充图形
turtle.fd(200)  #向指定方向直行
turtle.seth(-90)  #改变画笔绘制方向
turtle.fd(200)
turtle.seth(150)
turtle.fd(200)
turtle.seth(270)
turtle.circle(math.sqrt(3)*200/3,420)  #画圆，前一个参数是圆的半径，后一个参数是要画的角度
turtle.seth(90)
turtle.fd(200)
turtle.seth(-30)
turtle.fd(200)
turtle.seth(210)
turtle.fd(200)
turtle.end_fill()  #结束填充颜色
turtle.done()  #停止画笔绘制，使绘画窗口不关闭