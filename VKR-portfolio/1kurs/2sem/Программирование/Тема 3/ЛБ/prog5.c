#include <stdio.h>
#include <math.h>

int main() {
  float x,z,t=1;
  int n;
  printf("Enter x and n:" );
  scanf("%f %d",&x,&n);
  for (float i=1; i<n; i++){
    t=t*powf(1+(10+x)/x,1/i);
  }
  z=cos(0.1*t);
  printf("Z=%f\n",z);
  return 0;
}
