#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int x,sum=11;
  while (sum>10){
    printf("Enter a number:");
    scanf("%d",&x );
    sum=0;
    while (x>0){
      sum=sum+x%10;
      x=x/10;
    }
    printf("Sum of digits is %d.\n" ,sum);
  }
  printf("Sum of digits is less than or equal to 10\n");
  return 0;
}
