#include <math.h>
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
  for (int i = 0; i < amount_of_elements; i++) {
    array[i] = (double)(rand() % (max_range - min_range + 1)) / 100;
  }
}
/*Функция нахождения среднего геометрического*/
double geometric_mean(double *array, int amount_of_elements) {
  double product = 1, mean;
  for (int i = 0; i < amount_of_elements; i++)
    product *= array[i];
  mean = pow(product, 1.0 / amount_of_elements);
  return mean;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  double a[n], b[k], c[g];
  int i;
  /*Заполнение массивов случайными вещественными числами*/
  filling(a, n);
  filling(b, k);
  filling(c, g);
  printf("Массивы:\nA:\tB:\tC:\n");
  printf("%2.2f\t%2.2f\t%2.2f\n", geometric_mean(a, n), geometric_mean(b, k),
         geometric_mean(c, g));
  return 0;
}
