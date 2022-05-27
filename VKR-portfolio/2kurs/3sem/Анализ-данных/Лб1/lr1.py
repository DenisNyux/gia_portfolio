from prettytable import PrettyTable
import math


def table(val, t_a):
    """Вычисления"""
    """"Столбец n"""
    amount_of_counts = []
    for j in range(len(val)):
        amount_of_counts.append(j + 1)
    """"Столбец d-d0"""
    x0 = val[1]
    x_x0 = []
    sum_x_x0 = 0
    for j in range(len(val)):
        x_x0.append(round(val[j]-x0, 5))
        sum_x_x0 += x_x0[j]
    """"Столбец (d-d0)^2"""
    sqr_x_x0 = []
    sum_sqr_x_x0 = 0
    for j in range(len(val)):
        sqr_x_x0.append(round(x_x0[j]*x_x0[j], 5))
        sum_sqr_x_x0 += sqr_x_x0[j]
    """Столбец 'Среднее d'"""
    avr_x = list(' ' * len(val))
    avr_x[0] = round(x0 + (1/len(val)) * sum_x_x0, 5)
    """Столбец 'Средне-квадратичная погрешность'"""
    avr_sqr_x = list(' ' * len(val))
    avr_sqr_x[0] = round((1/(len(val)*(len(val)-1)))*(sum_sqr_x_x0 - len(val)*(avr_x[0]-x0)**2), 7)
    """Столбец 'Стандартное отклонение'"""
    st_dev = list(' ' * len(val))
    st_dev[0] = round(math.sqrt(avr_sqr_x[0]), 7)
    """Столбец 'Абс. погрешность'"""
    abs_dev = list(' ' * len(val))
    abs_dev[0] = round(t_a * st_dev[0], 7)
    """Столбец 'Относительная погрешность'"""
    rel_dev = list(' ' * len(val))
    temp = str(round(abs_dev[0] / avr_x[0] * 100, 5))
    rel_dev[0] = temp + '%'
    """Создание таблицы"""
    t = PrettyTable()
    column_names = ['n', 'x', 'x - x0', '(x - x0)^2', 'Среднее d', 'Средне-квадратичная погрешность',
                    'Стандартное отклонение', 'Абс. погрешность', 'Относительная погрешность']
    t.add_column(column_names[0], amount_of_counts)
    t.add_column(column_names[1], val)
    t.add_column(column_names[2], x_x0)
    t.add_column(column_names[3], sqr_x_x0)
    t.add_column(column_names[4], avr_x)
    t.add_column(column_names[5], avr_sqr_x)
    t.add_column(column_names[6], st_dev)
    t.add_column(column_names[7], abs_dev)
    t.add_column(column_names[8], rel_dev)
    return t


values = []
amount = int(input('Введите количество измерений: '))
print('Введите значения:')
for i in range(amount):
    print(i + 1, ') ', end='')
    values.append(float(input()))
st_k = float(input('Введите коэфицент Стьюдента: '))
print(table(values, st_k))
