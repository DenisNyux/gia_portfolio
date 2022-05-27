#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n=2;
const int m=4;

int main(int argc, char const *argv[])
{
  int i,j,r;
  int a[2][4]={1,2,1,3,4,-1,5,-1},a_t[4][2],c[2][2],x[4][4];

  //Транспонировани
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
    {
      a_t[j][i]=a[i][j];
    }
  }
  /*Умножение матрицы А на матрицу A_t*/
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      c[i][j]=0;
      for (r=0; r<m; r++)
      {
      c[i][j]+=a[i][r]*a_t[r][j];
      }
    }
  }
/*Умножение матрицы A_t на А*/
  for (i=0; i<m; i++)
  {
    for (j=0; j<m; j++)
    {
      x[i][j]=0;
      for (r=0; r<n; r++)
      {
        x[i][j]+=a_t[i][r]*a[r][j];
      }
    }
  }

  printf("\nA * A_t:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }

  printf("\nA_t * A:\n");
  for (i = 0; i<m; i++)
  {
    for (j = 0; j<m;j++)
    {
      printf("%d ",x[i][j]);
    }
    printf("\n");
  }
  return 0;
}
