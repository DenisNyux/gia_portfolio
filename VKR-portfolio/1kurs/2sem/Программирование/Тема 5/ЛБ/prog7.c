#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int n = 2;
const int m = 3;

int main(int argc, char const *argv[])
{
  int i,j;
  int a[2][3]={1,2,3,4,5,6},a_t[3][2];
  //Выводим исходную матрицу
  printf("\nA:\n");
  for (i = 0; i<n; i++)
  {
    for (j = 0; j<m;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  //Транспонирование
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
    {
      a_t[j][i]=a[i][j];
    }
  }
  //Вывод транспонированной матрицы
  printf("\nA_t:\n");
  for (i = 0; i<m; i++)
  {
    for (j = 0; j<n;j++)
    {
      printf("%d ",a_t[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}
