#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int a, b, c;
  printf("Enter three numbers:");
  scanf("%d %d %d", &a, &b, &c);
  if ((a >= b) && (b >= c)) {
    printf("The biggest one is:%d\n", a);
  } else if ((b >= a) && (b >= c)) {
    printf("The biggest one is:%d\n", b);
  } else if ((c >= a) && (c >= b)) {
    printf("The biggest one is:%d\n", c);
  }
  return 0;
}
