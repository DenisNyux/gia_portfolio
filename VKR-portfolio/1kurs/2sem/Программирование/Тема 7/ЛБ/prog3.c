#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int x;
  printf("Введите цифру: ");
  scanf("%d", &x);
  if (x == 0)
    printf("%d принадлежит любой системе счисления\n", x);
  else
    printf("Число %d принадлежит %d - ой системе счисления и выше\n", x, x + 1);
  return 0;
}
