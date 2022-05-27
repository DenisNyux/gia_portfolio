import math

a = -10
b = 10
acc = 10e-6


def func(x):
    return x ** 4 - 18 * x ** 2 + 6


def func_diff(x):
    return 4 * x * (x ** 2 - 9)


def newton():
    x_prev = a
    x_curr = x_prev - func(x_prev) / func_diff(x_prev)
    while abs(x_curr - x_prev) >= acc:
        x_prev = x_curr
        x_curr = x_prev - func(x_prev) / func_diff(x_prev)
    print('x =', x_curr)


def bisection():
    x_prev = a
    x_curr = b
    if abs(x_curr) == abs(x_prev):
        x_curr += a/2
    x = (x_prev + x_curr) / 2
    while abs(func(x)) > acc:
        x = (x_prev + x_curr) / 2
        if func(x_prev) * func(x) < 0:
            x_prev, x_curr = x_prev, x
        else:
            x_prev, x_curr = x, x_curr
    print('x =', (x_prev + x_curr) / 2)


def chord():
    x_prev = a
    x_curr = b
    if abs(x_prev) == abs(x_curr):
        x_curr += a/2
    while abs(x_curr - x_prev) >= acc:
        x = x_curr - ((x_curr - x_prev) * func(x_curr)) / (func(x_curr) - func(x_prev))
        x_prev = x_curr
        x_curr = x
    print('x =', x_curr)
