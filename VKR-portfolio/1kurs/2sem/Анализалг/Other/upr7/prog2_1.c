#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10
/*Граница интервала в котором берутся случайные числа */
#define k 21

int main(int argc, char const *argv[]) {
  int array[n], i, index[k], sorted_array[n];
  srand(time(NULL));
  /*Заполнение массива случайными числами*/
  printf("Массив А:\n");
  for (i = 0; i < n; i++) {
    array[i] = rand() % k;
    printf("%d ", array[i]);
  }
  for (i = 0; i < k; i++) {
    index[i] = 0;
  }
  for (i = 0; i < n; i++) {
    index[array[i]] += 1;
  }
  int b = 0;
  for (i = 0; i < k; i++) {
    for (int j = 0; j < index[i]; j++){
      sorted_array[b] = i;
      b++;
    }
  }
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", sorted_array[i]);
  }
  return 0;
}
