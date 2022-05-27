#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 5;

int main(int argc, char const *argv[])
{
  int i,j,t=0;
  int a[n][n];
  /*Заполнение массива случайными числами*/
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n; j++)
    {
      a[i][j]=rand()%20;
    }
  }
  printf("\nA:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  /*Нахождение общего арифметического и замена элементов*/
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n; j++)
    {
      t+=a[i][j];
    }
    t=t/n;
    for (j = 0; j<n; j++)
    {
      a[i][j]=t;
    }
    t=0;
  }
  /*Вывод полученного массива*/
  printf("\nA:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
