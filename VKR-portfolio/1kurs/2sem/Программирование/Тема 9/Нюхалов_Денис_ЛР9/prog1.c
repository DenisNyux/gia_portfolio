#include <stdio.h>
#include <stdlib.h>

int fact(int number) {
  if (number == 0)
    return 1;
  else
    return fact(number - 1) * number;
}

int main(int argc, char const *argv[]) {
  int n;
  printf("Факториал какого числа нужно вычислить?\n");
  scanf("%d", &n);
  printf("%d! = %d\n", n, fact(n));
  return 0;
}
/*
void Factorial ( int n, int &fact )
{
if ( n == 0 ) fact = 1;
Factorial ( n-1, fact );
fact *= n;
}
}
*/
