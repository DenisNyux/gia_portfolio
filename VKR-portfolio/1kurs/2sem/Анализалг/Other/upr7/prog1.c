#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10
/*Граница интервала в котором берутся случайные числа */
#define k 41

/*Сортировка прямым обменом*/
void bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = (size - 1); j > i; j--) {
      if (array[j - 1] > array[j]) {
        int temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int array[n], i;
  srand(time(NULL));
  /*Заполнение массива случайными числами*/
  printf("Массив А:\n");
  for (i = 0; i < n; i++) {
    array[i] = rand() % k - k / 2;
    printf("%d ", array[i]);
  }
  /*Отсортируем массив*/
  bubbleSort(array, n);
  /*Контрольный вывод*/
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  printf("\n\nНаибольший элемент: %d\n", array[n - 1]);
  return 0;
}
