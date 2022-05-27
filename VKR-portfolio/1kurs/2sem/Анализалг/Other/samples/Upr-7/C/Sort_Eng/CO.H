   /* Файл co.h.           */
   /* Поддержка сопрограмм */
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
  /* Регистрация функции-сопрограммы                         */
  /* ------------------------------------------------------- */
   void newProcess(void (*proc)(),unsigned int ident,
                                  unsigned int shift)
   /* proc - имя  функции-сопрограммы,  ident  - натуральное */
   /* число  (неравное нулю),  которое должно  идентифициро- */
   /* вать создаваемый процесс,  shift -  максимальное число */
   /* слов, которое еще может понадобиться для стека вызыва- */
   /* ющего процесса                                         */
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
  /* Функция передачи управления                         */
  /* --------------------------------------------------- */
   void transfer(unsigned int ident1, unsigned int ident2)
   /* Функция передает выполнение от процесса ident1 другому */
   /* процессу ident2                                        */
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
   /* Функция удаляет все процессы */
   /* ---------------------------- */
   {
     for (; co_process!=NULL; co_process=(*co_process).next)
       free(co_process);
     co_process=NULL;
   }
  /* ------------------------------- */
   void delProcess(unsigned int ident)
   /* Функция удаляет процесс c номером ident */
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
  /* Функция ожидания завершения процесса                    */
  /* ------------------------------------------------------- */
   void join(unsigned int ident1, unsigned int ident2)
   /* Функция ожидает  завершение процесса ident2 (на  про-  */
   /* цессе ident1). Где: ident1 -  идентификатор процесса,  */
   /* из которого вызвана сама функция join().               */
   /* Если процесс ident2 находится в состоянии:             */
   /*    0, то функция сразу возвращает управление;          */
   /* 1, 2, то функция  передает управление процессу до тех  */
   /*       пор, пока процесс не завершится (т.е. не перей-  */
   /*       дет в состояние 0);                              */
   /* ------------------------------------------------------ */
   {
     while(isAlive(ident2)!=0) transfer(ident1,ident2);
   }
  /* ------------------------------------------------------- */
  /* Функция проверки состояния процесса                     */
  /* ------------------------------------------------------- */
   int isAlive(unsigned int ident)
   /* Функция возвращает атрибут текущего состояния процесса */
   /* ident:                                                 */
   /*  0 - процесс не зарегистрирован функцией  newProcess() */
   /*      или полностью закончил  свое выполнение (для  его */
   /*      повторного  запуска, он нуждается в повторной ре- */
   /*      гистрации (функцией newProcess()) и передаче  уп- */
   /*      равления (функцией transfer()));                  */
   /*  1 - процесс зарегистрирован функцией newProcess(), но */
   /*      ещё не начал  выполняться  (т. е. не было вызовов */
   /*      функции transfer());                              */
   /*  2 - процесс выполняется                               */
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
