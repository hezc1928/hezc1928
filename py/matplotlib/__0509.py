from __future__ import division

from matplotlib import scale
import Han
from Han import MI, G_QGP, TC, FM_MEV
import time

import numpy as np
from scipy import integrate
from scipy.special import jv

import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import sys
sys.path.append('../')

PRE = 20
RANGE = 30
CRU = 0.000001
B = 236**4


def j0(x):
    return jv(0, x)


I_I_p = 1.894065658993939
I_I_m = 2.1646464674208215


def I_I_N(pos=1):
    if pos == 1:
        return 1.894065658993939
    elif pos == -1:
        return 2.1646464674208215


def initialize():
    # 画布初始化
    ax = plt.gca()
    plt.grid(visible=None, which='major', axis='both',
             color='k', linestyle='--', linewidth=0.5)
    # ax.yaxis.set_major_formatter(mticker.FormatStrFormatter('%.02f GeV'))
    # 标签设置
    plt.title('$\Lambda_2 = 3$')
    plt.tick_params(axis='both', which='major', labelsize=15)
    plt.xlabel('$\Lambda_1$', fontsize=15)
    plt.ylabel('$p_i$', fontsize=15)
    # 坐标轴尺度
    # plt.xlim(0.9, 1.1)
    # plt.ylim(0, 1)
    # 坐标轴刻度
    x_major_locator = mticker.MultipleLocator(1)
    y_major_locator = mticker.MultipleLocator(1)
    ax.xaxis.set_major_locator(x_major_locator)
    ax.yaxis.set_major_locator(y_major_locator)


def f(x, pos=1):
    return pos*x*np.log(1+pos*np.exp(-x))


def I(pos=1):
    return integrate.quad(f, 0, np.inf, args=(pos))[0]


def f_I(x, pos=1):
    return x*pos*x*np.log(1+pos*np.exp(-x))


def I_I(pos=1):
    return integrate.quad(f_I, 0, np.inf, args=(pos))[0]


def f_1(pos=1):
    return np.pi*(I(pos)/I_I(pos))  # check


def f_2_minor(x, L, k, pos=1):
    return pos*x*np.log(1+pos*np.exp(-x))*np.sin(k*L*x)/(k*L)


def f_2_list(L, pos=1):
    f2 = []
    for i in L:
        k = 1
        s = 0
        limit = 0
        while True:
            an = integrate.quad(f_2_minor, 0, np.inf, args=(i, k, pos))[0]
            s += an
            if limit == PRE//10:
                break
            if np.abs(an) <= 1/PRE:
                limit += 1
            # if np.abs(an) <= 1/PRE:
            #     break
            k += 1
        f2.append(s*2/I_I_N(pos))
    return f2  # check
    # 趋于零会发散


def f_2(L, pos=1):
    k = 1
    s = 0
    limit = 0
    while True:
        an = integrate.quad(f_2_minor, 0, np.inf,
                            args=(L, k, pos))[0]
        s += an
        if limit == PRE//10:
            break
        if np.abs(an) <= 1/PRE:
            limit += 1
        # if np.abs(an) <= 1/PRE:
        #     break
        k += 1
    return s*2/I_I_N(pos)
    # 趋于零会发散


def f_3_minor(x, L, k, pos=1):
    return pos*x*np.log(1+pos*np.exp(-x))*j0(k*L*x)


def f_3_list(L, pos=1):
    f3 = []
    for i in L:
        k = 1
        s = 0
        limit = 0
        while True:
            an = integrate.quad(f_3_minor, 0, np.inf, args=(i, k, pos))[0]
            s += an
            if limit == PRE//10:
                break
            if np.abs(an) <= 1/PRE:
                limit += 1
            # if np.abs(an) <= 1/PRE:
            #     break
            k += 1
        f3.append(s*np.pi/I_I_N(pos))
    return f3


def f_3(L, pos=1):
    k = 1
    s = 0
    limit = 0
    while True:
        an = integrate.quad(f_3_minor, 0, np.inf,
                            args=(L, k, pos))[0]
        s += an
        if limit == PRE//10:
            break
        if np.abs(an) <= 1/PRE:
            limit += 1
        k += 1
    return s*np.pi/I_I_N(pos)


