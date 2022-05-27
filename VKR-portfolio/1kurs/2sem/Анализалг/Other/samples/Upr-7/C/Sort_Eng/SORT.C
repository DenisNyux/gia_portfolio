   /* Программа, наглядно демонстрирующая некоторые */
   /* классические алгоритмы сортировки.            */
   /* Автор программы: А.В.Коротков (02.11.2003)    */
   /* --------------------------------------------- */
   #include <stdlib.h>
   #include <time.h>
   #include <dos.h>
   #include "win.h"
   #include "co.h"
   /* --------- */
   #define ESC 27
   #define TAB 9
   #define ENTER 13
   #define UP 72
   #define DOWN 80
   #define BACKSPACE 8
   #define SP 32
   #define STACK_SIZE 400         /* Для функции newProcess()  */
   #define MAIN 1     /* Главный процесс.                      */
   #define NEW 2      /* Процесс, который генерирует вектора.  */
   #define N 18       /* Число элементов в векторе.            */
   #define M_X 32     /* (M_X,M_Y) - левый верхний угол        */
   #define M_Y 2      /*             главного меню.            */
   #define M_W 46     /* Ширина главного меню.                 */
   #define M_H 21     /* Высота главного меню.                 */
   #define M__X 3     /* (M__X,M__Y) - левый верхний угол      */
   #define M__Y 3     /*               вспомогательного меню.  */
   #define M__W 24    /* Ширина вспомогательного меню.         */
   #define M__H 1     /* Высота вспомогательного меню.         */
   #define CMP_N_PAUSE 10
   #define MAX_PAUSE 12
   #define H_PAUSE 1
   #define COLOR 4    /* Цвет выделения элементов, которые     */
                      /* можно "изменять" нажатием клавиш.     */
   #define COLOR1 2   /* Цвет важных сообщений.                */
   #define LEN_MENU 10   /* Число элементов в главном меню <23 */
   /* -------------------------------------------------------- */
     char *menu[]={ "Сортировка простым обменом (способ 1)",
                    "Сортировка простым обменом (способ 2)",
                    "Сортировка простым выбором (способ 1)",
                    "Сортировка простыми включениями (модиф. 1)",
                    "Сортировка простыми включениями",
                    "Сортировка бинарными включениями",
                    "Быстрая сортировка (рекурсивный вариант)",
                    "Пирамидальная сортировка",
                    "Сортировка слиянием",
                    "Сортировка слиянием (модиф. 1)",
                  },
           m_dostup[]={1,1,1,1,1,1,1,1,1,1},
          *menu2[]={"Демонстрационный массив",
                    "\"Случайный\" массив"
                   },
          ris[]={'┌', '┐', '└', '┘', '─', '│', '┴', '┬'};
     int m_pause[]={
         0,  1,  2,  5,  10, 50,100,150,200,250,300,400,500,600
                   };
     int demo_matr[]={12, 10, 25,  4,  0, 25,  9,  8,  7, 90,
                       6, 35, 40, 40, 61, 51,  1,  1, 30, 50},
         matr[N];
     void f(void),
          tr(int,int,int,int,unsigned,unsigned),
          wait1(int,int,int,int,unsigned,unsigned),
          w(int,int,int,int,int,char*),
          upr(unsigned,unsigned),
          obmen(int *,int *),
          obmen1(int,int,
             int,int,int,int,unsigned,unsigned),
          cmp(int,int,int,char *,
             int,int,int,int,unsigned,unsigned),
          cmpKlad(int,int,int,char *,
             int,int,int,int,unsigned,unsigned),
          movKlad(int,int,int,int,
             int,int,int,int,unsigned,unsigned),
          mov(int,int,int,
             int,int,int,int,unsigned,unsigned),
          delElement(int,int),
          rect2(int,int,int,int),
          rect2_(int,int,int),
          cmp_n_pause(int,int,int,int,int,unsigned,unsigned),
          initCmpMov(int,int,int,int),
          printCmpMov(int,int,int,int,int,int),
          qSortRec(int,int,int *,
             int,int,int,int,unsigned,unsigned),
          hSort(int*,int,int,
             int,int,int,int,unsigned,unsigned),
          mergeSort(int*,int,int,
             int,int,int,int,unsigned,unsigned),
          mergeList(int*,int,int,int,int,
             int,int,int,int,unsigned,unsigned),
          mergeSort1(int*,int,int,
             int,int,int,int,unsigned,unsigned),
          mergeList1(int*,int,int,int,int,
             int,int,int,int,unsigned,unsigned),
        bubble1(void),
        bubble2(void),
        sortChoice1(void),
        sortInsertM(void),
        sortInsert(void),
        sortBinInsert(void),
        qSortRecProc(void),
        heapSort(void),
        mergeSortProc(void),
        mergeSortProc1(void),
          *proc[]={bubble1,
                   bubble2,
                   sortChoice1,
                   sortInsertM,
                   sortInsert,
                   sortBinInsert,
                   qSortRecProc,
                   heapSort,
                   mergeSortProc,
                   mergeSortProc1};
     /* ---------------------------------------------------- */
     int num_p1,     /* Номер выбранного пункта в меню 1.    */
         num_p2,     /* Номер выбранного пункта в меню 2.    */
         m,          /* Номер активного меню.                */
         cmp1,cmp2,  /* Число сравнений для процессов 1 и 2. */
         mov1,mov2,  /* Число копирований для этих процессов.*/
         pause=7,    /* Время задержки.                      */
         py,         /* Координата для окна процесса.        */
         i1,         /* Номер создаваемого процесса.         */
         i2,         /* Номер процесса для передачи упр.     */
         s,          /* "Семафор".                           */
         metka=-1,   /* Номер помеченного пункта меню 1      */
         sp=1;
  /* ------------------------------------------------------- */
   int main() {
     int i;
     _setcursortype(0);
     srand(time(NULL));
     num_p2=num_p1=0;
     for (i=0; i<N; i++)
       matr[i]=demo_matr[i];
     do {
       m=0;
       window(1,1,80,25);
       clrscr();
       textcolor(7);
       gotoxy(3,9);  cprintf("КЛАВИШИ УПРАВЛЕНИЯ:");
       gotoxy(4,11); cprintf("<Esc>       - выход,");
       gotoxy(4,12); cprintf("<Enter>     - сортировка,");
       gotoxy(4,13); cprintf("<Tab>       - переход,");
       gotoxy(4,14); cprintf("<\"Стрелки\"> - выбор,");
       gotoxy(4,15); cprintf("<\"Пробел\">  - пометить.");
       win(M__X, M__Y, M__X+M__W, M__Y+M__H, 0);
       gotoxy(2,1); cprintf(menu2[0]);
       gotoxy(2,2); cprintf(menu2[1]);
       textcolor(COLOR);
       gotoxy(2,1+num_p2); cprintf(menu2[num_p2]);
       textcolor(7);
       win(M_X, M_Y, M_X+M_W, M_Y+M_H, 1);
       for (i=0; i<LEN_MENU; i++)
         { gotoxy(2,i+1); cprintf(menu[i]); }
       if (metka!=-1) {
         textcolor(COLOR1); gotoxy(1,1+metka); cprintf(">");
       }
       textcolor(COLOR);
       gotoxy(2,1+num_p1); cprintf(menu[num_p1]);
       textcolor(7);
       do {
         if ((i=getch())==0)
           i=getch();
         switch (i) {
           case ENTER:
             newProcess(f,NEW,STACK_SIZE);
             window(1,1,80,25);
             clrscr();
             gotoxy(6,25);
             cprintf("<Esc> - выход, <\"Стрелки\"> - ");
             cprintf("изменение времени задержки");
             textcolor(sp?7:COLOR);
             cprintf(": ");
             textcolor(COLOR);
             if (pause<=MAX_PAUSE)
               cprintf("%d",m_pause[pause]);
             else
               cprintf("STOP");
             textcolor(7);
             i1=3; s=0;
             if (metka==-1) {
               i2=3; py=10;
               newProcess((void (*)())proc[num_p1],3,STACK_SIZE);
             } else {
               i2=4; py=6;
               newProcess((void (*)())proc[metka],3,STACK_SIZE);
               newProcess((void (*)())proc[num_p1],4,STACK_SIZE);
             }
             transfer(MAIN,NEW);
             delAllProcess();
             break;
           case SP:
             if (!m&&m_dostup[num_p1]) {
               if (metka==-1) {
                 metka=num_p1;
                 textcolor(COLOR1);
               } else
                 if (metka==num_p1) {
                   metka=-1;
                   textcolor(0);
                 } else {
                   textcolor(0);
                   gotoxy(1,1+metka); cprintf(">");
                   metka=num_p1;
                   textcolor(COLOR1);
                 }
               gotoxy(1,1+num_p1); cprintf(">");
               textcolor(7);
             } else
               ; /* Невозможно поставить метку ("звонок") */
             break;
           case TAB:
             if (m) {
               win(M__X, M__Y, M__X+M__W, M__Y+M__H, 0);
               win(M_X, M_Y, M_X+M_W, M_Y+M_H, 1);
             } else {
               win(M_X, M_Y, M_X+M_W, M_Y+M_H, 0);
               win(M__X, M__Y, M__X+M__W, M__Y+M__H, 1);
             }
             m=!m;
             break;
           case UP:
             if (m) {
               if (num_p2) {
                 int j;
                 num_p2=0;
                 gotoxy(2,1); textcolor(COLOR);
                 cprintf(menu2[0]);
                 gotoxy(2,2); textcolor(7);
                 cprintf(menu2[1]);
                 for (j=0; j<N; j++)
                   matr[j]=demo_matr[j];
               }
             } else
               if (num_p1) {
                 gotoxy(2,num_p1+1); cprintf(menu[num_p1]);
                 num_p1--; textcolor(COLOR);
                 gotoxy(2,num_p1+1); cprintf(menu[num_p1]);
                 textcolor(7);
               }
             break;
           case DOWN:
             if (m) {
               if (!num_p2) {
                 int j;
                 num_p2=1;
                 gotoxy(2,2); textcolor(COLOR);
                 cprintf(menu2[1]);
                 gotoxy(2,1); textcolor(7);
                 cprintf(menu2[0]);
                 for (j=0; j<N; j++)
                   matr[j]=rand()%100;
               }
             } else
               if (num_p1<LEN_MENU-1) {
                 gotoxy(2,num_p1+1); cprintf(menu[num_p1]);
                 num_p1++; textcolor(COLOR);
                 gotoxy(2,num_p1+1); cprintf(menu[num_p1]);
                 textcolor(7);
               }
             break;
         }
       } while (i!=ENTER && i!=ESC);
     } while (i!=ESC);
     return 0;
   }
  /* ---------- */
   void f(void) {
     int i,nextProc=i1;
     win(2,2,78,3,0);
     cprintf("Массив для сортировки:");
     for (;;) {
       gotoxy(1,2);
       for (i=0; i<N; i++)
         cprintf("%4d",matr[i]);
       tr(2,2,79,4,NEW,nextProc);
       if (num_p2)
         for (i=0; i<N; i++)
           matr[i]=rand()%100;
       else
         for (i=0; i<N; i++)
           matr[i]=demo_matr[i];
     }
   }
  /* -------------------------------------------------------- */
   void tr(int x1,int y1,int x2,int y2,unsigned i1,unsigned i2)
   {
     upr(i1,i2);
     transfer(i1,i2);
     window(x1,y1,x2,y2);
   }
  /* ----------------------------- */
   void upr(unsigned i1,unsigned i2)
   {
     if (pause<=MAX_PAUSE)
       delay(m_pause[pause]);
     if (kbhit()||(pause>MAX_PAUSE)||(i2==NEW&&sp))
     {
       int ch;
       if (i2==NEW&&sp) {
         window(2,2,78,3);
         textcolor(COLOR1);
         gotoxy(25,1);
         cprintf("СОРТИРОВКА ЗАВЕРШЕНА! ");
         cprintf("<Enter> - продолжить.");
         textcolor(7);
       }
       do {
         ch=getch();
         if (ch==0)
           ch=getch();
         if (ch==ESC)
           transfer(i1,MAIN);
         if (ch==BACKSPACE) {
           sp=!sp;
           window(1,1,80,25);
           gotoxy(61,25);
           textcolor(sp?7:COLOR);
           cprintf(":");
           textcolor(7);
           ch=ENTER;
         }
         if (ch==UP||ch==DOWN) {
           switch(ch) {
             case UP:
               if (pause<=MAX_PAUSE) pause+=H_PAUSE;
               break;
             case DOWN:
               if (pause>0) pause-=H_PAUSE;
           }
           window(1,1,80,25);
           gotoxy(63,25);
           textcolor(COLOR);
           if (pause<=MAX_PAUSE)
             cprintf("%d    ",m_pause[pause]);
           else
             cprintf("STOP");
           textcolor(7);
         }
         if (i2==NEW&&ch==ENTER) {
           window(2,2,78,3);
           textcolor(0);
           gotoxy(25,1);
           cprintf("СОРТИРОВКА ЗАВЕРШЕНА! ");
           cprintf("<Enter> - продолжить.");
           textcolor(7);
         }
       } while (i2==NEW&&sp&&ch!=ENTER);
     }
   }
  /* ----------------------- */
   void obmen(int *x,int *y) {
     int klad=*x; *x=*y; *y=klad;
   }
  /* ------------------------------ */
   void obmen1(int index1,int index2,
               int x1,int y1,int x2,int y2,
               unsigned i1,unsigned i2) {
     /* Визуализация обмена элементов массива */
     int xx1,xx2,y=y1+5,buf1[2],buf2[2],buf[2],i;
     if (index1>index2)
       { xx1=index1; index1=index2; index2=xx1; }
     xx1=x1+2+4*index1;
     xx2=x1+2+4*index2;
     rect2(3+4*index1,3+4*index2,6,0);
     gettext(x1,y+2,x1+1,y+2,buf);  /* Сохраняем "пробелы" */
     gettext(xx1,y,xx1+1,y,buf1);
     gettext(xx2,y,xx2+1,y,buf2);

     tr(x1,y1,x2,y2,i1,i2);
     for (i=0; i<2; i++) {
       puttext(xx1,y-i,xx1+1,y-i,buf);
       puttext(xx2,y+i,xx2+1,y+i,buf);
       gettext(xx1,y-i-1,xx1+1,y-i-1,buf);
       puttext(xx1,y-i-1,xx1+1,y-i-1,buf1);
       puttext(xx2,y+i+1,xx2+1,y+i+1,buf2);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=xx1; i<xx2; xx1++,xx2--) {
       puttext(xx1,  y-2,xx1+1,y-2,buf);
       puttext(xx1+1,y-2,xx1+2,y-2,buf1);
       puttext(xx2,  y+2,xx2+1,y+2,buf);
       puttext(xx2-1,y+2,xx2,  y+2,buf2);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=2; i>0; i--) {
       puttext(xx1,y-i,xx1+1,y-i,buf);
       puttext(xx2,y+i,xx2+1,y+i,buf);
       gettext(xx1,y-i+1,xx1+1,y-i+1,buf);
       puttext(xx1,y-i+1,xx1+1,y-i+1,buf1);
       puttext(xx2,y+i-1,xx2+1,y+i-1,buf2);
       tr(x1,y1,x2,y2,i1,i2);
     }
     textcolor(0);
     rect2(3+4*index1,3+4*index2,6,0);
     textcolor(7);
     printCmpMov(0,3,x1,y1,x2,y2);
   }
  /* ------------------------------------------- */
   void cmp(int index1,int index2,int rez,char *p,
               int x1,int y1,int x2,int y2,
               unsigned i1,unsigned i2) {
     /* Визуализация сравнения элементов массива */
     int xx1,xx2,y=y1+5,buf1[2],buf2[2],sh,i;
     xx1=x1+2+4*index1;
     xx2=x1+2+4*index2;
     gettext(xx1,y,xx1+1,y,buf1);
     gettext(xx2,y,xx2+1,y,buf2);
     if (index1>index2) {
       xx1=index1; index1=index2; index2=xx1;
       xx1=x1+2+4*index1;
       xx2=x1+2+4*index2;
     }
     rect2(3+4*index1,3+4*index2,6,1);
     for (i=0; *(p+i)!='\0'; i++);  /* i - длина строки *p */
     i+=4;  /* Длина всего текста для печати */
     sh=(3+4*index1+3+4*index2)/2-i/2+1;
     /* sh - относительный сдвиг к тексту для печати */
     if (sh<2) sh=2;
     if (sh>x2-x1-i-2) sh=x2-x1-i-2;
     puttext(x1+sh-1,y-3,x1+sh,y-3,buf1);
     puttext(x1+sh+i-3,y-3,x1+sh+i-2,y-3,buf2);
     gotoxy(sh+2,3); cprintf("%s",p);
     gotoxy(sh+i/2,2); cprintf("%d",rez);

     tr(x1,y1,x2,y2,i1,i2);
     cmp_n_pause(CMP_N_PAUSE,x1,y1,x2,y2,i1,i2);

     textcolor(0);
     gotoxy(sh+i/2,2); cprintf(" ");
     gotoxy(sh,3); for (; i>0; i--) cprintf(" ");
     rect2(3+4*index1,3+4*index2,6,1);
     textcolor(7);
     printCmpMov(1,0,x1,y1,x2,y2);
   }
  /* ---------------------------------------------------- */
   void movKlad(int iMatr,int iKlad,int matrKlad, int copy,
          int x1,int y1,int x2,int y2, unsigned i1,unsigned i2) {
     /* copy==1 - копирует, copy==0 - перемещает элемент;      */
     /* matrKlad==1 - из массива в клад, matrKlad==0 - обратно */
     /* iMatr - индекс элемента в массиве,                     */
     /* iKlad - индекс элемента в кладе.                       */
     /* Визуализация обмена элементов между массивом и кладом  */
     /* ------------------------------------------------------ */
     int xx1,xx2,yy1=y1+5,yy2=y1,buf1[2],buf[2],i,h,w,x,y,n;
     xx1=x1+2+4*iMatr;
     xx2=x1+2+4*iKlad;
     rect2_(3+4*iMatr,3+4*iKlad,0);
     tr(x1,y1,x2,y2,i1,i2);
     if (matrKlad) {
       h=-1;
       gettext(xx1,yy1,xx1+1,yy1,buf1);
       x=xx1; y=yy1;
       if (!copy) delElement(iMatr,0);
       w=(xx1<xx2)?1:-1;
     } else {
       h=1;
       gettext(xx2,yy2,xx2+1,yy2,buf1);
       x=xx2; y=yy2;
       if (!copy) delElement(iKlad,1);
       w=(xx1<xx2)?-1:1;
     }
     n=(xx1<xx2)?xx2-xx1:xx1-xx2;
     gettext(x,y,x+1,y,buf);  /* Сохраняем */

     for (i=0; i<3; i++) {
       puttext(x,y,x+1,y,buf);
       y+=h;
       gettext(x,y,x+1,y,buf);
       puttext(x,y,x+1,y,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=0; i<n; i++) {
       puttext(x,y,x+1,y,buf);
       x+=w;
       gettext(x,y,x+1,y,buf);
       puttext(x,y,x+1,y,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=0; i<2; i++) {
       puttext(x,y,x+1,y,buf);
       y+=h;
       gettext(x,y,x+1,y,buf);
       puttext(x,y,x+1,y,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }
     textcolor(0);
     rect2_(3+4*iMatr,3+4*iKlad,0);
     textcolor(7);
     printCmpMov(0,1,x1,y1,x2,y2);
   }
  /* ------------------------------------ */
   void mov(int index1,int index2,int copy,
               int x1,int y1,int x2,int y2,
               unsigned i1,unsigned i2) {
     /* copy==1 - копирует, copy==0 - перемещает элемент  */
     /* массива с index1 в позицию с index2               */
     /* ------------------------------------------------- */
     int xx1,xx2,y=y1+5,buf1[2],buf[2],i,w,n;
     xx1=x1+2+4*index1;
     xx2=x1+2+4*index2;
     rect2(3+4*index1,3+4*index2,6,0);
     tr(x1,y1,x2,y2,i1,i2);
     gettext(xx1,y,xx1+1,y,buf1);
     if (!copy) delElement(index1,0);
     w=(xx1<xx2)?1:-1;
     n=(xx1<xx2)?xx2-xx1:xx1-xx2;
     gettext(xx1,y,xx1+1,y,buf);  /* Сохраняем */

     for (i=1; i<3; i++) {
       puttext(xx1,y-i+1,xx1+1,y-i+1,buf);
       gettext(xx1,y-i,xx1+1,y-i,buf);
       puttext(xx1,y-i,xx1+1,y-i,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=0; i<n; i++) {
       puttext(xx1,y-2,xx1+1,y-2,buf);
       xx1+=w;
       gettext(xx1,y-2,xx1+1,y-2,buf);
       puttext(xx1,y-2,xx1+1,y-2,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }
     for (i=1; i>=0; i--) {
       puttext(xx1,y-i-1,xx1+1,y-i-1,buf);
       gettext(xx1,y-i,xx1+1,y-i,buf);
       puttext(xx1,y-i,xx1+1,y-i,buf1);
       tr(x1,y1,x2,y2,i1,i2);
     }

     textcolor(0);
     rect2(3+4*index1,3+4*index2,6,0);
     textcolor(7);
     printCmpMov(0,1,x1,y1,x2,y2);
   }
  /* --------------------------------- */
   void delElement(int index,int klad) {
     /* Удаляет элемент с индексом index                       */
     /*          klad==1 - удаляет элемент из клада.           */
     /*          klad==0 - удаляет элемент из массива          */
     /* ------------------------------------------------------ */
     gotoxy(3+4*index,klad?1:6); cprintf("  ");
   }
  /* -------------------------------- */
   void rect2_(int x1,int x2,int tip) {
     /* Рисует два прямоугольника для элемента массива x1 и */
     /* и элемента клада x2. Если tip!=0, то соединяет их.  */
     /* ris[]={'┌', '┐', '└', '┘', '─', '│', '┴', '┬');     */
     /*         0    1    2    3    4    5    6    7        */
     /* --------------------------------------------------- */
     rect2(x1,x1,6,0);
     gotoxy(x2-1,2);
     cprintf("%c%c%c%c",ris[2],ris[4],ris[4],ris[3]);
     gotoxy(x2-1,1); cprintf("%c",ris[5]);
     gotoxy(x2+2,1); cprintf("%c",ris[5]);

     if (tip)
       if (x1==x2) {
         gotoxy(x1,2); cprintf("%c",ris[7]);
         gotoxy(x1,3); cprintf("%c",ris[5]);
         gotoxy(x1,4); cprintf("%c",ris[5]);
         gotoxy(x1,5); cprintf("%c",ris[6]);
       } else {
         int i,n;
         if (x1<x2) {
           i=x1+2; n=x2;
           gotoxy(x2,2); cprintf("%c",ris[7]);
           gotoxy(x2,3); cprintf("%c",ris[5]);
           gotoxy(x2,4); cprintf("%c",ris[3]);
           gotoxy(x1+1,4); cprintf("%c",ris[0]);
           gotoxy(x1+1,5); cprintf("%c",ris[6]);
         } else {
           i=x2+2; n=x1;
           gotoxy(x2+1,2); cprintf("%c",ris[7]);
           gotoxy(x2+1,3); cprintf("%c",ris[5]);
           gotoxy(x2+1,4); cprintf("%c",ris[2]);
           gotoxy(x1,4); cprintf("%c",ris[1]);
           gotoxy(x1,5); cprintf("%c",ris[6]);
         }
         for (gotoxy(i,4); i<n; i++)
           cprintf("%c",ris[4]);
       }
   }
  /* ----------------------------------------------- */
   void cmpKlad(int index1,int index2,int rez,char *p,
               int x1,int y1,int x2,int y2,
               unsigned i1,unsigned i2) {
     /* Визуализация сравнения элементов массива index1 */
     /* и клада index2                                  */
     /* ----------------------------------------------- */
     int xx1,xx2,y=y1+5,buf1[2],buf2[2],sh,i;
     rect2_(3+4*index1,3+4*index2,1);
     xx1=x1+2+4*index1;
     xx2=x1+2+4*index2;
     gettext(xx1,y,xx1+1,y,buf1);
     gettext(xx2,y-5,xx2+1,y-5,buf2);
     for (i=0; *(p+i)!='\0'; i++);  /* i - длина строки *p */
     i+=4;                /* Длина всего текста для печати */
     if (xx1<xx2)
       if (xx2-x1>i+1)
         sh=xx2-x1-i;
       else
         sh=xx2-x1+4;
     else
       if (x2-xx2>i+3)
         sh=xx2-x1+4;
       else
         sh=xx2-x1-i;

     puttext(x1+sh-1,y-3,x1+sh,y-3,buf1);
     puttext(x1+sh+i-3,y-3,x1+sh+i-2,y-3,buf2);
     gotoxy(sh+2,3); cprintf("%s",p);
     gotoxy(sh+i/2,2); cprintf("%d",rez);

     tr(x1,y1,x2,y2,i1,i2);
     cmp_n_pause(CMP_N_PAUSE,x1,y1,x2,y2,i1,i2);

     textcolor(0);
     gotoxy(sh+i/2,2); cprintf(" ");
     gotoxy(sh,3); for (; i>0; i--) cprintf(" ");
     rect2_(3+4*index1,3+4*index2,1);
     textcolor(7);
     printCmpMov(1,0,x1,y1,x2,y2);
   }
  /* ------------------------------------- */
   void rect2(int x1,int x2,int y,int tip) {
     /* Рисует два прямоугольника: (x1-1,y-1,x1+2,y+1) и   */
     /* (x2-1,y-1,x2+2,y+1). Если tip!=0, то соединяет их. */
     /* ris[]={'┌', '┐', '└', '┘', '─', '│', '┴'};         */
     /*         0    1    2    3    4    5    6            */
     /* -------------------------------------------------- */
     gotoxy(x1-1,y-1);
     cprintf("%c%c%c%c",ris[0],ris[4],ris[4],ris[1]);
     gotoxy(x1-1,y+1);
     cprintf("%c%c%c%c",ris[2],ris[4],ris[4],ris[3]);
     gotoxy(x1-1,y); cprintf("%c",ris[5]);
     gotoxy(x1+2,y); cprintf("%c",ris[5]);

     gotoxy(x2-1,y-1);
     cprintf("%c%c%c%c",ris[0],ris[4],ris[4],ris[1]);
     gotoxy(x2-1,y+1);
     cprintf("%c%c%c%c",ris[2],ris[4],ris[4],ris[3]);
     gotoxy(x2-1,y); cprintf("%c",ris[5]);
     gotoxy(x2+2,y); cprintf("%c",ris[5]);

     if (tip) {
       int i;
       gotoxy(x1,y-1); cprintf("%c",ris[6]);
       gotoxy(x1,y-2); cprintf("%c",ris[0]);
       gotoxy(x2+1,y-1); cprintf("%c",ris[6]);
       gotoxy(x2+1,y-2); cprintf("%c",ris[1]);
       for (i=x1+1, gotoxy(i,y-2); i<x2+1; i++)
         cprintf("%c",ris[4]);
     }
   }
  /* ----------------------------------- */
   void wait1(int x1,int y1,int x2,int y2,
              unsigned numProc,unsigned nextProc) {
     /* "Ждет" пока другой процесс "не войдет" в эту функцию. */
     /* После этого передает управление процессу NEW          */
     /* ----------------------------------------------------- */
     if (numProc==nextProc)  /* Если один процесс сортировки  */
       tr(x1,y1,x2,y2,numProc,NEW);
     else {                  /* Если два процесса сортировки  */
       s++;
       while (s<2)
         tr(x1,y1,x2,y2,numProc,nextProc);
       if (s==2) {
         s++;
         tr(x1,y1,x2,y2,numProc,NEW);
       } else s=0;
     }
     initCmpMov(x1,y1,x2,y2);
   }
  /* ------------------------------ */
   void w(int x1,int y1,int x2,int y2,
          int tipBorder,char* nameSort) {
     win(x1,y1,x2,y2,tipBorder);
     window(x1+2,y1-1,x2,y1-1);
     cprintf(" ");
     cprintf(nameSort);
     cprintf(" ");
     initCmpMov(x1,y1,x2,y2);
   }
  /* ------------------------------------------ */
   void initCmpMov(int x1,int y1,int x2,int y2) {
     if (y1<12) {
       cmp1=0; mov1=0;
     } else {
       cmp2=0; mov2=0;
     }
     window(x1+2,y1-1,x2,y1-1);
     gotoxy(x2-x1-2-20,1);
     cprintf(" cmp=────── mov=─────");
     printCmpMov(0,0,x1,y1,x2,y2);
   }
  /* --------------------------------- */
   void printCmpMov(int d_cmp,int d_mov,
           int x1,int y1,int x2,int y2) {
     /* Увеличивает значение нужных счетчиков: cmp1,cmp2,     */
     /* mov1, mov2, на d_cmp и d_mov, и печатает их значение  */
     /* ----------------------------------------------------- */
     int *c,*m;
     if (y1<12) {
       c=&cmp1; m=&mov1;
     } else {
       c=&cmp2; m=&mov2;
     }
     *c+=d_cmp; *m+=d_mov;
     window(x1+2,y1-1,x2,y1-1);
     gotoxy(x2-x1-17,1);
     cprintf("%d ",*c);
     gotoxy(x2-x1-6,1);
     cprintf("%d ",*m);
     window(x1,y1,x2,y2);
   }
  /* ------------------- */
   void cmp_n_pause(int n,
           int x1,int y1,int x2,int y2,unsigned i1,unsigned i2) {
     if (0<pause&&pause<=MAX_PAUSE)
       while (n-->0)
         tr(x1,y1,x2,y2,i1,i2);
   }
   /* -------------------------------------------------------- */
   /*                 АЛГОРИТМЫ СОРТИРОВКИ                     */
   /* -------------------------------------------------------- */
   void bubble1(void) {
   /* Демонстрация сортировки методом простого обмена */
   /* (первый способ)                                 */
   /* ----------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[0]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (i=0;i<N;i++)   /* Сортировка*/
         for (j=N-1;j>i;j--) {
           cmp(j-1, j, m[j-1]>m[j], " > ",
               x1,y1,x2,y2, numProc,nextProc);
           if (m[j-1]>m[j]) {
             obmen(&m[j-1],&m[j]);
             obmen1(j-1,j,x1,y1,x2,y2,numProc,nextProc);
           }
         }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ---------------- */
   void bubble2(void) {
   /* Демонстрация сортировки методом простого обмена */
   /* (второй способ)                                 */
   /* ----------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j,
         f,    /* Если был обмен, то f=1, иначе - f=0 */
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[1]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (f=1,i=0;i<N&&f;i++)  /* Сортировка */
         for (f=0,j=N-1;j>i;j--) {
           cmp(j-1, j, m[j-1]>m[j], " > ",
               x1,y1,x2,y2, numProc,nextProc);
           if (m[j-1]>m[j]) {
             f=1;
             obmen(&m[j-1],&m[j]);
             obmen1(j-1,j,x1,y1,x2,y2,numProc,nextProc);
           }
         }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* -------------------- */
   void sortChoice1(void) {
   /* Демонстрация сортировки методом простого выбора */
   /* (первый способ)                                 */
   /* ----------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j, k,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[2]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (i=0;i<N-1;i++) {   /* Сортировка */
         k=i;
         for (j=i+1;j<N;j++) {
           cmp(k, j, m[k]>m[j], " > ",
               x1,y1,x2,y2, numProc,nextProc);
           if (m[j]<m[k])
             k=j;
         }
         cmp(i, k, m[i]!=m[k], " != ",
             x1,y1,x2,y2, numProc,nextProc);
         if (k!=i) {
           obmen(&m[k],&m[i]);
           obmen1(i,k,x1,y1,x2,y2,numProc,nextProc);
         }
       }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* -------------------- */
   void sortInsertM(void) {
   /* Демонстрация сортировки простыми включениями             */
   /* Алгоритм изменен: выбираемый (на каждом шагу внешнего    */
   /* цикла) элемент, не хранится в отдельной переменной, пока */
   /* не будет найдено его место в начале массива, а переме-   */
   /* щается, меняясь с соседним, пока не доберется до своего  */
   /* места                                                    */
   /* -------------------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[3]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (i=1;i<N;i++) {     /* Сортировка */
         for (j=i-1;j>=0&&m[j]>m[j+1];j--) {
           cmp(j, j+1, m[j]>m[j+1], " > ",
               x1,y1,x2,y2, numProc,nextProc);
           obmen1(j,j+1,x1,y1,x2,y2,numProc,nextProc);
           obmen(&m[j],&m[j+1]);
         }
         if (j!=-1)
           cmp(j, j+1, m[j]>m[j+1], " > ",
               x1,y1,x2,y2, numProc,nextProc);
       }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ------------------- */
   void sortInsert(void) {
   /* Демонстрация сортировки простыми включениями */
   /* -------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j, x,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[4]);  /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (i=1;i<N;i++) {      /* Сортировка */
         x=m[i];
         movKlad(i,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         for (j=i-1;j>=0&&x<m[j];j--) {
           cmpKlad(j,i,m[j]>x," > ",
               x1,y1,x2,y2, numProc,nextProc);
           mov(j,j+1,0,x1,y1,x2,y2,numProc,nextProc);
           m[j+1]=m[j];
         }
         if (j!=-1)
           cmpKlad(j,i,m[j]>x," > ",
               x1,y1,x2,y2, numProc,nextProc);
         m[j+1]=x;
         movKlad(j+1,i,0,0,x1,y1,x2,y2,numProc,nextProc);
       }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ---------------------- */
   void sortBinInsert(void) {
   /* Демонстрация сортировки бинарными включениями */
   /* --------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N],i,j,x,mm,l,r,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[5]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       for (i=1;i<N;i++) {     /* Сортировка */
         x=m[i]; l=0; r=i-1;
         movKlad(i,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         while (l<=r) {
           mm=(l+r)/2;
           cmpKlad(mm,i,m[mm]>x," > ",
               x1,y1,x2,y2, numProc,nextProc);
           if (x<m[mm])
             r=mm-1;
           else
             l=mm+1;
         }
         for (j=i-1;j>=l;j--) {
           mov(j,j+1,0,x1,y1,x2,y2,numProc,nextProc);
           m[j+1]=m[j];
         }
         m[l]=x;
         movKlad(l,i,0,0,x1,y1,x2,y2,numProc,nextProc);
       }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* --------------------- */
   void qSortRecProc(void) {
   /* Демонстрация рекурсивной реализации алгоритма */
   /* быстрой сортировки                            */
   /* --------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N], i, j,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[6]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       qSortRec(0,N-1,m,
                x1,y1,x2,y2,numProc,nextProc); /* Сортировка */
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ----------------------------- */
   void qSortRec(int l,int r,int *p,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
      int i=l,j=r,k,x=p[k=(l+r)/2];
      movKlad(k,k,1,1,x1,y1,x2,y2, numProc,nextProc);
      do {
         while (p[i]<x) {
           cmpKlad(i,k,p[i]<x," < ",
               x1,y1,x2,y2,numProc,nextProc);
           i++;
         }
         cmpKlad(i,k,p[i]<x," < ",
             x1,y1,x2,y2,numProc,nextProc);
         while (x<p[j]) {
           cmpKlad(j,k,p[j]>x," > ",
               x1,y1,x2,y2,numProc,nextProc);
           j--;
         }
         cmpKlad(j,k,p[j]>x," > ",
             x1,y1,x2,y2,numProc,nextProc);
         if (i<=j) {
           obmen(&p[i],&p[j]);
           obmen1(i,j,x1,y1,x2,y2,numProc,nextProc);
           i++; j--;
	 }
      } while (i<=j);
      delElement(k,1);
      if (l<j)
	qSortRec(l,j,p,x1,y1,x2,y2,numProc,nextProc);
      if (i<r)
	qSortRec(i,r,p,x1,y1,x2,y2,numProc,nextProc);
   }
  /* ----------------- */
   void heapSort(void) {
   /* Реализация алгоритма пирамидальной сортировки */
   /* --------------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N],i,l,r,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[7]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       l=N/2+1;
       r=N;
       while (l>1)
          hSort(m,--l,r,x1,y1,x2,y2,numProc,nextProc);
       while (r>1) {
         obmen(&m[0],&m[--r]);
         obmen1(0,r,x1,y1,x2,y2,numProc,nextProc);
         hSort(m,l,r,x1,y1,x2,y2,numProc,nextProc);
       }
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* -------------------------- */
   void hSort(int *a,int l,int r,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
      int i,j,x,k;
      i=l; j=2*i; x=a[k=i-1];
      movKlad(k,k,1,0,x1,y1,x2,y2,numProc,nextProc);
      while (j<=r)
        {
          if (j<r) {
            cmp(j-1,j,a[j-1]<a[j]," < ",
               x1,y1,x2,y2, numProc,nextProc);
            if (a[j-1]<a[j])
              j++;
          }
          cmpKlad(j-1,k,a[j-1]<=x," <= ",
               x1,y1,x2,y2, numProc,nextProc);
          if (x>=a[j-1])
            break;
          mov(j-1,i-1,0,x1,y1,x2,y2,numProc,nextProc);
          a[i-1]=a[j-1]; i=j; j=2*i;
        }
      a[i-1]=x;
      movKlad(i-1,k,0,0,x1,y1,x2,y2,numProc,nextProc);
   }
  /* ---------------------- */
   void mergeSortProc(void) {
   /* Реализация алгоритма сортировки слиянием */
   /* ---------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N],i,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[8]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       mergeSort(m,0,N-1,x1,y1,x2,y2,numProc,nextProc);
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ------------------------------ */
   void mergeSort(int *a,int l,int r,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
     if (l<r)
     {
       mergeSort(a,l,(l+r)/2,x1,y1,x2,y2,numProc,nextProc);
       mergeSort(a,(l+r)/2+1,r,x1,y1,x2,y2,numProc,nextProc);
       mergeList(a,l,(l+r)/2,(l+r)/2+1,r,
                   x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ---------------------------------------------- */
   void mergeList(int* a,int l1,int r1,int l2,int r2,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
     int l=l1,i,temp0[N];
     for (i=l; l1<=r1&&l2<=r2; i++) {
       cmp(l1,l2,a[l1]<a[l2]," < ",
               x1,y1,x2,y2, numProc,nextProc);
       if (a[l1]<a[l2]) {
         movKlad(l1,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp0[i]=a[l1++];
       } else {
         movKlad(l2,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp0[i]=a[l2++];
       }
     }
     /* Перенос оставшейся части "списка" */
     if (l1<=r1)
       for (; l1<=r1; i++,l1++) {
         movKlad(l1,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp0[i]=a[l1];
       }
     else
       for (; l2<=r2; i++,l2++) {
         movKlad(l2,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp0[i]=a[l2];
       }
     /* Возвращение результата в массив a */
     for (i=l; i<=r2; i++) {
       movKlad(i,i,0,0,x1,y1,x2,y2,numProc,nextProc);
       a[i]=temp0[i];
     }
   }
  /* ----------------------- */
   void mergeSortProc1(void) {
   /* Реализация алгоритма сортировки слиянием. */
   /* Модификация 1                             */
   /* ----------------------------------------- */
     int numProc=i1++, nextProc=i2--, m[N],i,
         x1=2,    y1=py,
         x2=78,   y2=y1+7;
     py+=10;
     w(x1,y1,x2,y2,0,menu[9]); /* Название сортировки */
     for(;;) {
       gotoxy(1,6);
       for (i=0; i<N; i++)
         cprintf("%4d",m[i]=matr[i]);
       mergeSort1(m,0,N-1,x1,y1,x2,y2,numProc,nextProc);
       wait1(x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ------------------------------- */
   void mergeSort1(int *a,int l,int r,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
     if (l<r)
     {
       mergeSort1(a,l,(l+r)/2,x1,y1,x2,y2,numProc,nextProc);
       mergeSort1(a,(l+r)/2+1,r,x1,y1,x2,y2,numProc,nextProc);
       mergeList1(a,l,(l+r)/2,(l+r)/2+1,r,
                   x1,y1,x2,y2,numProc,nextProc);
     }
   }
  /* ----------------------------------------------- */
   void mergeList1(int* a,int l1,int r1,int l2,int r2,
                 int x1,int y1,int x2,int y2,
                 unsigned numProc,unsigned nextProc) {
     int l=l1,i,temp1[N];
     for (i=l; l1<=r1&&l2<=r2; i++) {
       cmp(l1,l2,a[l1]<a[l2]," < ",
               x1,y1,x2,y2, numProc,nextProc);
       if (a[l1]<a[l2]) {
         movKlad(l1,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp1[i]=a[l1++];
       } else {
         movKlad(l2,i,1,0,x1,y1,x2,y2,numProc,nextProc);
         temp1[i]=a[l2++];
       }
     }
     /* Перенос оставшейся части "списка" (если нужно!). */
     /* Перенос на нужное место в массив m, а не в temp1 */
     if (l1<=r1)
       for (; l1<=r1; r1--,r2--) {
         mov(r1,r2,0,x1,y1,x2,y2,numProc,nextProc);
         a[r2]=a[r1];
       }
     /* Возвращение результата в массив a */
     for (; l<i; l++) {
       movKlad(l,l,0,0,x1,y1,x2,y2,numProc,nextProc);
       a[l]=temp1[l];
     }
   }
   /* -------------------------------------------------------- */
   /* Для добавления нового алгоритма сортировки нужно:        */
   /*     (1) увеличить значение константы LEN_MENU на 1,      */
   /*     (2) добавить название алгоритма в массив *menu[],    */
   /*     (3) добавить новую функцию void <имя>(void), в       */
   /*         которой реализован нужный алгоритм сортировки,   */
   /*         (функция должна быть "похожа" на bubble1).       */
   /*     (4) добавить элемент (имя новой функции сортировки)  */
   /*         в массив *proc[],                                */
   /*     (5) добавить элемент в массив m_dostup[]:            */
   /*         1 - сортировку м. запускать первым процессом,    */
   /*         0 - сортировку нельзя запускать первым процессом,*/
   /*             (функция сортировки рекурсивная!),           */
   /* Максимальное значение константы LEN_MENU должно не пре-  */
   /* вышать M_H + 1. (По умолчанию <=22.)                     */
   /* -------------------------------------------------------- */
