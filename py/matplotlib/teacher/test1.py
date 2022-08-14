import matplotlib.pyplot as plt


plt.subplot(221)
plt.xlim(xmax=7, xmin=0)
plt.ylim(ymax=7, ymin=0)
plt.xlabel("x")
plt.ylabel("y")
plt.plot([1, 2, 3], [4, 5, 6], 'ro')

plt.subplot(222)
plt.xlim(xmax=7, xmin=0)
plt.ylim(ymax=7, ymin=0)
plt.xlabel("x")
plt.ylabel("y")
plt.plot([1, 2, 3], [4, 5, 6], 'ro')

plt.subplot(223)

plt.xlim(xmax=7, xmin=0)
plt.ylim(ymax=7, ymin=0)
plt.xlabel("x")
plt.ylabel("y")
plt.plot([1, 2, 3], [4, 5, 6], 'ro')

plt.show()
