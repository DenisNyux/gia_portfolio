   /* ���������� 䨡����稥�� ���᪠ ������ ��������� */
   /* ������� ������୮�� 㯮�冷祭���� �� �����⠭�� */
   /* �᫮���� ���ᨢ�                                  */
   /* (� � � � � � � � � � � � �  ��ਠ��)               */
   /* -------------------------------------------------- */
   #include<stdio.h>
   #include<conio.h>
   #define N 7         /* ������⢮ ������⮢ � ���ᨢ� */
      long fib (long);
  /* --------------- */
   int main()
   {
      int a[N],   /* ��室�� ���ᨢ                       */
          x,      /* �᪮�� �������                       */
          finish, /* ����: 0 - ������� ������              */
          i,      /* ��ࠬ��� 横��                        */
          f1,f2,  /* �������� ��᫥����⥫쭮�� �������� */
          t,      /* �ᯮ����⥫쭠� ��६�����            */
          mid,
          b[N];   /* �ᯮ����⥫�� ���ᨢ  ���  �࠭���� */
                  /* �ᥫ ��������                       */
      /* ------------------------------------------------- */
      printf("������ ���ᨢ �� %u ������⮢, ",N);
      printf("㯮�冷祭�� �� �����⠭��:\n");
      for (i=0; i<N; i++)
        scanf("%u",&a[i]);
      printf("������ ���ᨢ: ");
      for (i=0; i<N; i++)
        printf("%u ",a[i]);
      printf("\n�᪮�� �������: "); scanf("%u",&x);
      /* ---------------------------------------- */
      for (i=1,b[1]=1; (b[i]=fib(i))<N+1; i++)
        ;
      mid=N-b[i-2]+1; f1=b[i-2]; f2=b[i-3];
      finish=0;
      while (x!=a[mid-1] && !finish)
        if (mid<=0 || x>a[mid-1])
          if (f1==1)
            finish=1;
          else {
                 mid=mid+f2; f1=f1-f2; f2=f2-f1;
               }
        else if (f2==0)
               finish=1;
             else {
                    mid=mid-f2; t=f1-f2; f1=f2; f2=t;
                  }
      if (!finish)
        printf("������� ������; ��� �����: %u\n",mid-1);
      else printf("������� �� ������.\n");
      getch();
      return 0;
   }
  /* ------------ */
   long fib(long x)
   /* ��४��ᨢ��� �㭪��  ���  ���᫥���  n-�� ������� */
   /* ��᫥����⥫쭮�� �������� � �ᯮ�짮������ ���ᨢ� */
   /* ----------------------------------------------------- */
   {
      long i,a[3];
      /* ------ */
      if (x<3)
        return 1;
      a[1]=a[0]=1;
      for (i=2; i<x; ++i)
      {
        a[2]=a[0]+a[1]; a[0]=a[1]; a[1]=a[2];
      }
      return a[2];
   }
