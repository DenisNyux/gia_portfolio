#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Размер массива*/
#define n 8
/*Верхняя граница диапазона случайных чисел*/
#define max_range 20

/*Функция заполения массива случайными числами*/
void filling(int *array, int amount_of_elements) {
  for (int i = 0; i < amount_of_elements; i++) {
    array[i] = rand() % max_range;
  }
}
/*Функция нахождения суммы элементов массива*/
int sum(int *array, int element) {
  if (element == 0) // Кол-во элементов равно 0
    return 0;
  else
    return sum(array, element - 1) + array[element - 1];
}

int main(int argc, char const *argv[]) {
  int a[n];
  filling(a, n);
  printf("Массив А:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n%d - сумма элементов\n", sum(a, n));

  return 0;
}
