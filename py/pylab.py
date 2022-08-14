
from pylab import *
import matplotlib.pyplot as plt
import numpy as np
X = np.linspace(-np.pi, np.pi, 256,endpoint=True)
C,S = np.cos(X), np.sin(X)

# 创建一个 8 * 6 点（point）的图，并设置分辨率为 80
plt.figure(figsize=(8,6), dpi=80)

# 创建一个新的 1 * 1 的子图，接下来的图样绘制在其中的第 1 块（也是唯一的一块）
plt.subplot(1,1,1)

X = np.linspace(-np.pi, np.pi, 256,endpoint=True)
C,S = np.cos(X), np.sin(X)

# 绘制余弦曲线，使用蓝色的、连续的、宽度为 1 （像素）的线条
plt.plot(X, C, color="blue", linewidth=1.0, linestyle="-")

# 绘制正弦曲线，使用绿色的、连续的、宽度为 1 （像素）的线条
plt.plot(X, S, color="green", linewidth=1.0, linestyle="-")

# 设置横轴的上下限
plt.xlim(-4.0,4.0)
# 设置纵轴的上下限
plt.ylim(-1.0,1.0)

# 设置横轴记号
plt.xticks(np.linspace(-4,4,9,endpoint=True))

# 设置纵轴记号
plt.yticks(np.linspace(-1,1,5,endpoint=True))

# 以分辨率 72 来保存图片
# savefig("exercice_2.png",dpi=72)

# 自适应设置1
# plt.xlim(X.min()*1.1, X.max()*1.1)
# plt.ylim(C.min()*1.1, C.max()*1.1)
# 自适应设置2
xmin ,xmax = X.min(), X.max()
ymin, ymax = C.min(), C.max()

dx = (xmax - xmin) * 0.2
dy = (ymax - ymin) * 0.2

plt.xlim(xmin - dx, xmax + dx)
plt.ylim(ymin - dy, ymax + dy)
# 在屏幕上显示
plt.show()