def f_4_minor(x, pos=1):
    return pos*np.log(1+pos*np.exp(-x))


def f_4(pos):
    return 2*integrate.quad(f_4_minor, 0, np.inf)[0]/I_I_N(pos)  # check


def f_4_N(pos=1):
    if pos == 1:
        return 0.8684672883631483
    elif pos == -1:
        return 0.7599088773180438


def f_5_min(t, L1, L2, k1, k2, pos=1):
    return np.cos(L1*k1*t)*np.cos(L2*k2*t)


def f_5_minor(x, L1, L2, k1, k2, pos=1):
    return pos*x*np.log(1+pos*np.exp(-x))*integrate.quad(f_5_min, 0, x, limit=10*PRE, args=(L1, L2, k1, k2, pos))[0]


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


def f_5_list(L1, L2, pos=1):
    f5 = []
    k1 = 1
    for i in L1:
        sum = 0
        limit_1 = 0
        while True:
            k2 = 1
            s = 0
            limit = 0
            while True:
                an = integrate.quad(f_5_minor, 0, np.inf,
                                    args=(i, L2, k1, k2, pos))[0]
                s += an
                k2 += 1
                if limit == PRE//10:
                    break
                if np.abs(an) <= 1/PRE:
                    limit += 1
                # if np.abs(an) <= 1/PRE:
                #     break
            sum += s
            k1 += 1
            if limit_1 == PRE//10:
                break
            if np.abs(s) <= 1/PRE:
                limit_1 += 1
            # if s <= 1/PRE:
            #     break
        f5.append(sum)
    return f5


def P(L1, L2, pos=1):
    # *+2*f_5(L1, L2, pos)
    return 1+(1/L1+1/L2)*f_1(pos)+f_2(L1)+f_2(L2)+2*f_3(L1)/L2+2*f_3(L2)/L1+2*f_4_N(pos)/(L1*L2)


def P_var(L, R, pos=1):
    L += CRU
    R += CRU
    L1 = 2/(1/L+1/R+CRU)
    L2 = 2/(1/L-1/R+CRU)
    # *+2*f_5(L1, L2, pos)
    return 1+(1/L1+1/L2)*f_1(pos)+f_2(L1)+f_2(L2)+2*f_3(L1)/L2+2*f_3(L2)/L1+2*f_4_N(pos)/(L1*L2)


def P_list(L1, L2, pos=1):
    Plist = []
    for i in L1:
        # print("L1 = ", i)
        Plist.append(1+(1/i+1/L2)*f_1(pos)+f_2(i)+f_2(L2)+2*f_3(i) /
                     L2+2*f_3(L2)/i+2*f_4_N(pos)/(i*L2))  # f5暂时不要
    return Plist


def P_list_var(L, R, pos=1):
    L1 = []
    L2 = []
    Plist = []
    for i in L:
        L1.append(2/(1/i+1/R+CRU))
        L2.append(2/(1/i-1/R+CRU))
    for i in range(len(L1)):

        Plist.append(1+(1/L1[i]+1/L2[i])*f_1(pos)+f_2(L1[i])+f_2(L2[i])+2*f_3(L1[i]) /
                     L2[i]+2*f_3(L2[i])/L1[i]+2*f_4_N(pos)/(L1[i]*L2[i]))
    return Plist


def p_1(L1, L2, pos=1):
    return (1/L1+1/L2)*f_1(pos)


def p_1_list(L1, L2, pos=1):
    p1list = []
    for i in L1:
        p1list.append((1/i+1/L2)*f_1(pos))
    return p1list


def p_2(L1, L2, pos=1):
    return f_2(L1)+f_2(L2)


def p_2_list(L1, L2, pos=1):
    p2list = []
    for i in L1:
        p2list.append(f_2(i)+f_2(L2))
    return p2list


def p_3(L1, L2, pos=1):
    return 2*f_3(L1)/L2+2*f_3(L2)/L1


def p_3_list(L1, L2, pos=1):
    p3list = []
    for i in L1:
        p3list.append(f_3(i) /
                      L2+2*f_3(L2)/i)
    return p3list


