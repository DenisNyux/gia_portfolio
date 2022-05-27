#include <stdio.h>

int main(int argc, char const *argv[]) {
  int x;
  printf("Enter a number: ");
  scanf("%d",&x);
  for (int i=0;i<=x;i++){
    printf("%d ",i);
  }
  printf("\n" );
  return 0;
}
