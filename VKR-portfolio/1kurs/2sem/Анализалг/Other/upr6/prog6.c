#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10

int main(int argc, char const *argv[]) {
  int array[n], i;
  srand(time(NULL));
  /*Заполнение массива случайными числами*/
  printf("Массив А:\n");
  for (i = 0; i < n; i++) {
    array[i] = rand() % 20;
    printf("%d\n", array[i]);
  }
  /*Первоначальное значение максимального и минимального
  элемента - первый элемент массива*/
  int min = array[0], max = array[0];
  /*Проходим по массиву, сравнивая max и min c элементами массива*/
  for (i = 1; i < n; i++) {
    if (array[i] > max)
      max = array[i];
    if (array[i] < min)
      min = array[i];
  }
  printf("\n%d - минимальный элемент\n%d - максимальный элемент\n", min, max);
  return 0;
}
