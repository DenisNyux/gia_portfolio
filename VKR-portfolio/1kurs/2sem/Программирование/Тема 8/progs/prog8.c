#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prime_number(int number) {
  int primeness = 0;
  for (int i = 2; i < number; i++)
    if (number % i == 0)
      primeness = 1;
  return primeness;
}

int main(int argc, char const *argv[]) {
  int number;
  printf("Введите чило: ");
  scanf("%d", &number);
  if (prime_number(number) == 0)
    printf("\nЧисло %d - простое\n", number);
  else
    printf("\nЧисло %d не является простым\n", number);
  return 0;
}
