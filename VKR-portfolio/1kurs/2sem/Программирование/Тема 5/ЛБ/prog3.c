#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 8;

int main(int argc, char const *argv[])
{
  int i,j,t;
  int a[n],b[n];
  /*Отсортируем массив А по возрастанию, проходя по массиву с начала,
  а массив B отсортируем по убыванию, проходя по массиву с конца*/
  /*Ввод массивов*/

  for (i = 0; i<n; i++)
  {
    a[i]=rand()%20;
    b[i]=rand()%20;
    printf("a[%d] = %d\t b[%d]=%d\n", i, a[i],i,b[i]);
  }
  printf("\n");

  /*Сортировка массива А*/

  for (i=0; i<n; i++)
  {
    for (j=i+1;j<n;j++)
    {
      if (a[i]>=a[j])
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
    }
  }

  /*Сортировка массива B*/

  for (i=n-1; i>=0; i--)
  {
    for (j=i-1; j>=0;j--)
    {
      if (b[i]>=b[j])
      {
        t=b[i];
        b[i]=b[j];
        b[j]=t;
      }
    }
  }

  /*Вывод массива*/

  for (i = 0;i<n; i++)
  {
    printf("a[%d] = %d\t b[%d]=%d\n", i, a[i],i,b[i]);
  }
  return 0;
}
