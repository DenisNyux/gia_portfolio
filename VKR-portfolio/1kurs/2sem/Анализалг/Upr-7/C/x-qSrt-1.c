   /* Демонстрация работы с библиотечной функцией */
   /* qsort(), реализующей алгоритм быстрой  сор- */
   /* тировки Ч.Хоара                             */
   /* ------------------------------------------- */
   #include<stdio.h>
   #include<stdlib.h>
   #include<conio.h>
   #define N 15
      int comp (const void *,const void *);
      int comp1(const void *,const void *);
      int comp2(const void *,const void *);
   /* ---------------------------------- */
   int main()
   {
      int num[N],i;
      /* ------------------------- */
      /* Ввод "случайного" массива */
      /* ------------------------- */
      for (i=0;i<N;i++)
	num[i]=rand()%10;
      printf("Исходный массив:\n");
      for (i=0;i<N;i++)
	printf("%d ",num[i]);
      printf("\n\n");
      /* ------------------------ */
      qsort(num,N,sizeof(int),comp);
      printf("Результат сортировки (по возрастанию):\n");
      for (i=0;i<N;i++)
        printf("%d ",num[i]);
      printf("\n\n");
      /* ------------------------- */
      qsort(num,N,sizeof(int),comp1);
      printf("Результат сортировки (по убыванию):\n");
      for (i=0;i<N;i++)
        printf("%d ",num[i]);
      printf("\n\n");
      /* ------------------------- */
      qsort(num,N,sizeof(int),comp2);
      printf("Результат сортировки (по условию x+y>2):\n");
      for (i=0;i<N;i++)
	printf("%d ",num[i]);
      printf("\n\n");
      getch();
      return 0;
   }
   /* -------------------------------- */
   int comp (const void *i,const void *j)
   /* Функция, возвращающая результат сравнения */
   /* целых чисел                               */
   {
     return *(int *)i - *(int *)j;
   }
   /* --------------------------------- */
   int comp1 (const void *i,const void *j)
   /* Функция, возвращающая результат сравнения */
   /* целых чисел                               */
   {
     return *(int *)j - *(int *)i;
   }
   /* --------------------------------- */
   int comp2 (const void *i,const void *j)
   /* Функция, возвращающая результат сравнения */
   /* целых чисел                               */
   {
     return *(int *)i + *(int *)j > 2;
   }
