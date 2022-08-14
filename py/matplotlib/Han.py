
from __future__ import division
import time

import numpy as np
from scipy import integrate
from scipy.special import jv, zeta

import matplotlib.pyplot as plt
import matplotlib.ticker as mticker

import xlrd
import xlwt

PRE = 10
RANGE = 15
CRU = 0.0001
MI = 850

TC = 165
FM_MEV = 0.005068  # 0.0008066  # 197.3

TIMES = 1
BAG = 0


def xls_read():
    p = []
    xls_file = xlrd.open_workbook("E:\\cpp_project\\py\\Han_data.xls")
    xls_sheet = xls_file.sheets()[0]  # num为第几个工作bu
    for i in range(0, xls_sheet.nrows):
        x = xls_sheet.cell(i, 0).value
        p.append(x)
    return p


def xls_write(p):
    workbook = xlwt.Workbook(encoding='ascii')
    worksheet = workbook.add_sheet('1')
    for count in range(len(p)):
        print(count)
        worksheet.write(count, 0, label=p[count])
    workbook.save("E:\\cpp_project\\py\\Han_data.xls")


def initialize():
    # 画布初始化
    ax = plt.gca()
    plt.grid(visible=None, which='major', axis='both',
             color='k', linestyle='--', linewidth=0.5)
    # ax.yaxis.set_major_formatter(mticker.FormatStrFormatter('%.02f GeV'))
    # 标签设置
    # plt.title('$\Lambda_2 = 3$')
    # plt.tick_params(axis='both', which='major', labelsize=15)
    # plt.xlabel('$\Lambda_1$', fontsize=15)
    # plt.ylabel('$p_i$', fontsize=15)
    # 坐标轴尺度
    # plt.xlim(0.9, 1.1)
    # plt.ylim(0, 1)
    # 坐标轴刻度
    # x_major_locator = mticker.MultipleLocator(1)
    # y_major_locator = mticker.MultipleLocator(1)
    # ax.xaxis.set_major_locator(x_major_locator)
    # ax.yaxis.set_major_locator(y_major_locator)


def Han_f(x, y, pos):
    return pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def Han_I(y, pos=1):
    return integrate.quad(Han_I_minor, 0, np.inf, args=(y, pos))[0]


def Han_I_minor(x, y, pos):
    return pos*x*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def Han_R3_t(y, pos=1):
    return (np.pi*integrate.quad(Han_f, 0, np.inf, args=(y, pos))[0])/(Han_I(y, pos))


def Han_R3_t_list(x, pos=1):
    y = []
    for i in x:
        y.append(Han_R3_t(i, pos))
    return y
# 这个好 快，而且不卡


def my_plot_Han_R3_t(pos):
    for i in range(0, RANGE*PRE):
        x = i/PRE
        y = Han_R3_t(x, pos)
        plt.scatter(x, y, s=5, c='r')
        print(x, y)


def sum():
    n = 0
    s = 0
    while True:
        an = float(10**(-n))
        n = n+1
        s = s+an
        if an <= 0.001:
            break
    print(s)


def Han_R2_minor(x, y, k, Lambda=1, pos=1):

    return np.sin(k*Lambda*x)*pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))/k


def Han_R2(y, Lambda=1, pos=1):
    k = 1
    s = 0
    while True:
        an = integrate.quad(Han_R2_minor, 0, np.inf,
                            args=(y, k, Lambda, pos))[0]
        k = k+1
        s = s+an
        if np.abs(an) <= 0.1:
            break
    numerator = 2*s
    denominator = Han_I(y, pos=pos)*Lambda
    return numerator/denominator


def Han_R2_list(y, Lambda=1, pos=1):
    R2 = []
    for i in y:
        k = 1
        s = 0
        while True:
            an = integrate.quad(Han_R2_minor, 0, np.inf,
                                args=(i, k, Lambda, pos))[0]
            k = k+1
            s = s+an
            if np.abs(an) <= 0.001:
                break
        numerator = 2*s
        denominator = Han_I(i, pos=pos)*Lambda
        R2.append(numerator/denominator)
    return R2


def plot_Han_R2(y):
    plt.plot(y, Han_R2_list(y, Lambda=1, pos=1), label='$\Lambda=1$ Fermion')
    plt.plot(y, Han_R2_list(y, Lambda=1, pos=-1), label='$\Lambda=1$ Boson')

    plt.plot(y, Han_R2_list(y, Lambda=2, pos=1), label='$\Lambda=2$ Fermion')
    plt.plot(y, Han_R2_list(y, Lambda=2, pos=-1), label='$\Lambda=2$ Boson')

    plt.plot(y, Han_R2_list(y, Lambda=3, pos=1), label='$\Lambda=3$ Fermion')
    plt.plot(y, Han_R2_list(y, Lambda=3, pos=-1), label='$\Lambda=3$ Boson')


