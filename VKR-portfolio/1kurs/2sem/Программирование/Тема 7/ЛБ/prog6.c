#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*Функция находит наименьшее число среди 3*/
float lowest(float a, float b, float c) {
  if ((a <= b) && (b <= c)) {
    return a;
  } else if ((b <= a) && (b <= c)) {
    return b;
  } else if ((c <= a) && (c <= b)) {
    return c;
  }
}
/*Функция находит косинус наибольшего угла*/
float cosinus(float a, float b, float c) {
  float cos1, cos2, cos3;
  cos1 = (a * a + b * b - c * c) / (2 * a * b);
  cos2 = (c * c + a * a - b * b) / (2 * c * a);
  cos3 = (c * c + b * b - a * a) / (2 * c * b);
  return lowest(cos1, cos2, cos3);
}

float main(int argc, char const *argv[]) {
  float a, b, c;
  printf("Введите 3 стороны треугольника:\n");
  printf("a=");
  scanf("%f", &a);
  printf("b=");
  scanf("%f", &b);
  printf("c=");
  scanf("%f", &c);
  /*
  printf("%f\n", lowest(a, b, c));
  printf("%f\n", cosinus(a, b, c));
  */
  /*Если косинус наибольшего угла равен 0 - треугольник прямоугольный,
  если косинус больше 0 - остроугольный, если меньше 0 - тупоугольный*/
  if ((a < b + c) && (b < a + c) && (c < a + b)) {
    printf("Треугольник с такими сторонами существует.");
    if (cosinus(a, b, c) > 0) {
      printf(" Он остроугольный\n");
    }
    if (cosinus(a, b, c) == 0) {
      printf(" Он прямоугольный\n");
    }
    if (cosinus(a, b, c) < 0) {
      printf(" Он тупоугольный\n");
    }
  } else {
    printf("Такого треугольника не существует\n");
  }
  return 0;
}
