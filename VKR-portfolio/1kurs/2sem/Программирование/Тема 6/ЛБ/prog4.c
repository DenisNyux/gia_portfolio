#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int **a;
  int i, j, n, m, k;
  printf("Введите количество строк и столбцов: ");
  scanf("%d %d", &m, &n);
  /*Выделение памяти на строки*/
  a = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    /*Выделение памяти на столбцы и заполнение массива случайными числами*/
    a[i] = (int *)malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      a[i][j] = rand() % 50 - 25;
    }
  }

  /*Вывод массива*/
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("Введите номер строки, которую необходимо удалить:");
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    a[k - 1][i] = 0;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  /*Очистка памяти*/
  for (i = 0; i < m; i++)
    free(a[i]);
  free(a);
  return 0;
}
