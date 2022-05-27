#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Размеры первого и второго массива*/
#define n 3

void printing(int array[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int s[n][n]={1,2,3,4,5,6,7,8,9};
  int k[n][n]={-1,-2,-3,4,-5,6,-7,-8,-9};
  /*Вывод матрицы s*/
  printf("Матрица S:\n" );
  printing(s);
  /*Вывод матрицы k*/
  printf("\nМатрица K:\n" );
  printing(k);
  return 0;
}
