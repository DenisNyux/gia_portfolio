from prettytable import PrettyTable
from formulas import *
from rcounting import *


def table(args):
    """
    Выводит таблицу с результатом подсчета интеграла всеми методами.
    """
    left_parts = [str(round(rectangle_left([args[0], args[1], args[2]]), 5)) + ', R = ' + str(round(r_rectangle(
        [args[0], args[1], args[2]]), 8))]
    right_parts = [str(round(rectangle_right([args[0], args[1], args[2]]), 5)) + ', R = ' + str(round(r_rectangle(
        [args[0], args[1], args[2]]), 8))]
    trap = [str(round(trapeze([args[0], args[1], args[2]]), 5)) +
            ', R = ' + str(round(r_trapeze([args[0], args[1], args[2]]), 8))]
    par = [str(round(parabola([args[0], args[1], args[2]]), 5)) +
           ', R = ' + str(round(r_parabola([args[0], args[1], args[2]]), 8))]
    first = [str(round(double_recount([args[0], args[1], args[3]]), 5))]
    sec = [str(round(second_algorithm([args[0], args[1], args[3]]), 5))]
    t = PrettyTable()
    column_names = ['Прямоугольник левых частей ', 'Прямоугольник правых частей', 'Трапеция', 'Парабола',
                    'Первый алгоритм', 'Второй алгоритм']
    t.add_column(column_names[0], left_parts)
    t.add_column(column_names[1], right_parts)
    t.add_column(column_names[2], trap)
    t.add_column(column_names[3], par)
    t.add_column(column_names[4], first)
    t.add_column(column_names[5], sec)
    return t
