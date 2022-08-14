from __future__ import division


import Han
from Han import MI, G_QGP, TC, FM_MEV, CRU, BAG
import __0509
import time

import numpy as np
from scipy import integrate
from scipy.special import jv

import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import sys
sys.path.append('../')
PRE = 10
RANGE = 20


def j0(x):
    return jv(0, x)


I_I_p = 1.894065658993939
I_I_m = 2.1646464674208215


def I_I_N(pos=1):
    if pos == 1:
        return 0.11810101194866345
    elif pos == -1:
        return 0.11830765415098156


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


def f(x, y=MI/TC, pos=1):
    return pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def I(y=MI/TC, pos=1):
    return integrate.quad(f, 0, np.inf, args=(y, pos))[0]


def f_I(x, y=MI/TC,  pos=1):
    return pos*x*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def I_I(y=MI/TC, pos=1):
    return integrate.quad(f_I, 0, np.inf, args=(y, pos))[0]


def f_1(y=MI/TC, pos=1):
    return np.pi*(I(y, pos)/I_I(y, pos))


def f_2_minor(x, L, k, y=MI/TC, pos=1):
    return f(x, y, pos)*np.sin(k*L*x)/(k*L)


def f_2_list(L, y=MI/TC, pos=1):
    f2 = []
    frac = I_I(y, pos)
    for i in L:
        k = 1
        s = 0
        limit = 0
        while True:
            an = integrate.quad(f_2_minor, 0, np.inf, args=(i, k, y, pos))[0]
            s += an
            if limit == PRE//10:
                break
            if np.abs(an) <= 1/PRE:
                limit += 1
            # if np.abs(an) <= 1/PRE:
            #     break
            k += 1
        f2.append(s*2/frac)
    return f2  # check
    # 趋于零会发散


def f_2(L, y=MI/TC, pos=1):
    k = 1
    s = 0
    limit = 0
    frac = I_I(y, pos)
    while True:
        an = integrate.quad(f_2_minor, 0, np.inf,
                            args=(L, k, y, pos))[0]
        s += an
        if limit == PRE//10:
            break
        if np.abs(an) <= 1/PRE:
            limit += 1
        # if np.abs(an) <= 1/PRE:
        #     break
        k += 1
    return s*2/frac
    # 趋于零会发散


def f_3_minor(x, L, k, y=MI/TC, pos=1):
    return f(x, y, pos)*j0(k*L*x)


def f_3_list(L, y=MI/TC, pos=1):
    f3 = []
    frac = I_I(y, pos)
    for i in L:
        k = 1
        s = 0
        limit = 0
        while True:
            an = integrate.quad(f_3_minor, 0, np.inf, args=(i, k, y, pos))[0]
            s += an
            if limit == PRE//10:
                break
            if np.abs(an) <= 1/PRE:
                limit += 1
            # if np.abs(an) <= 1/PRE:
            #     break
            k += 1
        f3.append(s*np.pi/frac)
    return f3


def f_3(L, y=MI/TC, pos=1):
    k = 1
    s = 0
    limit = 0
    frac = I_I(y, pos)
    while True:
        an = integrate.quad(f_3_minor, 0, np.inf,
                            args=(L, k, y, pos))[0]
        s += an
        if limit == PRE//10:
            break
        if np.abs(an) <= 1/PRE:
            limit += 1
        k += 1
    return s*np.pi/frac


def f_4_minor(x, y=MI/TC, pos=1):
    return pos*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def f_4(y=MI/TC, pos=1):
    return 2*integrate.quad(f_4_minor, 0, np.inf, args=(y, pos))[0]/I_I(y, pos)


def f_4_N(pos=1):
    if pos == 1:
        return 0.2976034998412567
    elif pos == -1:
        return 0.2982642380324421


def f_5_min(t, L1, L2, k1, k2, pos=1):  # f5就是p5
    return np.cos(L1*k1*t)*np.cos(L2*k2*t)


