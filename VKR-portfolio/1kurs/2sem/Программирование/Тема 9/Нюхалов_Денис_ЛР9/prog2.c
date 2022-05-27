#include <stdio.h>
#include <stdlib.h>

int fib(int number) {
  if ((number == 1) || (number == 2)) {
    return 1;
  }
  return fib(number - 1) + fib(number - 2);
}

int main(int argc, char const *argv[]) {
  int n;
  printf("Сколько чисел Фибоначчи нужно вычислить?\n");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    printf("%d ", fib(i));
  printf("\n");
  return 0;
}
