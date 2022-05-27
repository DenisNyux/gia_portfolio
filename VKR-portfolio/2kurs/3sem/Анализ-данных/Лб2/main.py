import math


def input_random(vals):
    vals_list = list()
    while vals != 0:
        vals_list.append(float(input()))
        vals -= 1
    return vals_list


def characteristics(lst1, lst2):
    xi_pi = [lst1[i]*lst2[i] for i in range(len(lst1))]
    mx = sum(xi_pi)
    xi_mx = [lst1[i]-mx for i in range(len(xi_pi))]
    disp_vals = [(xi_mx[i]**2)*lst2[i] for i in range(len(lst2))]
    disp = sum(disp_vals)
    return mx, disp, math.sqrt(disp)


def readfile(val_am, num):
    x_i = list()
    p_i = list()
    with open('vals{}.txt'.format(num)) as vals_file:
        all = vals_file.readlines()
    for i in range(val_am):
        x_i.append(float(all[i].rstrip()))
        p_i.append(float(all[i+val_am+1].rstrip()))
    return x_i, p_i



def main():
    print('1) Ввести значения самостоятельно', '2) Значения из первой задачи', 
          '3) Значения из второй задачи', '4) Значения из третьей задачи', 
          '5) Значения из четвертой задачи', sep='\n')
    cond = input()
    if cond == '1':
        x_vals = int(input('Введите кол-во значения случайной величины (xi) и вероятностей (pi): '))
        print('Введите xi')
        x_i = input_random(x_vals)
        print('Введите pi')
        p_i = input_random(x_vals)
        result = characteristics(x_i, p_i)
    elif cond == '2':
        val_am = 11
        vals = readfile(val_am, 1)
        result = characteristics(*vals)
    elif cond == '3':
        val_am = 4
        vals = readfile(val_am, 2)
        result = characteristics(*vals)
    elif cond == '4':
        val_am = 5
        vals = readfile(val_am, 3)
        result = characteristics(*vals)
    elif cond == '5':
        val_am = 6
        vals = readfile(val_am, 4)
        result = characteristics(*vals)
    print('\nМатематическое ожидание: {0}\nДисперсия: {1}\nСреднеквадратическое ожидание: {2}'.format(*result))


main()
