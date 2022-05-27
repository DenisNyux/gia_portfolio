#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int a[5];
  int i;
  printf("Enter X:\n" );
  for (i = 0; i<5; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
    a[i]=a[i]*a[i];
  }
  printf("\n");
  printf("X^2:\n");
  for (i = 0;i<5; i++)
  {
    printf("a[%d] = %d\n",i,a[i]);
  }
  return 0;
}
