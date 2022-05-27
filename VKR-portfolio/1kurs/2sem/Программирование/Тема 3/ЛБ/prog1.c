#include <stdio.h>
#include <math.h>

const float r1=1.5235; //радиус орбиты марса в а.е.
const float r2=1.0; //радиус орбиты земли в а.е.
const float t1=686./365; //период обращения вокруг марса (год)
const float t2=1.0; //период обращения вокруг земли (год)

int main(){
  float w1=2*M_PI/t1,w2=2*M_PI/t2,x,y; //t (год)
  for (float t=1;t<=20;t++){
    x=r1*cosf(w1*t)-r2*cos(w2*t);
    y=r1*sinf(w1*t)-r2*sin(w2*t);
    printf("x=%f  y=%f\n",x,y);
  }
  return 0;
}
