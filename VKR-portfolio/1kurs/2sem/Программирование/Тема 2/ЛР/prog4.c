#include <stdio.h>
#include <math.h>

int main() {
  float z,s,x,r;
  printf("Enter z,s,x:\n");
  scanf("%f %f %f",&z,&s,&x);
  r=2.71*10e6*z*powf(tanf(logf(s)*x),2)/(exp(-s*tanf(x))+fabs(z*x));
  printf("r=%f\n",r);
  return 0;
}