def f_5_minor(x, L1, L2, k1, k2, y=MI/TC, pos=1):
    return f(x, y, pos)*integrate.quad(f_5_min, 0, x, limit=10*PRE, args=(L1, L2, k1, k2, pos))[0]


def f_5(L1, L2, y=MI/TC, pos=1):
    sum = 0
    k1 = 1
    while True:
        k2 = 1
        s = 0
        while True:
            an = integrate.quad(f_5_minor, 0, np.inf,
                                args=(L1, L2, k1, k2, y, pos))[0]
            s += an
            k2 += 1
            if np.abs(an) <= 1/PRE:
                break
        sum += s
        k1 += 1
        if s <= 1/PRE:
            break
    return sum


def f_5_list(L1, L2, y=MI/TC, pos=1):
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
                                    args=(i, L2, k1, k2, y, pos))[0]
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


def P(L1, L2, y=MI/TC, pos=1):
    # *+2*f_5(L1, L2, pos)
    # return 1+(1/L1+1/L2)*f_1(y=y, pos=pos)+f_2(L=L1, y=y, pos=pos)+f_2(L=L2, y=y, pos=pos)+2*f_3(L=L1, y=y, pos=pos)/L2+2*f_3(L=L2, y=y, pos=pos)/L1+2*f_4_N(pos)/(L1*L2)
    return 1-(1/L1+1/L2)*f_1(y=y, pos=pos)+2*f_4_N(pos)/(L1*L2)


def P_var(L, R, y=MI/TC, pos=1):
    # L += CRU
    # R += CRU
    L1 = 2/(1/L+1/R+CRU)
    L2 = 2/(1/L-1/R+CRU)
    # *+2*f_5(L1, L2, pos)
    # return 1+(1/L1+1/L2)*f_1(y=y, pos=pos)+f_2(L=L1, y=y, pos=pos)+f_2(L=L2, y=y, pos=pos)+2*f_3(L=L1, y=y, pos=pos)/L2+2*f_3(L=L2, y=y, pos=pos)/L1+2*f_4_N(pos)/(L1*L2)
    return 1-(1/L1+1/L2)*f_1(y=y, pos=pos)+2*f_4_N(pos)/(L1*L2)


def P_list(L1, L2, y=MI/TC,  pos=1):
    Plist = []
    for i in L1:
        # print("L1 = ", i)
        # Plist.append(1+(1/i+1/L2)*f_1(y=y, pos=pos)+f_2(L=i, y=y, pos=pos)+f_2(L=L2, y=y, pos=pos) +
        #              2*f_3(L=i, y=y, pos=pos)/L2+2*f_3(L=L2, y=y, pos=pos) /
        #              i+2*f_4_N(pos)/(i*L2))   # f5暂时不要
        Plist.append(1-(1/i+1/L2)*f_1(y=y, pos=pos)+2*f_4_N(pos)/(i*L2))
        # f2,f3今天不要
    return Plist


def P_list_var(L, R, y=MI/TC,  pos=1):
    L1 = []
    L2 = []
    Plist = []
    for i in L:
        L1.append(2/(1/i+1/R+CRU))
        L2.append(2/(1/i-1/R+CRU))
    for i in range(len(L1)):
        # Plist.append(1+(1/L1[i]+1/L2[i])*f_1(y=y, pos=pos)+f_2(L=L1[i], y=y, pos=pos)+f_2(L=L2[i], y=y, pos=pos) +
        #              2*f_3(L=L1[i], y=y, pos=pos)/L2[i]+2*f_3(L=L2[i], y=y, pos=pos) /
        #              L1[i]+2*f_4_N(pos)/(L1[i]*L2[i]))
        Plist.append(1-(1/L1[i]+1/L2[i]) *
                     f_1(y=y, pos=pos)+2*f_4_N(pos)/(L1[i]*L2[i]))
    return Plist


def p_1(L1, L2, y=MI/TC,  pos=1):
    return -(1/L1+1/L2)*f_1(y, pos)


def p_1_list(L1, L2, y=MI/TC,  pos=1):
    p1list = []
    for i in L1:
        p1list.append(-(1/i+1/L2)*f_1(y, pos))
    return p1list


