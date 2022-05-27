#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int **mas;
  int i, j, n;
  printf("Введите количество строк и столбцов квадратной матрицы:");
  scanf("%d", &n);
  /*Выделение памяти на строки*/
  mas = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    /*Выделение памяти на столбцы и заполнение матрицы случайными числами*/
    mas[i] = (int *)malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      mas[i][j] = ((i + j) % 2 == 0) ? 0 : 1;
    }
  }
  /*Вывод массива*/
  printf("\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", mas[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
