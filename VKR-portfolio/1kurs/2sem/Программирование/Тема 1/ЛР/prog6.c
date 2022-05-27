#include <stdio.h>
#include <math.h>

int main(){
  float a,b,c,x,r;
  printf("Enter a,b,c,x:");
  scanf("%f %f %f %f",&a,&b,&c,&x);
  r=b*c/12*(6*x*x*powf(1-x/a,2)+b*powf(1-x/sinf(a),2));
  printf("r=%f\n",r);
  return 0;
}
