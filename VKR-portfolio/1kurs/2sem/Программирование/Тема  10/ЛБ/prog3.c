#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct list_struct {
  int field;                // поле данных
  struct list_struct *next; // указатель на следующий элемент
  struct list_struct *previous; // указатель на предыдущий элемент
};

int main(int argc, char const *argv[]) {
  struct list_struct *first = malloc(sizeof(struct list_struct));
  first->field = 1;
  first->previous = NULL;
  struct list_struct *x, *y;
  x = first;
  for (int i = 1; i < 5; i++) {
    y = malloc(sizeof(struct list_struct));
    y->field = x->field + 1;
    x->next = y;
    y->previous = x;
    x = y;
  }
  x = first;
  while (x != NULL) {
    printf("%d ", x->field);
    x = x->next;
  }
  printf("\n");

  x = first->next->next->next->next;
  while (x != NULL) {
    printf("%d ", x->field);
    x = x->previous;
  }

  free(first->next->next->next->next);
  free(first->next->next->next);
  free(first->next->next);
  free(first->next);
  free(first);
  return 0;
}
