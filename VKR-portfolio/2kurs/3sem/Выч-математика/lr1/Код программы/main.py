from integral_table import *
from entering import *
from double_integral import *


def cond_checker(menu: dict) -> int:
    """
    На вход поступает меню в виде словаря.
    Функция выводит меню и возвращает введенное
    пользователем значение.
    """
    for i in sorted(menu.keys()):
        print(i)
    cond = int(input())
    return cond


def main():
    cond_main = 0
    while cond_main != main_menu['5) Выход']:
        cond_main = cond_checker(main_menu)
        arguments = list()
        if cond_main == main_menu['1) Методы с постоянным шагом']:
            cond_const = 0
            while cond_const != menu_constant['5) Выход']:
                cond_const = cond_checker(menu_constant)
                if (cond_const > 0) & (cond_const < 5):
                    arguments = input_const()
                if cond_const == 1:
                    print('\nРезультат вычисления: ', rectangle_left(arguments), ' Остаточный член:',
                          r_rectangle(arguments), '\n')
                elif cond_const == 2:
                    print('\nРезультат вычисления: ', rectangle_right(arguments), ' Остаточный член:',
                          r_rectangle(arguments), '\n')
                elif cond_const == 3:
                    print('\nРезультат вычисления: ', trapeze(arguments), ' Остаточный член:',
                          r_trapeze(arguments), '\n')
                elif cond_const == 4:
                    print('\nРезультат вычисления: ', parabola(arguments), ' Остаточный член:',
                          r_parabola(arguments), '\n')
                elif cond_const == 5:
                    pass
                else:
                    print('Ошибка, введите другое значение')
        elif cond_main == main_menu['2) Методы с переменным шагом']:
            cond_var = 0
            while cond_var != menu_var['3) Выход']:
                cond_var = cond_checker(menu_var)
                if (cond_var > 0) & (cond_var < 3):
                    arguments = input_var()
                if cond_var == 1:
                    print('\nРезультат вычисления: ', double_recount(arguments), '\n')
                elif cond_var == 2:
                    print('\nРезультат вычисления: ', second_algorithm(arguments), '\n')
                elif cond_var == 3:
                    pass
                else:
                    pass
        elif cond_main == main_menu['3) Таблица']:
            arguments = input_table()
            print('\n', table(arguments), '\n')
        elif cond_main == main_menu['4) Двойной интеграл']:
            args = input_double()
            print('\nРезультат вычисления:', rectangular_double(args), '\n')
        elif cond_main == main_menu['5) Выход']:
            pass
        else:
            print('Ошибка, введите другое значение')


main_menu = {'1) Методы с постоянным шагом': 1,
             '2) Методы с переменным шагом': 2,
             '3) Таблица': 3,
             '4) Двойной интеграл': 4,
             '5) Выход': 5}
menu_constant = {'1) Метод правых частей прямоугольников': 1,
                 '2) Метод левых частей прямоугольников': 2,
                 '3) Метод трапеций': 3,
                 '4) Метод парабол': 4,
                 '5) Выход': 5}
menu_var = {'1) Метод по первому алгоритму': 1,
            '2) Метод по второму алгоритму': 2,
            '3) Выход': 3}

main()
