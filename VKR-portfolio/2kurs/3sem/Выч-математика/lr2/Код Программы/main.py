# x0 = 0, y0 = 1, a - b = 0-1
from methods import *


def cond_checker(menu: list):
    """
    На вход поступает меню в виде списка.
    Функция выводит меню и возвращает введенное
    пользователем значение.
    """
    for each in menu:
        print(each)
    condition = int(input())
    return condition - 1


def main():
    main_cond = -1
    methods_cond = -1
    while main_cond != 3:
        main_cond = cond_checker(main_menu)
        if main_cond == 0:
            while methods_cond != 2:
                methods_cond = cond_checker(methods_menu)
                if methods_cond == 0:
                    euler(0, 1, 10, 0, 1)
                elif methods_cond == 1:
                    runge_kutt(0, 1, 10, 0, 1)
                elif methods_cond == 2:
                    pass
                else:
                    print('Вы ввели неправильное значение')
        if main_cond == 1:
            high(1, 1.5, 0.1, 0.77, -0.44)
        if main_cond == 2:
            systemUr(1, 1.5, 0.1, 2, 1, 1)
        if main_cond == 3:
            pass
    
    
main_menu = ('1) Решение ДУ', '2) Система ДУ', '3) ДУ 2ого порядка', '4) Выход')
methods_menu = ('1) Метод Эйлера', '2) Метод Рунге-Кутта', '3) Выход')
main()
