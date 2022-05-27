"""
Модуль необходимый для вычисления двойного интеграла.
"""


def rectangular_double(args):
    f = lambda x, y: x * 2 + y
    a = args[0]
    b = args[1]
    c = args[2]
    d = args[3]
    nx = args[4]
    ny = args[5]
    hx = (b - a) / float(nx)
    hy = (d - c) / float(ny)
    res = 0
    for i in range(nx):
        for j in range(ny):
            xi = a + hx/2 + i*hx
            yj = c + hy/2 + j*hy
            res += hx*hy*f(xi, yj)
    return res

