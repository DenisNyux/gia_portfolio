#include <stdio.h>
#include <math.h>

const float acc=10e-6;

float fn(float x){
  return x-(powf(x,4)-18*x*x+6)/(4*powf(x,3)-36*x);
}

int main(int argc, char const *argv[]) {
  float x,x1=10 ;
  do {
    x=x1;
    x1=fn(x);
  } while(fabs(x1-x)>acc);
  printf("x=%f\n",x);
  return 0;
}
