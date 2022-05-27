#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 11
/*Граница интервала в котором берутся случайные числа */
#define k 41

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
  int array[n], index[n], i;
  srand(time(NULL));
  /*Заполнение массива случайными числами и обнуление массива index*/
  printf("Массив А:\n");
  for (i = 0; i < n; i++) {
    array[i] = rand() % k - k / 2;
    printf("%d ", array[i]);
    index[i] = 0;
  }
  /*Сортировка массива*/
  quickSort(array, 0, n - 1);
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  /*Количество повторений записывается в массив index, переменная t нужна для
   * подсчета повторений*/
  int t = 1;
  for (i = 0; i < n; i++) {
    if (array[i] == array[i + 1])
      t += 1;
    else {
      index[i] = t;
      t = 1;
    }
  }
  /*Вывод количества повторений*/
  int max_index = index[0];
  for (i = 0; i < n; i++) {
    if (index[i] > 1)
      printf("\nЧисло %d повторяется в массиве %d разa\n", array[i], index[i]);
    if (max_index < index[i])
      max_index = index[i];
  }
  if (max_index == 1)
    printf("\nВ массиве нет повторяющихся элементов\n");
  return 0;
}
