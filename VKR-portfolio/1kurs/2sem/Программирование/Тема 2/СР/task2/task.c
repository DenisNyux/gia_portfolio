#include <stdio.h>
#include <math.h>
const int l = 330000;      //удельная теплота плавления
const int r = 2256000;     //удельная теплота парообразования
const int tpl = 0;      //температура плавления
const int tpo = 100;    //температура парообразования
const int t0 = -20;     //начальная температура
const int cl = 1943;    //удельная теплота льда
const int cv = 4217;    //удельная теплота воды
const float kerosin = 42.9e6;
const float drova = 9.5e6;
const float spirt = 30.6e6;

int main(int argc, char const *argv[]) {
  int q1, qp, q2, qpo, q, m=1; //количества теплоты для нагревания воды/льда и для плавления/парообразования
  float mk,md,ms;
  q1 = cl*m*(tpl-t0);
  qp = m*l;
  q2 = cv*m*(tpo-tpl);
  qpo = m*r;
  q = q1+q2+qp+qpo;
  printf("Общее количество теплоты: %d\n",q);
  mk=q/kerosin;
  printf("Для перехода воды в пар требуется %f (кг) керосина\n", mk);
  md=q/drova;
  printf("Для перехода воды в пар требуется %f (кг) дров\n", md);
  ms=q/spirt;
  printf("Для перехода воды в пар требуется %f (кг) спирта\n", ms);
  return 0;
}
