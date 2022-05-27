#include <stdio.h>
#include <math.h>

int main(){
  float a,b,c,x,h;
  printf("Enter a,b,c,x:");
  scanf("%f %f %f %f",&a,&b,&c,&x);
  h=(a-x)/powf(x*x+a*a,1/3)-4*powf(x*x+b*b,3/4)/(2+a+b+powf(x-c,2/3));
  printf("h=%f\n",h);
  return 0;
}
