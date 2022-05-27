#include <stdio.h>

int main(){
  printf("Enter humber: ");
  int x,sum=0;
  scanf("%d",&x);
  while (x>0) {
    sum=sum+x%10;
    x=x/10;
  }
  printf("Sum of digits: %d\n",sum);
}
