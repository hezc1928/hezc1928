import matplotlib.lines
import matplotlib.pyplot as plt
import numpy as np

ax=plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')
ax.spines['bottom'].set_position(('data',0))
ax.spines['left'].set_position(('data',0))

pi=2*np.arcsin(1)
i=0
la=550*1e-9#单位：m
d0=0.05#单位：m
dta=(4*pi)/la*d0*1.5*np.cos(i)#dta=delta theta(相位差)，la=lambda(波长),d0=平行板距离，i=入射角,取折射率为1.5
I_0=1#同理，为了接下来的绘图工作的方便，I_0也取特殊值

R=0.1#R=Rho(反射强度)
#为了分析反射强度对于干涉条纹的影响，所以应该通过多次改变Rho的取值来获得模拟图形
I_t=I_0/(1+(4*R*(np.sin(dta/2))*(np.sin(dta/2)))/((1-R)**2))#I_t=总叠加强度，I_0=入射光的强度
vs=2*R/(1+R**2)#vs=可见度

#接下来分为两种情况来讨论，第一种：透射光的干涉条纹图样
plt.figure(num=1,figsize=(5,5)) #图的大小
plt.subplot(facecolor='black')
d=100#d=距离
r=d*i#当角度很小时，近似认为i=sini=tani
while i<=pi/36:#取i小于5度进行分析
    i+=0.0001
    ap=4/la*d0*1.5*(np.cos(i))#a=alpha,alpha=dta/pi=4/la*d0*cosi
    if np.abs((np.sin(ap/2)-1))<0.05:
        #引入截断误差，事实上，由于数字保留的精度问题，无法真正意义上控制sin(ap/2)=1，所以只能采用该种办法完成循环控制
        #在某种意义上，这种考虑截断误差的做法同教材中采用的半值相位宽度的方法有异曲同工之妙
        #从计算机绘图的角度理解，谱线的宽度可以近似认为多条相近谱线的叠加与重合，以至于人类从肉眼上无法分辨
        plt.title('Circle of Interference of Transmission')
        r=d*i
        x=np.linspace(-r,r,100000)
        plt.xlim(-2,2)#x轴的刻度范围
        plt.ylim(-2,2)#y……
        if (r**2-x**2).all()==0.:
            y1=np.sqrt(r**2-x**2)
            y2=-np.sqrt(r**2-x**2)
            plt.plot(x,y1,color='white',linewidth=1,alpha=vs)
            #为了绘图方便，我们这里引入系数1作为绘制图线的线宽,作为数学模型与原始公式之间的转化比例（系数）
            plt.plot(x,y2,color='white',linewidth=1,alpha=vs)

#第二种情况：反射光的干涉条纹图样
plt.figure(num=2,figsize=(5,5)) #图的大小
plt.subplot(facecolor='white')
d=100#d=距离
i=0
r=d*i#当角度很小时，近似认为i=sini=tani
while i<=pi/36:#取i小于5度进行分析
    i+=0.0001
    ap=4/la*d0*1.5*(np.cos(i))#ap=dta/pi=4/la*d0*cosi
    if np.abs((np.sin(ap/2)-1))<0.05:
        plt.title('Circle of Interference of Reflection')
        r=d*i
        x=np.linspace(-r,r,100000)
        plt.xlim(-2,2)#x轴的刻度范围
        plt.ylim(-2,2)#y……
        if (r**2-x**2).all()==0.:
            y1=np.sqrt(r**2-x**2)
            y2=-np.sqrt(r**2-x**2)
            plt.plot(x,y1,color='black',linewidth=1)
            #在matplotlib中，alpha命令代表透明度，由于反射过程需要在白色背景之下绘制黑色条纹
            #以我们可以近似认为物理角度下的可见度分析过程在此可以忽略
            plt.plot(x,y2,color='black',linewidth=1)


plt.show()
