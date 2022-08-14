from __future__ import division

# 调用该函数求出lnZ
# 只考虑p1和p4

from Han import TC, FM_MEV, BAG, CRU

import numpy as np
from scipy import integrate
from scipy.special import jv

import Han
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import sys
sys.path.append('../')
PRE = 10
RANGE = 20


def j0(x):
    return jv(0, x)


def f(x, y, pos=1):
    return pos*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def I(y, pos=1):
    return integrate.quad(f, 0, np.inf, args=(y, pos))[0]


def f_I(x, y,  pos=1):
    return pos*x*x*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def I_I(y, pos=1):
    return integrate.quad(f_I, 0, np.inf, args=(y, pos))[0]


def f_1(y, pos=1):
    return np.pi*(I(y, pos)/I_I(y, pos))


def f_2_minor(x, L, k, y, pos=1):
    return f(x, y, pos)*np.sin(k*L*x)/(k*L)


def f_2(L, y, pos=1):
    k = 1
    s = 0
    limit = 0
    frac = I_I(y, pos)
    while True:
        an = integrate.quad(f_2_minor, 0, np.inf,
                            args=(L, k, y, pos))[0]
        s += an
        # if limit == PRE//10:
        #     break
        # if np.abs(an) <= 1/PRE:
        #     limit += 1
        if np.abs(an) <= 1/PRE:
            break
        k += 1
    return s*2/frac
    # 趋于零会发散


def f_3_minor(x, L, k, y, pos=1):
    return f(x, y, pos)*j0(k*L*x)


def f_3(L, y, pos=1):
    k = 1
    s = 0
    limit = 0
    frac = I_I(y, pos)
    while True:
        an = integrate.quad(f_3_minor, 0, np.inf,
                            args=(L, k, y, pos))[0]
        s += an
        # if limit == PRE//10:
        #     break
        # if np.abs(an) <= 1/PRE:
        #     limit += 1
        if np.abs(an) <= 1/PRE:
            break
        k += 1
    return s*np.pi/frac


def f_4_minor(x, y, pos=1):
    return pos*np.log(1+pos*np.exp(-np.sqrt(x**2+y**2)))


def f_4(y, pos=1):
    return 2*integrate.quad(f_4_minor, 0, np.inf, args=(y, pos))[0]/I_I(y, pos)


def p_1(Lambda1, Lambda2, y, pos=1):
    return -(1/Lambda1+1/Lambda2)*f_1(y, pos)


def p_2(Lambda1, Lambda2, y,  pos=1):
    return f_2(L=Lambda1, y=y)+f_2(L=Lambda2, y=y)


def p_3(Lambda1, Lambda2, y, pos=1):
    return 2*f_3(L=Lambda1, y=y)/Lambda1+2*f_3(L=Lambda2, y=y)/Lambda2


def p_4(Lambda1, Lambda2, y, pos=1):
    return 2*f_4(y, pos)/(Lambda1*Lambda2)


def main_list(T, MI, GI, L1, L2):
    # pos=1 for fermion, pos=-1 for boson
    lnZ = []
    for i in T:
        lnZ.append(main(T=i, MI=MI, GI=GI, L1=L1, L2=L2))
    return lnZ


def main(T=TC, MI=0, GI=1, L1=1/CRU, L2=4):
    # pos=1 for fermion, pos=-1 for boson

    pos = int(((GI*2) % 2)*2-1)
    lnZ = []
    if L1 == 1/CRU:
        if L2 == 1/CRU:
            lnZ = GI*I(y=MI/T, pos=pos)/2/np.pi/np.pi*T*T*T
        else:
            lnZ = Han.lnZ(T=T, mi=MI, GI=GI, L=L2)
            # L1 = L1*FM_MEV
            # L2 = L2*FM_MEV
            # Lambda1 = 2*L1*T
            # Lambda2 = 2*L2*T
            # lnZ = GI*I(y=MI/T, pos=pos)/2/np.pi/np.pi*T*T*T*(1+p_1(Lambda1=Lambda1, Lambda2=Lambda2,
            #                                                        y=MI/T, pos=pos)+p_2(Lambda1=Lambda1, Lambda2=Lambda2,
            #                                                                             y=MI/T, pos=pos)+p_3(Lambda1=Lambda1, Lambda2=Lambda2,
            #                                                                                                  y=MI/T, pos=pos)+p_4(Lambda1=Lambda1, Lambda2=Lambda2, y=MI/T, pos=pos))
            # lnZ = GI*I(y=MI/T, pos=pos)/2/np.pi/np.pi*T*T*T*(1+p_1(Lambda1=Lambda1, Lambda2=Lambda2,
            #                                                        y=MI/T, pos=pos)+p_4(Lambda1=Lambda1, Lambda2=Lambda2, y=MI/T, pos=pos))
    else:
        L1 = L1*FM_MEV
        L2 = L2*FM_MEV
        Lambda1 = 2*L1*T
        Lambda2 = 2*L2*T
        # lnZ = GI*I(y=MI/T, pos=pos)/2/np.pi/np.pi*T*T*T*(1+p_1(Lambda1=Lambda1, Lambda2=Lambda2,
        #                                                        y=MI/T, pos=pos)+p_2(Lambda1=Lambda1, Lambda2=Lambda2,
        #                                                                             y=MI/T, pos=pos)+p_3(Lambda1=Lambda1, Lambda2=Lambda2,
        #                                                                                                  y=MI/T, pos=pos)+p_4(Lambda1=Lambda1, Lambda2=Lambda2, y=MI/T, pos=pos))
        lnZ = GI*I(y=MI/T, pos=pos)/2/np.pi/np.pi*T*T*T*(1+p_1(Lambda1=Lambda1, Lambda2=Lambda2,
                                                               y=MI/T, pos=pos)+p_4(Lambda1=Lambda1, Lambda2=Lambda2, y=MI/T, pos=pos))
    return lnZ
    # 直接在这里加倍数修正

if __name__ == '__main__':
    main()
