#include <stdio.h>
#include <math.h>

int main(){
  float x,y;
  printf("Enter x:");
  scanf("%f",&x );
  y=-2*sqrtf(x*x+4*x*x/3)-powf(cosf(x),4)/x;
  printf("y=%f\n",y);
  return 0;
}