def plot_Han_R3(y):
    plt.plot(y, Han_R3_t_list(y, 1), label='Fermion')
    plt.plot(y, Han_R3_t_list(y, -1), label='Boson')


def Han_R_list(x, Lambda=1, pos=1):
    y = []
    for i in x:
        y.append(1-Han_R3_t(i, pos=pos)/Lambda +
                 Han_R2(i, Lambda=Lambda, pos=pos))
    return y


def Han_p(T=165, L=0.0004, pos=1):
    # return 1+Han_R2(y=MI/T, Lambda=2*T*L, pos=pos) - Han_R3_t(y=MI/T, pos=pos)/L/T/2
    # R2在零附近震荡，暂不解决，直接舍弃掉
    return 1 - Han_R3_t(y=MI/T, pos=pos)/L/T/2


def Han_p_list(L, T=165,  pos=1):
    y = []
    for i in L:
        # + \            Han_R2(y=MI/T, Lambda=2*T*i, pos=pos)
        y.append(1 - Han_R3_t(y=MI/T, pos=pos)/i/T/2)
    return y


def T_c_list(L,  pos=1):
    T_c = []
    for i in L:
        T_c.append(TC+np.pi/16/i/FM_MEV)
    return T_c


def T_true_list(L,  pos=1):
    T_true = []
    for i in L:
        T_true.append(TC*(Han_p(TC, i*FM_MEV, pos))**(-0.25))  # 这么写
    return T_true


def T_plot(y):
    plt.plot(y, T_c_list(y), label='approximate')
    plt.plot(y, T_true_list(y),  label='true')


###############################################################################
def Han_f_var(x, y, pos):
    return pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def Han_R3_var(y, pos=1):
    return (np.pi*integrate.quad(Han_f, 0, np.inf, args=(y, pos))[0])/(Han_I(y, pos))


def Han_p_var(T, L, mi, pos):

    return 1 - Han_R3_t(y=mi/T, pos=pos)/L/T/2

###############################################################################


def lnZ_list(T, mi, GI, L):
    # pos=1 for fermion, pos=-1 for boson
    ans = []
    for i in T:
        ans.append(lnZ(T=i, mi=mi, GI=GI, L=L))
    return ans


def lnZ(T=TC, mi=0, GI=1, L=1/CRU):
    # pos=1 for fermion, pos=-1 for boson
    pos = int(((GI*2) % 2)*2-1)
    lnZ = []
    L = L*FM_MEV
    Lambda = 2*L*T
    lnZ = GI*Han_I(y=mi/T, pos=pos)/2/np.pi/np.pi*T*T * \
        T*Han_p_var(T=T, L=Lambda, mi=mi, pos=pos)
    # print('lnZ = %.4f' % lnZ)
    return lnZ


def cal_QGP(T, L):
    lnZ_g_up = lnZ_list(T=T, mi=0, GI=1, L=L)  # gluon
    lnZ_u_up = lnZ_list(T=T, mi=0, GI=1/2, L=L)  # u quark
    lnZ_d_up = lnZ_u_up  # d quark
    lnZ_s_up = lnZ_list(T=T, mi=150, GI=1/2, L=L)  # s quark
    lnZ_g_down = lnZ(T=TC, mi=0, GI=1, L=1/CRU)  # gluon
    lnZ_u_down = lnZ(T=TC, mi=0, GI=1/2, L=1/CRU)  # u quark
    lnZ_d_down = lnZ_u_down  # d quark
    lnZ_s_down = lnZ(T=TC, mi=150, GI=1/2, L=1/CRU)  # s quark
    omega_up = []
    omega_down = []
    r = []
    for i in range(len(T)):
        omega_up.append(-TIMES*T[i]*(lnZ_d_up[i]+3*lnZ_g_up[i] +
                        lnZ_u_up[i]+lnZ_s_up[i])+BAG)
        omega_down.append(-TIMES*T[i]*(lnZ_d_down +
                          3*lnZ_g_down+lnZ_u_down+lnZ_s_down)+BAG)
        r.append(omega_up[i]/omega_down[i])
    plt.plot(T, r, label='$\Lambda_2 = 4fm$')


def main():
    start = time.time()
    initialize()
    y = np.arange(1/PRE, RANGE, 1/PRE)
    T = np.arange(150, 200, 1/PRE)

    cal_QGP(T, 1/CRU)

    end = time.time()
    print("time = ", end-start)
    plt.legend()
    plt.show()


if __name__ == '__main__':
    main()
