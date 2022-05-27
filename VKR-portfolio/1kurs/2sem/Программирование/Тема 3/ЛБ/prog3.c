#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x1=1,x2,t,m ;
  printf("Enter m:" );
  scanf("%d",&m );
  printf("1 ");
  for (x2=1;x2<m;) {
    printf("%d ",x2);
    t=x2;
    x2=x2+x1;
    x1=t;
  }
  printf("\n" );
  return 0;
}
