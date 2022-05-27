   /* Демонстрация сортировки методом простого выбора */
   /* (второй способ)                                 */
   /* ----------------------------------------------- */
   #include<stdio.h>
   #include<stdlib.h>
   #include<conio.h>
   #include<time.h>
   #define N 7      /* Количество элементов в массиве */
     void sortChoice_2 (int *);
     int minI (int,int *);
     void obmen (int *,int *);
     void print (int *);
  /* ----------------- */
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
      printf("Пошаговая демонстрация сортировки методом "
             "простого выбора (второй способ):\n");
      sortChoice_2(a);
      printf("Результат: "); print(a);
      getch();
      return 0;
   }
  /* ---------------------- */
   void sortChoice_2 (int *p)
   /* Сортировка методом простого выбора (второй способ) */
   /* -------------------------------------------------- */
   {
      int i,j,k;
      for (i=0;i<N-1;i++)
        obmen(&p[minI(i,p)],&p[i]);
   }
  /* ----------------------- */
   int minI (int start,int *p)
   /* Функция находит минимальный элемент "правее" start */
   /* (включая start) и возвращает его номер             */
   /* -------------------------------------------------- */
   {
      int m,i;
      for (m=start,i=start+1;i<N;i++)
        if (p[i]<p[m])
          m=i;
      if (m!=start)
        print(p);
      return m;
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
