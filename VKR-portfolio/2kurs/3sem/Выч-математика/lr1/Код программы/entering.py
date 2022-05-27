def input_const():
    """
    Функция для форматированного ввода параметров,
    необходимых при вычислении интеграла методами
    с постоянным шагом
    """
    print('Введите границы интегрирования и шаг:\na = ', end='')
    a = float(input())
    print('b = ', end='')
    b = float(input())
    print('n = ', end='')
    n = float(input())
    res = [a, b, n]
    return res


def input_var():
    """
    Функция для форматированного ввода параметров,
    необходимых при вычислении интеграла методами
    с переменным шагом
    """
    print('Введите границы интегрирования и точность:\na = ', end='')
    a = float(input())
    print('b = ', end='')
    b = float(input())
    print('ε = ', end='')
    e = float(input())
    res = [a, b, e]
    return res


def input_table():
    """
    Функция для форматированного ввода параметров,
    необходимых для составления таблицы
    """
    print('Введите границы интегрирования, шаг и точность:\na = ', end='')
    a = float(input())
    print('b = ', end='')
    b = float(input())
    print('n = ', end='')
    n = float(input())
    print('ε = ', end='')
    e = float(input())
    res = [a, b, n, e]
    return res


def input_double():
    """
    Функция для форматированного ввода параметров,
    необходимых для вычисления двойного интеграла
    """
    res = [i*0 for i in range(6)]
    print('Введите границы интегрирования и шаг для первого интеграла:\na = ', end='')
    res[0] = float(input())
    print('b = ', end='')
    res[1] = float(input())
    print('n1 = ', end='')
    res[4] = int(input())
    print('Введите границы интегрирования и шаг для второго интеграла:\nc = ', end='')
    res[2] = float(input())
    print('d = ', end='')
    res[3] = float(input())
    print('n2 = ', end='')
    res[5] = int(input())
    return res
