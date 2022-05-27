#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n;
  float r, s, h;
  printf("Что будем искать?\n1)Площадь круга\n2)Объем шара\n3)Объем "
         "цилиндра\n4)Площадь поверхности сферы\n");
  scanf("%d", &n);
  if (n < 5 && n > 0) {
    printf("Введите радиус\nr=", r);
    scanf("%f", &r);
  }
  switch (n) {
  case 1:
    s = M_PI * r * r;
    break;
  case 2:
    s = 4 / 3 * M_PI * r * r * r;
    break;
  case 3:
    printf("Введите высоту циллиндра\nh=");
    scanf("%f", &h);
    s = M_PI * r * r * h;
    break;
  case 4:
    s = 4 * M_PI * r * r;
    break;
  default:
    printf("Ошибка\n");
  }
  printf("s=%f\n", s);
  return 0;
}
