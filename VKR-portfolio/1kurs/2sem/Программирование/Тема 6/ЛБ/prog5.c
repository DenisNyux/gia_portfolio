#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int **mas;
  int i, j, n, m;
  printf("Введите количество строк и столбцов матрицы M: ");
  scanf("%d %d", &n, &m);
  /*Выделение памяти на строки*/
  mas = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    /*Выделение памяти на столбцы и заполнение матрицы случайными числами*/
    mas[i] = (int *)malloc(m * sizeof(int));
    for (j = 0; j < m; j++) {
      mas[i][j] = rand() % 50 - 25;
    }
  }

  int **a;
  int na = n, ma = 1;
  /*Выделение памяти на строки*/
  a = (int **)malloc(na * sizeof(int *));
  for (i = 0; i < na; i++) {
    /*Выделение памяти на столбцы и заполнение матрицы случайными числами*/
    a[i] = (int *)malloc(ma * sizeof(int));
    for (j = 0; j < ma; j++) {
      a[i][j] = rand() % 50 - 25;
    }
  }
  printf("\nМатрица М:\n");
  /*Вывод массива M*/
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", mas[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  /*Вывод вектора a*/
  printf("Вектор a:\n");
  for (i = 0; i < na; i++) {
    for (j = 0; j < ma; j++) {
      printf("%d\n", a[i][j]);
    }
  }
  /*Умножение матрицы на вектор*/
  int **b;
  int nb = n, mb = ma, k;
  b = (int **)malloc(nb * sizeof(int *));
  for (i = 0; i < nb; i++) {
    b[i] = (int *)malloc(mb * sizeof(int));
    for (j = 0; j < mb; j++) {
      b[i][j] = 0;
      for (k = 0; k < m; k++) {
        b[i][j] += mas[i][j] * a[i][j];
      }
    }
  }
  /*Вывод вектора b*/
  printf("\nВектор b:\n");
  for (i = 0; i < nb; i++) {
    for (j = 0; j < mb; j++) {
      printf("%d\n", b[i][j]);
    }
  }

  return 0;
}