def p_4(L1, L2, pos=1):
    return 2*f_4_N(pos)/(L1*L2)


def p_4_list(L1, L2, pos=1):
    p4list = []
    for i in L1:
        p4list.append(2*f_4_N(pos)/(i*L2))
    return p4list


def pi_show_fermi(L1, L2=3):
    plt.plot(L1, p_1_list(L1, L2, 1), label='$p_1$   Fermion')
    plt.plot(L1, p_2_list(L1, L2, 1), label='$p_2$   Fermion')
    plt.plot(L1, p_3_list(L1, L2, 1), label='$p_3$   Fermion')
    plt.plot(L1, p_4_list(L1, L2, 1), label='$p_4$   Fermion')


def pi_show_boson(L1, L2=3):
    plt.plot(L1, p_1_list(L1, L2, -1), label='$p_1$   Boson')
    plt.plot(L1, p_2_list(L1, L2, -1), label='$p_2$   Boson')
    plt.plot(L1, p_3_list(L1, L2, -1), label='$p_3$   Boson')
    plt.plot(L1, p_4_list(L1, L2, -1), label='$p_4$   Boson')


def r_dim2_HG(T, L, R, pos=1):
    return T**4/TC**4*(P_list_var(L, R, pos)/P_list_var(1/CRU, 1/CRU, pos))


def r_dim2_HG_list(T, L, R, pos=1):
    rdim2_list = []
    for i in T:
        print("T = %.2f" % i)
        rdim2_list.append(i**4/TC**4*(P_var(L, R, pos) /
                          P_var(1/CRU, 1/CRU, pos)))
    return rdim2_list


def r_dim1_HG_list(T, L, pos=1):
    rdim1_list = []
    temp_2 = Han.Han_I(MI/TC, pos=pos)*TC**4*Han.Han_p(T=TC, L=1/CRU, pos=pos)
    for i in T:
        print("T = %.2f" % i)
        temp_1 = Han.Han_I(MI/i, pos=pos) * i**4*Han.Han_p(T=i, L=L, pos=pos)
        rdim1_list.append(temp_1/temp_2)
    return rdim1_list


def r_dim1_QGP_list(T, L, pos=1):
    rdim1_list = []
    temp_2 = -TC**4*G_QGP * \
        Han.Han_I(MI/TC, pos=pos)*Han.Han_p(T=TC,
                                            L=1/CRU, pos=pos)/2/np.pi/np.pi+B
    for i in T:
        print("T = %.2f" % i)
        temp_1 = - i**4*G_QGP * \
            Han.Han_I(MI/i, pos=pos) * Han.Han_p(T=i,
                                                 L=L, pos=pos)/2/np.pi/np.pi + B
        rdim1_list.append(temp_1/temp_2)  # 改不出来
    return rdim1_list


def main():
    start = time.time()
    # initialize()

    x = np.arange(2+1/PRE, RANGE, 1/PRE)  # 最小值取零会报错
    T = np.arange(150, 200, 3/PRE)
    # plt.plot(x, P_list_var(x, 1/CRU, 1), label='inf')
    # plt.plot(x, P_list_var(x, 1, 1), label='1')
    # plt.plot(x, Han.Han_p_list(L=x, pos=1), 'r', label='Han')  # 这个图像也许是对的
    # print(Han.Han_p(L=1/CRU, pos=1))  # 这个图像也许是对的
    # plt.plot(T, r_dim2_list(T, 4, 1/CRU, 1), label='4fm_2')
    # plt.plot(T, r_dim2_list(T, np.inf, 1/CRU, 1), label='inf')
    # plt.plot(T, r_dim1_HG_list(T, 1/CRU, 1), label='inf_1_HG')
    # plt.plot(T, r_dim1_HG_list(T, 4*FM_MEV, 1), label='4fm_HG')
    # plt.plot(T, r_dim1_QGP_list(T, 1/CRU, 1), label='inf_1_QGP')
    # plt.plot(T, r_dim1_list(T, 4, 1), label='4fm_1')
    # print(r_dim1(180, 1/CRU, 1))
    end = time.time()
    print("time = ", end-start)
    plt.legend()
    plt.show()


if __name__ == '__main__':
    main()
