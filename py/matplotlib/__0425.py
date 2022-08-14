
from __future__ import division
from cv2 import line

import numpy as np
from scipy import integrate
from scipy.special import jv, zeta

import matplotlib.pyplot as plt
import matplotlib.ticker as mticker

# import math

PRE = 10


def initialize():
    # 画布初始化
    ax = plt.gca()
    plt.grid(visible=None, which='major', axis='both',
             color='k', linestyle='--', linewidth=0.5)
    ax.yaxis.set_major_formatter(mticker.FormatStrFormatter('%.02f GeV'))
    # 标签设置
    plt.title('$\\mu_B$ = 0.1 GeV')
    plt.tick_params(axis='both', which='major', labelsize=10)
    plt.xlabel('$\\mu_B$', fontsize=10)
    plt.ylabel('$\\mu_B$', fontsize=10)
    # 坐标轴尺度
    # plt.xlim(0, 3)
    # plt.ylim(0, 1)
    # 坐标轴刻度
    x_major_locator = mticker.MultipleLocator(1)
    y_major_locator = mticker.MultipleLocator()
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)


def Han_R3(x):
    return np.sqrt(2*np.pi/x)*(1-7/(8*x+15))


def Han_R3_p_t(y):
    return (np.pi*integrate.quad(Han_f_p, 0, np.inf, args=(y))[0])/(Han_I_p(y))


def Han_f_p(x, y):
    return x*np.log(1+np.exp(-np.sqrt(x**2+y**2)))


def Han_I_p(y):
    return integrate.quad(Han_I_p_minor, 0, np.inf, args=(y))[0]


def Han_I_p_minor(x, y):
    return x*x*np.log(1+np.exp(-np.sqrt(x**2+y**2)))


def my_plot_Han_R3_p_t():
    for i in range(0, 10*PRE):
        x = i/PRE
        y = Han_R3_p_t(x)
        plt.scatter(x, y, s=5, c='r')
        print(x, y)


def Han_R3_m_t(y):
    return (np.pi*integrate.quad(Han_f_m, 0, np.inf, args=(y))[0])/(Han_I_p(y))


def Han_I_m(y):
    return integrate.quad(Han_I_m_minor, 0, np.inf, args=(y))[0]


def Han_I_m_minor(x, y):
    return x*x*np.log(1-np.exp(-np.sqrt(x**2+y**2)))


def Han_f_m(x, y):
    return -x*np.log(1-np.exp(-np.sqrt(x**2+y**2)))


def my_plot_Han_R3_m_t():
    for i in range(0, 10*PRE):
        x = i/PRE
        y = Han_R3_m_t(x)
        plt.scatter(x, y, s=5, c='r')
        print(x, y)


def Han_f(x, y, pos):
    return pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def Han_I(y, pos):
    return integrate.quad(Han_I_minor, 0, np.inf, args=(y, pos))[0]


def Han_I_minor(x, y, pos):
    return pos*x*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def Han_R3_t(y, pos):
    return (np.pi*integrate.quad(Han_f, 0, np.inf, args=(y, pos))[0])/(Han_I(y, pos))


def my_plot_Han_R3_t(pos):
    for i in range(0, 10*PRE):
        x = i/PRE
        y = Han_R3_t(x, pos)
        plt.scatter(x, y, s=5, c='r')
        print(x, y)


initialize()
# my_plot_Han_R3_p_t()
# my_plot_Han_R3_m_t()
my_plot_Han_R3_t(1)
# my_plot_Han_R3_t(-1)
# plt.legend()
plt.show()
