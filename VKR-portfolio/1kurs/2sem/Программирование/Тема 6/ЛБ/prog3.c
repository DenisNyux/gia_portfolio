#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /*Объявление динамических массивов размерностью n*/
  int *a, *b, *c;
  int n = 12, i, k = 0, j;
  ;
  a = (int *)malloc(n * sizeof(int));
  b = (int *)malloc(n * sizeof(int));
  c = (int *)malloc(n * sizeof(int));
  /*Заполнение массивов элементами последовательности*/
  a[0] = 1;
  a[1] = 1;
  b[0] = 1;
  b[1] = 1;
  b[2] = 1;
  for (i = 2; i < n; i++)
    a[i] = a[i - 1] + a[i - 2];
  for (i = 3; i < n; i++)
    b[i] = b[i - 2] + b[i - 3];
  printf("\nПервое множество:\n");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\nВторое множество:\n");
  for (i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n");
  /*Находим совпадающие*/
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i] == b[j] & c[k - 1] != b[j]) {
        c[k] = a[i];
        k++;
      }
    }
  }
  printf("\nПересечение двух множеств:\n");
  for (i = 0; i < k; i++)
    printf("%d ", c[i]);
  printf("\n");
  free(a);
  free(b);
  free(c);
  return 0;
}
