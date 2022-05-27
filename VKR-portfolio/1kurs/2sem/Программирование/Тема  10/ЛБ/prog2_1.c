#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*Точность вычисления экспоненты*/
#define accuracy 10

/*Структура комплексного числа*/
struct complex {
  float re;
  float im;
} cm, pow_comp, exp_comp;
/*Функция вычисления факториала*/
float fact(float number) {
  if (number == 0)
    return 1.0;
  else
    return fact(number - 1) * number;
}
/*Функция для отображения значений полей экземпляра структуры*/
void show(struct complex obj) {
  if (obj.im == 0) {
    printf("%2.2f", obj.re);
  } else {
    if (obj.re != 0) {
      printf("%2.2f", obj.re);
      if (obj.im > 0) {
        printf("+");
      }
    }
    printf("%2.2fi", obj.im);
  }
}
/*Функция возведения в степень комплексного числа. Переводим в
 * тригонометрическую форму, а затем считаем по формуле Муавра*/
void comlplex_pow(struct complex cm, float power) {
  float mod = sqrtf(cm.re * cm.re + cm.im * cm.im);
  float arg = atanf(cm.im / cm.re);
  pow_comp.re = powf(mod, power) * cosf(arg * power);
  pow_comp.im = powf(mod, power) * sinf(arg * power);
}
/*Функции вычисления экспоненты*/
void complex_exp(struct complex cm) {
  exp_comp.re = 0;
  exp_comp.im = 0;
  float i = 0;
  while (i < accuracy) {
    comlplex_pow(cm, i);
    exp_comp.re += 1 / fact(i) * pow_comp.re;
    exp_comp.im += 1 / fact(i) * pow_comp.im;
    i += 1.0;
  }
}

int main(int argc, char const *argv[]) {
  // Создание указателя на экземпляр структуры:
  struct complex *cmpoint;
  cmpoint = &cm;
  printf("Введите действетельную и мнимую часть комплексного числа: ");
  scanf("%f %f", &cmpoint->re, &cmpoint->im);
  show(cm);
  printf("\nЭкспонента:\n");
  complex_exp(cm);
  show(exp_comp);
  printf("\n");
  return 0;
}
