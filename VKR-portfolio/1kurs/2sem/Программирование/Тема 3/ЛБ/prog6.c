#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float x,n,y,t=0;
  printf("Enter n,x:");
  scanf("%f %f",&n,&x);
  for (float k=3;k<=n;k++){
    t=t+2*x*x*x*k+cosf(k)*sqrtf(x+1)-2.3/k;
  }
  y=6.3*x-4*t;
  printf("y=%f\n",y);
  return 0;
}
