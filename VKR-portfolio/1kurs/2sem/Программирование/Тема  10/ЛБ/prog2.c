#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define accuracy 5

/*Структура комплексного числа*/
struct complex {
  float re;
  float im;
} cm, exp_comp;
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
void comlplex_pow(struct complex *cmpoint, float power) {
  float mod = sqrtf(cmpoint->re * cmpoint->re + cmpoint->im * cmpoint->im);
  float arg = atanf(cmpoint->im / cmpoint->re);
  cmpoint->re = powf(mod, power) * cosf(arg * power);
  cmpoint->im = powf(mod, power) * sinf(arg * power);
}

void complex_exp(struct complex *cmpoint) {
  struct complex *exp_comp_point;
  exp_comp_point = &exp_comp;
  float i = 1.0;
  exp_comp_point->re = 1;
  exp_comp_point->im = 1;
  while (i < accuracy) {
    comlplex_pow(cmpoint, i);
    exp_comp_point->re += 1.0 / fact(i) * cmpoint->re;
    exp_comp_point->im += 1.0 / fact(i) * cmpoint->im;
    i += 1.0;
  }
  show(exp_comp);
}

int main(int argc, char const *argv[]) {
  // Создание указателя на экземпляр структуры:
  struct complex *cmpoint;
  cmpoint = &cm;
  printf("Введите действетельную и мнимую часть комплексного числа: ");
  scanf("%f %f", &cmpoint->re, &cmpoint->im);
  show(cm);
  printf("\n");
  comlplex_pow(cmpoint, 2.0);
  show(cm);
  comlplex_pow(cmpoint, 0.5);
  printf("\n");
  complex_exp(cmpoint);
  return 0;
}
