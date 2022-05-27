#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float v0=200,a=58*M_PI/180,g=9.8,h=80,s;
  printf("V0=%f (м/с)\n",v0);
  printf("a=%f (рад)\n",a);
  printf("g=%f (м/с^2)\n",g);
  printf("h=%f (рад)\n",h);
  printf("\n");
  s=(v0*v0*sinf(a)*cosf(a)+v0*cosf(a)*sqrtf(v0*v0*sinf(a)*sinf(a)+2*g*h))/g;
  printf("s=%f (м)\n",s);
  return 0;
}
