#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество элементов в массиве*/
#define n 10
/*Граница интервала в котором берутся случайные числа*/
#define k 21

/*Функция сравнения, необходимая для qsort*/
int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
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
  qsort(array, n, sizeof(int), cmp);
  /*Контрольный вывод*/
  printf("\n\nОтсортированный массив:\n");
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);
  /*Переменная будет показывать, есть ли необходимый нам элемент в массиве*/
  int flag = 0;
  /*Находим необходимый элемент линейным поиском*/
  for (i = 0; i < n; i++) {
    if (array[i] == i) {
      int flag = 1;
      break;
    }
  }
  if (flag == 1)
    printf("\n\nВ массиве есть элемент a[i]=i\n");
  else
    printf("\n\nВ массиве нет элемента a[i]=i\n");
  return 0;
}
