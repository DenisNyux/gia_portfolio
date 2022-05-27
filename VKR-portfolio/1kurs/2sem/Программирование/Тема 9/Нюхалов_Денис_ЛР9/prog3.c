#include <stdio.h>
#include <stdlib.h>

int amount(int number) {
  if (number < 10)
    return 1;
  else
    return amount(number / 10) + 1;
}

int main(int argc, char const *argv[]) {
  int n;
  printf("Введите число:\n");
  scanf("%d", &n);
  printf("В числе %d %d цифр\n", n, amount(n));
  return 0;
}
