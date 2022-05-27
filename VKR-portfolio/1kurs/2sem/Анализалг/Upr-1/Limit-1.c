   /* Демонстрация функции, вычисляющей */
   /* к о н е ч н ы й  предел вида      */
   /*                                   */
   /*   lim  f(x)=b=?                   */
   /*   x->x0                           */
   /*                                   */
   /* Автор: М.В.Швецкий (26.05.2013)   */
   /* --------------------------------- */
   #include<stdio.h>
   #include<math.h>
   #include<conio.h>
      double f (double);
   /* --------------- */
   int main()
   {
      double x0,
	     x1,x2,
	     delta=0.5,
	     eps=0.00001;
      /* ------------------------------------------------- */
      printf("Введите предельную точку: "); scanf("%lg",&x0);
      x1=x0-delta; x2=x0+delta;
      while (fabs(fabs(f(x1))-fabs(f(x2)))>eps)
      {
	delta=delta/2; x1=x0-delta; x2=x0+delta;
	printf("(%g, %g); (%g, %g)\n",x1,f(x1),x2,f(x2));
      }
      printf("Результат: %g\n",(f(x1)+f(x2))/2);
      getch();
      return 0;
   }
   /* ------------- */
   double f (double x)
   {
      return // x*x*sin(1.0/x);
	     // pow(log(1+x)/6/x,x/(x+2));
	     // (pow(3,5*x-3)-pow(3,2*x*x))/tan(M_PI*x);
	     //	(exp(7*x)-exp(-2*x))/(sin(x)-2*x);
	     //	1/x/x-1/tan(x)/tan(x);
	      sin(1.0/(x+0.001));
   }
