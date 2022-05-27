#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Количество строк*/
#define n 3
/*Количество столбцов*/
#define m 4
/*Верхняя граница диапазона случайных чисел*/
#define max_range 20

/*Функция заполения массива случайными числами*/
void filling(int array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      array[i][j] = rand() % max_range;
    }
  }
}
/*Функция вывода матрицы*/
void printing(int array[n][m]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}
/*Структура, содержащая указатель на функцию*/
struct fnpointer {
  void (*pointer)(int array[n][m]);
} fnp;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int d[n][m];
  fnp.pointer = filling;
  fnp.pointer(d);
  fnp.pointer = printing;
  printf("D:\n");
  fnp.pointer(d);
  return 0;
}
