#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 3;
const int m = 3;

int main(int argc, char const *argv[])
{
  int i,j;
  int a[n][m];

  /*Ввод массива*/

  printf("Enter A(3x3):\n" );
  for (i = 0; i<n; i++)
  {
    printf("\nEnter %d column:\n",i+1 );
    for (j = 0; j<m; j++)
    {
      scanf("%d",&a[j][i] );
    }
  }

  /*Вывод матрицы (для проверки)*/

  printf("\nA:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<m;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
