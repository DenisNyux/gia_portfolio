#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int *a; // указатель на массив
  int i, n = 12, s = 0, t = 0, u = 0, y, k = 0;
  // Выделение памяти
  a = (int *)malloc(n * sizeof(int));
  // Заполнение массива случайными числами
  for (i = 0; i < n; i++) {
    a[i] = rand() % 100 - 60;
    if (i % 2 != 0)
      s++;
    if (abs(a[i]) > t) {
      //Переменная k позволяет сохранить "знак" наибольшего по модулю числа
      k = (a[i] < 0) ? 1 : 0;
      t = abs(a[i]);
    }
    if (a[i] < 0)
      u += a[i];
  }
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  if (k != 0)
    t = -t;
  printf("\n");
  printf("s=%d\n", s);
  printf("t=%d\n", t);
  printf("u=%d\n", u);
  printf("\n");
  y = (u + t) * (s + 2);
  printf("y=%d\n", y);
  return 0;
}
