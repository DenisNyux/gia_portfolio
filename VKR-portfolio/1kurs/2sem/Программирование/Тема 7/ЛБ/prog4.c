#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a, b; /*a,b - границы интервалв*/
  printf("Введите интервал:");
  scanf("%d %d", &a, &b);
  int t = 0; /*В t будет храниться сумма делителей*/
  for (int i = a; i <= b; i++) {
    for (int j = 1; j < i; j++) {
      if (i % j == 0) {
        t += j;
      }
    }
    if (t == i) {
      printf("%d - совершенное\n", i);
    }
    t = 0;
  }
  return 0;
}
