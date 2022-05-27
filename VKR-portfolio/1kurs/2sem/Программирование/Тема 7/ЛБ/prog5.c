#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i, t, sum;
  for (i = 10; i < 100; i++) {
    sum = 0;
    t = i;
    while (i != 0) {
      sum += i % 10;
      i = i / 10;
    }
    i = t;
    if (i % sum == 0)
      printf("%d делится на сумму своих цифр\n", i);
  }
  return 0;
}
