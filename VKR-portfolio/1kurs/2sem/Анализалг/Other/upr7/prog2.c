#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10
/*Граница интервала в котором берутся случайные числа */
#define k 41

/*Сортировка вставками*/
void insertionSort(int *array, int size) {
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
  insertionSort(array, n);
  /*Контрольный вывод*/
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  /*Предотвращение ошибки, возникающей если в массиве несколько одинаковых
   * минимальных элементов*/
  int almostmin;
  if (array[0] == array[1]) {
    int t = 0;
    while (array[t] == array[t + 1])
      t += 1;
    almostmin = array[t + 1];
  } else
    almostmin = array[1];
  /*Вывод ближайшего к минимальному*/
  printf("\n\nБлижайший к минимальному элемент: %d\n", almostmin);
  return 0;
}