def p_2(L1, L2, y=MI/TC,  pos=1):
    return f_2(L=L1, y=y)+f_2(L=L2, y=y)


def p_2_list(L1, L2, y=MI/TC, pos=1):
    p2list = []
    for i in L1:
        p2list.append(f_2(L=i, y=y)+f_2(L=L2, y=y))
    return p2list


def p_3(L1, L2, y=MI/TC, pos=1):
    return 2*f_3(L=L1, y=y)/L2+2*f_3(L=L2, y=y)/L1


def p_3_list(L1, L2, y=MI/TC, pos=1):
    p3list = []
    for i in L1:
        p3list.append(f_3(L=i, y=y) /
                      L2+2*f_3(L=L2, y=y)/i)
    return p3list


def p_4(L1, L2, y=MI/TC, pos=1):
    return 2*f_4(y, pos)/(L1*L2)


def p_4_list(L1, L2, y=MI/TC, pos=1):
    p4list = []
    for i in L1:
        p4list.append(2*f_4_N(pos)/(i*L2))
    return p4list


def pi_show_fermi(L1, y=MI/TC, L2=3):
    plt.plot(L1, np.abs(p_1_list(L1=L1, L2=L2, y=y, pos=1)),
             label='$\left| p_1 \\right|$   Fermion')
    print("done")
    plt.plot(L1, p_2_list(L1=L1, L2=L2, y=y, pos=1), label='$p_2$   Fermion')
    print("done")
    plt.plot(L1, p_3_list(L1=L1, L2=L2, y=y, pos=1), label='$p_3$   Fermion')
    print("done")
    plt.plot(L1, p_4_list(L1=L1, L2=L2, y=y, pos=1), label='$p_4$   Fermion')
    print("done")


def pi_show_boson(L1, y=MI/TC, L2=3):
    plt.plot(L1, p_1_list(L1=L1, L2=L2, y=y, pos=-1), label='$p_1$   Boson')
    print("good")
    plt.plot(L1, p_2_list(L1=L1, L2=L2, y=y, pos=-1), label='$p_2$   Boson')
    print("good")
    plt.plot(L1, p_3_list(L1=L1, L2=L2, y=y, pos=-1), label='$p_3$   Boson')
    print("good")
    plt.plot(L1, p_4_list(L1=L1, L2=L2, y=y, pos=-1), label='$p_4$   Boson')
    print("good")


def r_dim2_HG(T, L, R,  pos=1):  # 这里开始补上记得补上I项
    return T**4/TC**4*(P_list_var(L, R, y=MI/T, pos=pos)/P_list_var(1/CRU, 1/CRU,  y=MI/T, pos=pos))*I_I(y=MI/T, pos=pos)/I_I(MI/TC, pos)


def r_dim2_HG_list(T, L, R,  pos=1):
    rdim2_list = []
    const = TC**4*I_I(MI/TC, pos)*P_var(1/CRU, 1/CRU)
    for i in T:
        print("T = %.2f" % i)
        rdim2_list.append(i**4*I_I(y=MI/i, pos=pos) *
                          P_var(L=L, R=R, y=MI/i, pos=pos)/const)
    return rdim2_list


def r_dim1_HG_list(T, L, y=MI/TC, pos=1):
    rdim1_list = []
    temp_2 = Han.Han_I(MI/TC, pos=pos)*TC**4*Han.Han_p(T=TC, L=1/CRU, pos=pos)
    for i in T:
        print("T = %.2f" % i)
        temp_1 = Han.Han_I(MI/i, pos=pos) * i**4*Han.Han_p(T=i, L=L, pos=pos)
        rdim1_list.append(temp_1/temp_2)
    return rdim1_list


