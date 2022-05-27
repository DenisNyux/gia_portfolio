#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int *f; // указатель на массив
  int i, n = 12;
  float t, r = 0, q, s = 1;
  // Выделение памяти
  f = (int *)malloc(n * sizeof(int));
  // Заполнение массива случайными числами
  for (i = 0; i < n; i++) {
    f[i] = rand() % 100 - 50;
    if (f[i] <= 0) {
      r += f[i];
      q = f[i];
    } else {
      s *= f[i];
    }
  }
  // Вывод элементов массива
  for (i = 0; i < n; i++)
    printf("%d ", f[i]);
  printf("\n");
  t = (r + q + s) / (r * q * s + 2);
  printf("t=%f\n", t);
  free(f);
  return 0;
}
