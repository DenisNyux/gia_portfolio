#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n;
  printf("Введите количество углов n, n>2\nn=");
  scanf("%d", &n);
  switch (n) {
  case 3:
    printf("Треугольник\n");
    break;
  case 4:
    printf("Четырехугольник\n");
    break;
  case 5:
    printf("Пятиугольник\n");
    break;
  case 6:
    printf("Шестиугольник\n");
    break;
  default:
    printf("Многоугольник\n");
  }
  return 0;
}