def r_dim1_QGP_list(T, L, y=MI/TC, pos=1):
    rdim1_list = []
    temp_2 = -TC**4*G_QGP * \
        Han.Han_I(MI/TC, pos=pos)*Han.Han_p(T=TC,
                                            L=1/CRU, pos=pos)/2/np.pi/np.pi+BAG
    for i in T:
        print("T = %.2f" % i)
        temp_1 = - i**4*G_QGP * \
            Han.Han_I(MI/i, pos=pos) * Han.Han_p(T=i,
                                                 L=L, pos=pos)/2/np.pi/np.pi+BAG
        rdim1_list.append(temp_1/temp_2)  # 改不出来
    return rdim1_list


def T_c_dim2_list(L1, L2=3,  pos=1):
    T_c = []
    for i in L1:
        T_c.append(TC*(P(i*2*TC, 2*L2*TC))**(-0.25))
    return T_c


def T_c_dim2_Qin_list(L1, L2=3,  pos=1):
    T_c = []
    for i in L1:
        T_c.append(TC*(Qin_T(i, L2, TC))**(-0.25))
    return T_c


def Qin_T(L1, L2, T):
    return 1-(np.pi/2/L1+np.pi/2/L2)/T+np.pi/4/L1/L2/T/T


def T_c_dim2_var_list(L, R,  pos=1):
    T_c = []
    for i in L:
        T_c.append(TC*(P_var(i*2*TC, 2*R*TC))**(-0.25))
    return T_c


def duibi(x):
    plt.subplot(121)
    pi_show_fermi(L1=x, L2=4)
    plt.subplot(122)
    __0509.pi_show_fermi(L1=x, L2=4)


def r_plot(T):  # 注释不准
    # plt.plot(T, r_dim2_HG_list(T, 1/CRU, 1/CRU, 1),
    #          label='inf_2_HG')  # 二维 两边无穷
    # plt.plot(T, r_dim2_HG_list(T,  2*FM_MEV, 1/CRU, 1),
    #          label='4fm*inf_2_HG')  # 二维 一边受限???没改出来
    plt.plot(T, r_dim1_HG_list(T, 1/CRU, 1), label='inf_1_HG')  # 一维 一边无穷
    # plt.plot(T, r_dim1_HG_list(T, 4*FM_MEV, 1), label='4fm_1_HG')  # 一维 一边受限
    plt.plot(T, r_dim1_QGP_list(T, 1/CRU, 1), label='inf_1_QGP')
    # plt.plot(T, r_dim1_QGP_list(T, 4*FM_MEV, 1), label='4fm_1_QGP')
    # plt.plot(T, r_dim1_list(T, 4, 1), label='4fm_1')


def T_c_all_plot(x):  # 注释不准
    # plt.plot(x, T_c_dim2_Qin_list(x*FM_MEV, np.inf, 1), label='dim2_T_c_Qin')
    #          label='L2_inf_dim2_T_c')  # 二维 第二边无穷
    # plt.plot(x, T_c_dim2_list(x*FM_MEV, 4*FM_MEV, 1),  # 二维 第二边受限
    #          label='L2_4_dim2_T_c')
    plt.plot(x, Han.T_true_list(x, 1), label='Han_True_c', linewidth=1)
    # plt.plot(x, Han.T_c_list(x, 1), label='Han_T_c', linewidth=1)
    # plt.plot(x, T_c_dim2_var_list(x*FM_MEV, 4*FM_MEV, 1),
    #          label='dim2_var_T_c')  # 二维 第二边无穷
    plt.plot(x, T_c_dim2_var_list(x*FM_MEV, np.inf, 1),
             label='4fm*inf_dim2_var_T_c')  # 二维 正方形


def main():
    start = time.time()
    initialize()

    x = np.arange(4+1/PRE, RANGE, 1/PRE)  # 最小值取零会报错
    T = np.arange(150, 200, 3/PRE)
    r_plot(T)
    end = time.time()
    print("time = ", end-start)
    plt.legend()
    plt.show()
# 两个r函数之差是单调的
# 因此可以单向搜索T，找到零点位置
# 另外，对于不同的l，T_c的值是单调的，所以可以估计出T_c的初始尝试值


if __name__ == '__main__':
    main()
