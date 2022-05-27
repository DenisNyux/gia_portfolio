#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 2;


int main(int argc, char const *argv[])
{
  int i,j,r;
  /*A - матрица, E - единичная матрица, A_2 - квадрат исходной матрицы, X - результат */
  int a[2][2]={1,2,3,0},a_2[2][2],x[2][2],e[2][2]={1,0,0,1};

  /*Вычисляем квадрат матрицы A*/

  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      a_2[i][j]=0;
      for (r=0; r<n; r++)
      {
        a_2[i][j]=a_2[i][j]+a[i][r]*a[r][j];
      }
    }
  }

  /*В цикле сразу вычисляем поэлементно матричный многочлен*/

  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      x[i][j]=-2*a[i][j]+5*a[i][j]+9*e[i][j];
    }
  }

  /*Выводим результат*/

  printf("\nf(x):\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",x[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
