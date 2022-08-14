
from __future__ import division

import time

import numpy as np
from scipy import integrate
from scipy.special import jv

import matplotlib.pyplot as plt
import matplotlib.ticker as mticker


def initialize():
    # 画布初始化
    ax = plt.gca()
    plt.grid(visible=None, which='major', axis='both',
             color='k', linestyle='--', linewidth=0.5)
    # ax.yaxis.set_major_formatter(mticker.FormatStrFormatter('%.02f GeV'))
    # 标签设置
    plt.title('$\\mu_B$ = 0.1 GeV')
    plt.tick_params(axis='both', which='major', labelsize=10)
    plt.xlabel('$y$', fontsize=10)
    # plt.ylabel('$\\mu_B$', fontsize=10)
    # 坐标轴尺度
    plt.xlim(-2, RANGE)
    # plt.ylim(0, 1)
    # 坐标轴刻度
    x_major_locator = mticker.MultipleLocator(1)
    y_major_locator = mticker.MultipleLocator()
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)


def f_5_min(t, L1, L2, k1, k2, pos=1):
    return np.cos(L1*k1*t)*np.cos(L2*k2*t)


def f_5_minor(x, L1, L2, k1, k2, pos=1):
    return pos*x*np.log(1+pos*np.exp(-x))*integrate.quad(f_5_min, 0, x, args=(L1, L2, k1, k2, pos))[0]


def f_5(L1, L2, pos=1):
    sum = 0
    k1 = 1
    while True:
        k2 = 1
        s = 0
        while True:
            an = integrate.quad(f_5_minor, 0, np.inf,
                                args=(L1, L2, k1, k2, pos))[0]
            s += an
            k2 += 1
            if np.abs(an) <= 1/PRE:
                break
        sum += s
        k1 += 1
        if s <= 1/PRE:
            break
    return sum


PRE = 10
RANGE = 15
start = time.time()
initialize()
print(f_5_minor(1, 1, 200, 200, 1))
print(f_5(1, 1, 1))

end = time.time()
print("time = ", end-start)
plt.show()
