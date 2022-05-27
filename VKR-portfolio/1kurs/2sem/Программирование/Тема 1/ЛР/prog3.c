#include <stdio.h>
#include <math.h>

int main() {
  float x,y,u,t;
  printf("Enter x and y:");
  scanf("%f %f", &x,&y);
  t=sinf(x+y);
  u=(1+t*t)/(2+fabs(x-(2*x*x)/(1+fabs(t))));
  printf("U=%f\n",u);
  return 0;
}
