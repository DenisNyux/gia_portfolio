#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество строк*/
#define n 3
/*Количество столбцов*/
#define m 5
/*Нижняя граница диапазона случайных чисел*/
#define min_range -1000
/*Верхняя граница диапазона случайных чисел*/
#define max_range 1000

/*Функция заполения массива случайными числами*/
void filling(double array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      array[i][j] = (double)(rand() % (max_range - min_range + 1)) / 100;
    }
  }
}
/*Функция вывода матрицы*/
void printing(double array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%2.2f ", array[i][j]);
    }
    printf("\n");
  }
}
/*Функция нахождения среднего геометрического для каждой строки*/
double geometric_mean(double array[n][m], int i) {
  double product = 1, mean;
  for (int j = 0; j < m; j++)
    product *= array[i][j];
  mean = pow(product, 1.0 / n);
  return mean;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  double d[n][m];
  filling(d);
  printf("D:\n");
  printing(d);
  for (int i = 0; i < n; i++)
    printf("\nСреднее геометрическое %d - ой строки: %f\n", i + 1,
           geometric_mean(d, i));
  return 0;
}
