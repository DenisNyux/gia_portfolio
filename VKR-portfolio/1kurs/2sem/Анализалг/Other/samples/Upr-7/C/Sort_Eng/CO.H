   /* ���� co.h.           */
   /* �����প� ᮯணࠬ� */
   /* -------------------- */

#ifndef  __CO_H
   #define  __CO_H

   #include <stdio.h>
   #include <alloc.h>
   #include <setjmp.h>

   void newProcess(void (*)(), unsigned int, unsigned int);
   void transfer(unsigned int, unsigned int);
   void delAllProcess(void);
   void delProcess(unsigned int);
   void join(unsigned int, unsigned int);
   int isAlive(unsigned int);

   struct Co_Process
   {
     void (*proc)();
     unsigned int shift;
     jmp_buf buf;
     unsigned int ident;
     struct Co_Process *next;
   } *co_process=NULL;
  /* ------------------------------------------------------- */
  /* ��������� �㭪樨-ᮯணࠬ��                         */
  /* ------------------------------------------------------- */
   void newProcess(void (*proc)(),unsigned int ident,
                                  unsigned int shift)
   /* proc - ���  �㭪樨-ᮯணࠬ��,  ident  - ����ࠫ쭮� */
   /* �᫮  (��ࠢ��� ���),  ���஥ ������  ��������- */
   /* ���� ᮧ������� �����,  shift -  ���ᨬ��쭮� �᫮ */
   /* ᫮�, ���஥ �� ����� ������������ ��� �⥪� ��뢠- */
   /* �饣� �����                                         */
   /* ------------------------------------------------------ */
   {
     struct Co_Process *p;
     if (co_process==NULL)
       (co_process=(struct Co_Process *)
                              calloc(sizeof(struct Co_Process),1)
       )->next=NULL;
     p=co_process;
     for(; (*p).next!=NULL&&(*(*p).next).ident!=ident;
                                                    p=(*p).next);
     if ((*p).next==NULL)
       ((*p).next=(struct Co_Process *)
                              calloc(sizeof(struct Co_Process),1)
       )->next=NULL;
     p=(*p).next;
     (*p).proc=proc;
     (*p).shift=shift;
     (*p).ident=ident;
   }
  /* --------------------------------------------------- */
  /* �㭪�� ��।�� �ࠢ�����                         */
  /* --------------------------------------------------- */
   void transfer(unsigned int ident1, unsigned int ident2)
   /* �㭪�� ��।��� �믮������ �� ����� ident1 ��㣮�� */
   /* ������ ident2                                        */
   /* ------------------------------------------------------ */
   {
     struct Co_Process *p1,*p2;
     p1=p2=co_process;
     for (; (*p2).next!=NULL&&(*(*p2).next).ident!=ident2;
                                                  p2=(*p2).next);
     if ((*p2).next==NULL) return;
     p2=(*p2).next;
     /* ## (*p2).ident==ident2 */
     for (; (*p1).next!=NULL&&(*(*p1).next).ident!=ident1;
                                                  p1=(*p1).next);
     if ((*p1).next==NULL)
     {
       ((*p1).next=(struct Co_Process *)
                              calloc(sizeof(struct Co_Process),1)
       )->next=NULL;
       p1=(*p1).next;
       (*p1).proc=0;
       (*p1).ident=ident1;
     } else
       p1=(*p1).next;
     if (setjmp((*p1).buf)==0)
       if ((*p2).proc)
       {
         int i=0;
         void (*p)(void);
         p=(*p2).proc;
         (*p2).proc=0;
         for (; i<(*p2).shift; i++)
           asm push i;
         p();
         delProcess(ident2);
         longjmp((*p1).buf,(*p1).ident);
       } else
         longjmp((*p2).buf,(*p2).ident);
   }
  /* -------------------- */
   void delAllProcess(void)
   /* �㭪�� 㤠��� �� ������ */
   /* ---------------------------- */
   {
     for (; co_process!=NULL; co_process=(*co_process).next)
       free(co_process);
     co_process=NULL;
   }
  /* ------------------------------- */
   void delProcess(unsigned int ident)
   /* �㭪�� 㤠��� ����� c ����஬ ident */
   /* --------------------------------------- */
   {
     struct Co_Process *p,*pd;
     p=co_process;
     for (; (*p).next!=NULL&&(*(*p).next).ident!=ident;
                                                    p=(*p).next);
     if ((*p).next!=NULL)
     {
       pd=(*p).next;
       (*p).next=(*(*p).next).next;
       free(pd);
     }
   }
  /* ------------------------------------------------------- */
  /* �㭪�� �������� �����襭�� �����                    */
  /* ------------------------------------------------------- */
   void join(unsigned int ident1, unsigned int ident2)
   /* �㭪�� �������  �����襭�� ����� ident2 (��  ��-  */
   /* ��� ident1). ���: ident1 -  �����䨪��� �����,  */
   /* �� ���ண� �맢��� ᠬ� �㭪�� join().               */
   /* �᫨ ����� ident2 ��室���� � ���ﭨ�:             */
   /*    0, � �㭪�� �ࠧ� �����頥� �ࠢ�����;          */
   /* 1, 2, � �㭪��  ��।��� �ࠢ����� ������ �� ��  */
   /*       ���, ���� ����� �� ��������� (�.�. �� ��३-  */
   /*       ��� � ���ﭨ� 0);                              */
   /* ------------------------------------------------------ */
   {
     while(isAlive(ident2)!=0) transfer(ident1,ident2);
   }
  /* ------------------------------------------------------- */
  /* �㭪�� �஢�ન ���ﭨ� �����                     */
  /* ------------------------------------------------------- */
   int isAlive(unsigned int ident)
   /* �㭪�� �����頥� ��ਡ�� ⥪�饣� ���ﭨ� ����� */
   /* ident:                                                 */
   /*  0 - ����� �� ��ॣ����஢�� �㭪樥�  newProcess() */
   /*      ��� ��������� �����稫  ᢮� �믮������ (���  ��� */
   /*      ����୮��  ����᪠, �� �㦤����� � ����୮� �- */
   /*      �����樨 (�㭪樥� newProcess()) � ��।��  �- */
   /*      ࠢ����� (�㭪樥� transfer()));                  */
   /*  1 - ����� ��ॣ����஢�� �㭪樥� newProcess(), �� */
   /*      ��� �� ��砫  �믮�������  (�. �. �� �뫮 �맮��� */
   /*      �㭪樨 transfer());                              */
   /*  2 - ����� �믮������                               */
   /* ------------------------------------------------------ */
   {
     if (co_process==NULL) return 0;
     else
     {
       struct Co_Process *p=(*co_process).next;
       for (; p!=NULL&&(*p).ident!=ident; p=(*p).next);
       return p==NULL?0:((*p).proc==0?2:1);
     }
   }

#endif     /*  __CO_H  */
