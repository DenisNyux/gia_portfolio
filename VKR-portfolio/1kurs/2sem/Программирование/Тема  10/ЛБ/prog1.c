#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Размер имени вектора*/
#define n 10

struct vector {
  char name[n];
  float x;
  float y;
  float z;
};

/*Вывод вектора*/
void print_struct(struct vector v) {
  printf("%s(%2.2f,%2.2f,%2.2f)\n", v.name, v.x, v.y, v.z);
}
/*Скалярное произведение*/
float scal_mult(struct vector v1, struct vector v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
/*Векторное произведение*/
void vec_mult(struct vector v1, struct vector v2) {
  float i = v1.y * v2.z - v1.z * v2.y;
  float j = v1.x * v2.z - v1.z * v2.x;
  float k = v1.x * v2.y - v1.y * v2.x;
  printf("\nВекторное произведение: %2.2f %2.2f %2.2f\n", i, j, k);
}
/*Модуль вектора*/
float vec_mod(struct vector v) {
  return powf(v.x * v.x + v.y * v.y + v.z * v.z, 1.0 / 2.0);
}

int main(int argc, char const *argv[]) {
  struct vector v1;
  struct vector v2;
  printf("Введите имя первого вектора и его значение\n");
  scanf("%s %f %f %f", &v1.name, &v1.x, &v1.y, &v1.z);
  printf("Введите имя второго вектора и его значение\n");
  scanf("%s %f %f %f", &v2.name, &v2.x, &v2.y, &v2.z);
  printf("\nПервый вектор:\n");
  print_struct(v1);
  printf("Второй вектор\n");
  print_struct(v2);
  printf("\nСкалярное произведение: %2.2f\n", scal_mult(v1, v2));
  vec_mult(v1, v2);
  printf("\nМодуль вектора %s: %2.2f\n", v1.name, vec_mod(v1));
  printf("Модуль вектора %s: %2.2f\n", v2.name, vec_mod(v2));
  return 0;
}
