#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Размер первого и второго массива*/
#define n 8
/*Верхняя граница диапазона случайных чисел*/
#define max_range 100

/*Функция заполения массива случайными числами*/
void filling(int *array, int amount_of_elements) {
  for (int i = 0; i < amount_of_elements; i++) {
    array[i] = rand() % max_range;
  }
}
/*Функция нахождения суммы максимума двух массивов одного размера*/
int sum_of_max(int *array1, int *array2, int amount_of_elements) {
  int max1 = array1[0], max2 = array2[0];
  for (int i = 0; i < amount_of_elements; i++) {
    if (max1 < array1[i])
      max1 = array1[i];
    if (max2 < array2[i])
      max2 = array2[i];
  }
  return max1 + max2;
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int a[n], b[n];
  /*Заполнение массивов случайными числами*/
  filling(a, n);
  filling(b, n);
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\n", a[i], b[i]);
  }
  printf("Сумма максимальных элементов - %d\n", sum_of_max(a, b, n));
  return 0;
}
