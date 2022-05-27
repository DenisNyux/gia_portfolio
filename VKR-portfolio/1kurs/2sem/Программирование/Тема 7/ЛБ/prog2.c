#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  float a, b, h, s;
  printf("Введите стороны фигуры a, b, h:");
  scanf("%f %f %f", &a, &b, &h);
  if (h == 0) {
    s = a * b;
    if (a == b)
      printf("Площадь квадрата: %4.2f\n", s);
    else
      printf("Площадь прямоугольника: %4.2f\n", s);
  } else {
    s = (a + b) / 2 * h;
    printf("Площадь трапеции: %4.2f\n", s);
  }
  return 0;
}
