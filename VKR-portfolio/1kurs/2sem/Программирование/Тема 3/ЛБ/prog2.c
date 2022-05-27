#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float a,b,h,fx,n=100000;
  printf("Enter a,b:");
  scanf("%f %f",&a,&b);
  h=(b-a)/n;
  for (float x=a;x<=b-h;x=x+h){
    fx=fx+expf(x+2);
  }
  printf("%f\n",fx );
  return 0;
}
