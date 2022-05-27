#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n=2;

int main(int argc, char const *argv[])
{
  int i,j,r,t;
  int a[2][2]={1,-1,-1,1},b[2][2]={2,0,-3,1},c[2][2]={3,-1,2,3};
  int ab[2][2],ab_c[2][2],bc[2][2],a_bc[2][2];
  /*Находим первое произведение A*B */
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      ab[i][j]=0;
      for (r=0; r<n; r++)
      {
        ab[i][j]+=a[i][r]*b[r][j];
      }
    }
  }

  /*Находим второе произведение (A*B)*С */
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      ab_c[i][j]=0;
      for (r=0; r<n; r++)
      {
        ab_c[i][j]+=ab[i][r]*c[r][j];
      }
    }
  }

  /*Находим первое произведение B*C */
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      bc[i][j]=0;
      for (r=0; r<n; r++)
      {
        bc[i][j]+=b[i][r]*c[r][j];
      }
    }
  }
  /*Находим второе произведение A*(B*С) */
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      a_bc[i][j]=0;
      for (r=0; r<n; r++)
      {
        a_bc[i][j]+=a[i][r]*bc[r][j];
      }
    }
  }
  /*Выводи матрицы*/
  printf("\n(A*B)*C:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",ab_c[i][j]);
    }
    printf("\n");
  }
  printf("\n(A*B)*C:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",a_bc[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
