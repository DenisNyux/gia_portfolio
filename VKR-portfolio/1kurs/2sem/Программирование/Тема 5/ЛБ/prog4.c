#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 10;


int main(int argc, char const *argv[])
{
  int i,j,t;
  int a[n],b[n];

  /*Ввод массивов*/

  for (i = 0; i<n; i++)
  {
    a[i]=rand()%20;
    b[i]=rand()%20;
    printf("a[%d] = %d\t b[%d] = %d\n",i,a[i],i,b[i]);
  }
  printf("\n");

  /*Сортировка массива А по возрастанию*/

  for (i = 1; i<n; i++)
  {
      t=a[i];
      j=i-1;
      while (j>=0 & a[j] >= t )
      {
        a[j+1]=a[j];
        j=j-1;
      }
      a[j+1]=t;
  }

  /*Сортировка массива B по убыванию*/
  for (i = 1; i<n; i++)
  {
      t=b[i];
      j=i-1;
      while (j>=0 & b[j] <= t )
      {
        b[j+1]=b[j];
        j=j-1;
      }
      b[j+1]=t;
  }
  /*Вывод массива*/

  for (i = 0;i<n; i++)
  {
    printf("a[%d] = %d\t b[%d] = %d\n",i,a[i],i,b[i]);
  }
  return 0;
}
