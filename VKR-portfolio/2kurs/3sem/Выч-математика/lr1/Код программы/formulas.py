"""
В модуле содержатся функции для подсчета интегралов
"""

import math


def func(x):
    return math.cos(x)


def rectangle_right(args: list) -> float:
    """Интегралы методом правых частей прямоугольника.
    Args - это a, b  и количество разбиений"""
    h = (args[1]-args[0])/args[2]
    i = args[0]+h
    res = 0
    while i <= args[1]:
        res += h * func(i)
        i += h
    return res


def rectangle_left(args: list) -> float:
    """args - это a, b  и количество разбиений"""
    h = (args[1]-args[0])/args[2]
    i = args[0]
    res = 0
    while i <= args[1]-h:
        res += h * func(i)
        i += h
    return res


def trapeze(args: list) -> float:
    """args - это a, b  и количество разбиений"""
    h = (args[1]-args[0])/args[2]
    i = args[0] + h
    res = 0
    while i <= args[1]-h:
        res += func(i)
        i += h
    res += (func(args[0]) + func(args[1]))/2
    res *= h
    return res


def parabola(args: list) -> float:
    """args - это a, b  и количество разбиений"""
    h = (args[1] - args[0]) / args[2]
    i = args[0] + h
    odd = 0
    even = 0
    while i <= args[1] - h:
        odd += func(i)
        i += 2 * h
    i = args[0] + 2 * h
    while i <= args[1] - 2 * h:
        even += func(i)
        i += 2 * h
    res = h / 3 * (func(args[0]) + func(args[1]) + 4 * odd + 2 * even)
    return res


def n_from_h(args):
    """Вспомогательная функция для получения n из h.
    Необходима для более удобного подсчета интеграла.
    Аргументы: a, b, h"""
    return (args[1] - args[0])/args[2]


def double_recount(args_var):
    """args_var - это a, b и точность"""
    h = args_var[2]
    a = args_var[0]
    b = args_var[1]
    res1 = trapeze([a, b, n_from_h([a, b, h])])
    res2 = trapeze([a, b, n_from_h([a, b, h/2])])
    while abs(res2-res1) > args_var[2]:
        h /= 2
        res1 = trapeze([a, b, n_from_h([a, b, h])])
        res2 = trapeze([a, b, n_from_h([a, b, h])])
    return res2


def second_algorithm(args_var):
    h_v = args_var[2]
    h_s = h_v/2
    a = args_var[0]
    b = args_var[1]
    res1 = rectangle_right([a, b, n_from_h([a, b, h_v])])
    res2 = 0
    while abs(res2 - res1) > args_var[2]:
        res1 = rectangle_right([a, b, n_from_h([a, b, h_v])])
        h_v += h_s
        h_d = h_v/2
        res2 = rectangle_right([a, b, n_from_h([a, b, h_d])])
        h_v /= 2
        h_s /= 2
    return res2
