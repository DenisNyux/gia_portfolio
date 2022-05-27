   /* Демонстрация сортировки простыми включениями */
   /* -------------------------------------------- */
   #include<stdio.h>
   #include<stdlib.h>
   #include<conio.h>
   #include<time.h>
   #define N 5          /* Количество элементов в массиве */
     void sortInsert (int *);
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
      printf("Пошаговая демонстрация сортировки "
             "простыми включениями:\n");
      sortInsert(a);
      printf("Результат: "); print(a);
      getch();
      return 0;
   }
  /* -------------------- */
   void sortInsert (int *p)
   /* Сортировка простыми включениями */
   /* ------------------------------- */
   {
      int i,j,x;
      for (i=1;i<N;i++)
      {
        x=p[i];
        for (j=i-1;j>=0&&x<p[j];j--)
          p[j+1]=p[j];
        p[j+1]=x;
        print(p);
      }
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
