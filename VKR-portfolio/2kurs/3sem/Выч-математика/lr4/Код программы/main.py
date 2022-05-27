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
    while main_cond != 3:
        main_cond = cond_checker(main_menu)
        if main_cond == 0:
            bisection()
        if main_cond == 1:
            newton()
        if main_cond == 2:
            chord()
        if main_cond == 3:
            pass


main_menu = ('1) Деление отрезка пополам', '2) Метод Ньютона', '3) Метод хорд', '4) Выход')
main()
