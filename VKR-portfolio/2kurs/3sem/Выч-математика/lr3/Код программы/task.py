import math

# Функции для подсчета значений для арктангенса и логарифма
s1 = lambda x, n: (-1) ** (n + 1) * x ** n / n
s2 = lambda x, n: (-1)**n * x**(2 * n + 1) / (2 * n + 1)
# Значения для решения по методу Чнбышева
vals_for_exp = [0.9999998, 1.000000, 0.5000063, 0.1666674, 0.0416350, 0.0083298, 0.0014393, 0.0002040]
vals_for_sin = [1.000000002, -0.166666589, 0.08333075, -0.000198107, 0.000002608]


def homemade_exp(x, acc=7):
    res = 0
    for i in range(acc):
        res += vals_for_exp[i] * x ** i
    return res


def homemade_sin(x, acc=9):
    res = 0
    for i in range(len(vals_for_sin)):
        res += vals_for_sin[i] * x**(i*2+1)
    return res


def homemade_ln_plus_1(x, acc):
    n = 1
    res1 = 0
    res2 = s1(x, n)
    while abs(res2 - res1) >= acc:
        res1 = res2
        n += 1
        res2 += s1(x, n)
    return res2


def homemade_arctg(x, acc):
    n = 1
    res1 = 0
    res2 = x - s2(x, n)
    while abs(res2 - res1) >= acc:
        res1 = res2
        n += 1
        res2 += s2(x, n)
    return res2


def main():
    x = 0.5
    y = math.pi / 6
    print('x = {}\nexp(x) ='.format(x), homemade_exp(x))
    print('ln(x+1) =', homemade_ln_plus_1(x, 0.00001))
    print('\ny = {}\narctg(y) ='.format('pi/6'), homemade_arctg(y, 0.00001))
    print('sin(y) =', homemade_sin(y))


main()
