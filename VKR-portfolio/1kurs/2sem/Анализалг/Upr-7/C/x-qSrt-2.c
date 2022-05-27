   /* Демонстрация работы с библиотечной функцией qsort(), */
   /* реализующей алгоритм быстрой сортировки Ч.Хоара      */
   /* ---------------------------------------------------- */
   #include<stdio.h>
   #include<stdlib.h>
   #include<string.h>
   #include<conio.h>
      int comp (const void *,const void *);
   /* ---------------------------------- */
   int main()
   {
      char num[100];
      int i,N;
      printf("Введите стринг      : "); gets(num);
      N=strlen(num);
      qsort(num,N,sizeof(char),comp);
      printf("Результат сортировки: "); puts(num);
      printf("\n");
      getch();
      return 0;
   }
  /* ---------------------------------- */
   int comp (const void *i,const void *j)
   /* Функция, возвращающая результат сравнения */
   /* целых чисел                               */
   {
     return *(char *)i - *(char *)j;
   }
