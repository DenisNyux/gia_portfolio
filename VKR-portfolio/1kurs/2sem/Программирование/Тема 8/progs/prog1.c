#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Размер первого массива*/
#define n 6
/*Размер второго массива*/
#define k 8
/*Размер третьго массива*/
#define g 7
/*Нижняя граница диапазона случайных чисел*/
#define min_range -1000
/*Верхняя граница диапазона случайных чисел*/
#define max_range 1000

/*Функция заполения массива случайными числами*/
void filling(double *array, int amount_of_elements) {
  srand(time(NULL));
  for (int i = 0; i < amount_of_elements; i++) {
    array[i] = (double)(rand() % (max_range - min_range + 1)) / 100 - 10;
  }
}

/*Функция нахождение суммы положительных элементов*/
double sum_of_positive(double *array, int amount_of_elements) {
  double sum = 0;
  int i;
  for (i = 0; i < amount_of_elements; i++) {
    if (array[i] >= 0)
      sum += array[i];
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  double a[n], b[k], c[g];
  int i;
  /*Заполнение массивов случайными вещественными числами*/
  filling(a, n);
  filling(b, k);
  filling(c, g);
  /*Нахождение сум всех положительных элементов*/
  double sums =
      sum_of_positive(a, n) + sum_of_positive(b, k) + sum_of_positive(c, g);
  printf("Сумма всех положительных элементов: %2.2f\n", sums);
  return 0;
}
