#include "math.h"
#include "stdio.h"

/*Постоянная Планка*/
const double h = 6.626E-34;
/*Масса электрона*/
const double me = 9.1E-31;
/*Скорость света в вакууме*/
const double c = 2.998E8;
/*Длина волны*/
const double l = 2.5E-7;
/*Частота*/
const double fr = c / l;
/*1 эВ в джоулях*/
const double eV = 1.602E-19;
/*Работа для серебра в Эв*/
const double a_ag = 4.3;
/*Работа для никеля*/
const double a_ni = 5.04;

/*Перевод Эв в джоули*/
double invertion(double a) { return a * eV; }
/*Cкорость электрона*/
double speed(double a) { return sqrt(2 / me * (h * fr - invertion(a))); }

int main(int argc, char const *argv[]) {
  printf("Ag: %1.5f\n", speed(a_ag));
  printf("Ni: %1.5f\n", speed(a_ni));
  return 0;
}
