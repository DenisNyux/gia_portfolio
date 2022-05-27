#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество строк*/
#define n 4
/*Количество столбцов*/
#define m 5
/*Верхняя граница диапазона случайных чисел*/
#define max_range 100

/*Функция заполения массива случайными числами*/
void filling(int array[n][m]) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      array[i][j] = rand() % max_range;
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
/*Функция нахождения минимального элемента в строке*/
int min_of_string(int array[n][m], int i) {
  int min = array[i][0];
  for (int j = 0; j < m; j++)
    if (min > array[i][j])
      min = array[i][j];
  return min;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int f[n][m];
  filling(f);
  printf("F:\n");
  printing(f);
  for (int i = 0; i < n; i++)
    printf("\nМинимальный элемент %d - ой строки: %d\n", i + 1,
           min_of_string(f, i));
  return 0;
}
