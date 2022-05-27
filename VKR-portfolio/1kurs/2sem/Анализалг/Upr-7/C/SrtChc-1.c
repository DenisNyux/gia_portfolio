   /* Демонстрация сортировки методом простого выбора */
   /* (первый способ)                                 */
   /* ----------------------------------------------- */
   #include<stdio.h>
   #include<stdlib.h>
   #include<conio.h>
   #include<time.h>
   #define N 6      /* Количество элементов в массиве */
      void sortChoice_1 (int *);
      void obmen (int *,int *);
      void print (int *);
  /* ------------------ */
   int main()
   {
      int i,a[N];
      printf("Введите: 0 - \"случайный\" массив,"
             " 1 - ввод массива с клавиатуры: ");
      scanf("%d",&i);
      if (i)
      {
        printf("Введите массив из %u элементов:\n",N);
        for (i=0;i<N;i++)
          scanf("%d",&a[i]);
      }
      else {
             srand(time(NULL));
             for (i=0;i<N;i++)
               a[i]=rand()%10;
           }
      printf("Исходный массив: "); print(a);
      printf("Пошаговая демонстрация сортировки методом"
             " простого выбора (первый способ):\n\n");
      sortChoice_1(a);
      printf("\nРезультат: "); print(a);
      getch();
      return 0;
   }
  /* ---------------------- */
   void sortChoice_1 (int *p)
   /* Сортировка методом простого выбора (первый способ) */
   /* -------------------------------------------------- */
   {
      int i,j,k;
      for (i=0;i<N-1;i++)
      {
        k=i;
        for (j=i+1;j<N;j++)
          if (p[j]<p[k])
            k=j;
        if (k!=i)
        {
          obmen(&p[k],&p[i]); print(p);
        }
      }
   }
  /* ---------------------- */
   void obmen (int *x,int *y)
   {
      int klad=*x;
      *x=*y; *y=klad;
   }
  /* --------------- */
   void print (int *p)
   /* Вывод элементов массива на экран */
   /* -------------------------------- */
   {
      int i;
      for (i=0;i<N;i++)
        printf("%d ",p[i]);
      printf("\n");
   }
