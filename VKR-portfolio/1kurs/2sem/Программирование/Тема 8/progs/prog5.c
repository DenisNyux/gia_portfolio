#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество строк*/
#define n 6
/*Количество столбцов*/
#define m 5
/*Верхняя граница диапазона случайных чисел*/
#define max_range 100

/*Функция заполения массива случайными числами*/
void filling(int array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      array[i][j] = rand() % max_range - max_range / 2;
    }
  }
}
/*Функция вывода матрицы*/
void printing(int array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}
/*Функция нахождения суммы минимальных неотрицательных элементов*/
int sum_of_strings(int array[n][m], int i) {
  int sum = 0;
  for (int j = 0; j < m; j++)
    if (array[i][j] > 0)
      sum += array[i][j];
  return sum;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int d[n][m];
  filling(d);
  printf("D:\n");
  printing(d);
  int minimal_sum = sum_of_strings(d, 0);
  for (int i = 1; i < n; i++)
    if (minimal_sum > sum_of_strings(d, i))
      minimal_sum = sum_of_strings(d, i);
  printf("\nНаименьшая из сумм неотрицательных элементов строки: %d\n",
         minimal_sum);
  return 0;
}
