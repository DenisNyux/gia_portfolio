#include <stdio.h>
#include <stdlib.h>

int C(int m, int n) {
  if (m == 0 || m == n)
    return 1;
  else
    return C(m, n - 1) + C(m - 1, n - 1);
}

int main(int argc, char const *argv[]) {
  int n, m;
  printf("Введите числа m и n, 0 <= m <= n:\n");
  scanf("%d %d", &m, &n);
  printf("Биноминальный коэфицент: %d\n", C(m, n));
  return 0;
}
