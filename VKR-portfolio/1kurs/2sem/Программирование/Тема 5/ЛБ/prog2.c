#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 6;

int main(int argc, char const *argv[])
{
  int i,t;
  int a[n];

  /*Ввод массива*/

  printf("Enter X:\n" );
  for (i = 0; i<n; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
  }
  printf("\n");

  /*Каждый элемент i меняется на элемент n-i-1*/

  for (i=0; i<(n/2);i++)
  {
    t=a[n-i-1];
    a[n-i-1]=a[i];
    a[i]=t;
  }
  printf("\n");
  /*Вывод массива*/
  for (i = 0;i<n; i++)
  {
    printf("a[%d] = %d\n",i,a[i]);
  }
  return 0;
}
