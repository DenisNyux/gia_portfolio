#include <stdio.h>
#include <math.h>

int main(){
  float x,p;
  printf("Enter x:");
  scanf("%f",&x);
  p=2*powf(x,4)-3*powf(x,3)+2*x*x+x+3;
  printf("p=%f\n",p);
  return 0;
}
