#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
/*Верхняя граница диапазона случайных чисел*/
#define max_range 100

void generation_of_matrix(int n, int m) {
  int *a;
  int i, j;
  a = (int *)malloc(n * m * sizeof(int));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      *(a + i * m + j) = rand() % max_range;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%5d ", *(a + i * m + j));
    }
    printf("\n");
  }
  free(a);
}

int main(int argc, char const *argv[]) {
  int n, m;
  printf("Введите количество строк: ");
  scanf("%d", &n);
  printf("Введите количество столбцов: ");
  scanf("%d", &m);
  generation_of_matrix(n, m);
  return 0;
}
