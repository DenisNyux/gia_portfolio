#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 11
/*Граница интервала в котором берутся случайные числа */
#define k 41

/*Быстрая сортировка*/
void quickSort(int *array, int first, int last) {
  if (first < last) {
    int left = first, right = last, middle = array[(left + right) / 2];
    do {
      while (array[left] < middle)
        left++;
      while (array[right] > middle)
        right--;
      if (left <= right) {
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;
        left++;
        right--;
      }
    } while (left <= right);
    quickSort(array, first, right);
    quickSort(array, left, last);
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
  quickSort(array, 0, n - 1);
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  if (n % 2 == 0)
    printf("\nВ массиве четное количество элементов\n");
  else
    printf("\nМедиана массива: %d\n", array[n / 2]);
  return 0;
}
