#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10
/*Граница интервала в котором берутся случайные числа */
#define k 41

/*Сортировка вставками по возрастанию*/
void increasing_insertionSort(int *array, int size) {
  int newElement, location;
  for (int i = 1; i < n; i++) {
    newElement = array[i];
    location = i - 1;
    while (location >= 0 && array[location] > newElement) {
      array[location + 1] = array[location];
      location = location - 1;
    }
    array[location + 1] = newElement;
  }
}
/*Сортировка вставками по убыванию*/
void decreasing_insertionSort(int *array, int size) {
  int newElement, location;
  for (int i = 1; i < n; i++) {
    newElement = array[i];
    location = i - 1;
    while (location >= 0 && array[location] < newElement) {
      array[location + 1] = array[location];
      location = location - 1;
    }
    array[location + 1] = newElement;
  }
}
/*Проверка на то как отсортирован массив*/
int checking(int *array, int size) {
  int result, closest;
  /*Предотвращение ошибки, возникающей если в массиве несколько одинаковых
   * минимальных элементов*/
  if (array[0] == array[1]) {
    int t = 0;
    while (array[t] == array[t + 1])
      t += 1;
    closest = array[t + 1];
  } else
    closest = array[1];
  if (array[0] > closest)
    result = 1;
  else if (array[0] < closest)
    result = 0;
  return result;
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
  /*Выбор сортировки*/
  printf("\nКак отсортировать массив?\n1)По убыванию\n2)По возрастанию\n");
  int flag;
  scanf("%d", &flag);
  if (flag == 1) {
    decreasing_insertionSort(array, n);
  } else
    increasing_insertionSort(array, n);
  /*Отсортируем массив*/
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  /*Проверка сортировки*/
  if (checking(array, n) == 1)
    printf("\n\nМассив отсортирован по убыванию\n");
  else
    printf("\n\nМассив отсортирован по возрастанию\n");
  return 0;
}
