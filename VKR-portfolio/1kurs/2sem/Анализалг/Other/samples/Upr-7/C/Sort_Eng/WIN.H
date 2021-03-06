   /* ���� win.h.            */
   /* �����প� ���� � ࠬ�� */
   /* ---------------------- */
#ifndef  __WIN_H
   #define  __WIN_H

   #include <conio.h>

   void win(int,int,int,int,int);
   void delBorder(int,int,int,int);
  /* -------------------------------------------- */
  /* ��⠭���� ���� � �ᮢ���� ����� ���� ࠬ�� */
  /* -------------------------------------------- */
   void win(int x1,int y1,int x2,int y2,int tip)
   /* ��⠭�������� ���� � ���न��⠬� (x1,y1)-(x2,y2).     */
   /* tip - ⨯ ࠬ��.                                       */
   /* ����� ��⮢:          ���ᠭ��:                       */
   /*      0           ("⮫騭� ࠬ��")                     */
   /*                      0 - �����ୠ�, 1 - �������.       */
   /*                  �����������������������������Ŀ       */
   /*    1-4           ����祭���     ���� ࠬ��     �       */
   /*                  �����������������������������Ĵ       */
   /*                  �    0   � ���⫮-���       �       */
   /*                  �    1   � �����              �       */
   /*                  �    2   � ������            �       */
   /*                  �    3   � ����-������       �       */
   /*                  �    4   � ����            �       */
   /*                  �    5   � ��᭮-ᨭ��       �       */
   /*                  �    6   � ���筥��         �       */
   /*                  �    7   � ���⫮-���       �       */
   /*                  �    8   � �����-���        �       */
   /*                  �    9   � �મ-ᨭ��         �       */
   /*                  �   10   � �મ-������       �       */
   /*                  �   11   � �ન� ᨭ�-������ �       */
   /*                  �   12   � �મ-����       �       */
   /*                  �   13   � �ન� ��᭮-ᨭ�� �       */
   /*                  �   14   � �����             �       */
   /*                  �   15   � ����              �       */
   /*                  �������������������������������       */
   /* ------------------------------------------------------ */
   {
     char r[2][6]={{'�', '�', '�', '�', '�', '�'},
                   {'�', '�', '�', '�', '�', '�'}
                  };
     int i,attr=tip>>1;
     window(x1-1,y1-1,x2+2,y2+2);
     if (attr)
       textattr(attr);
     tip&=1;
     gotoxy(1,1);        cprintf("%c",r[tip][0]);
     for (i=0; i<=x2-x1; i++)
       cprintf("%c",r[tip][4]);
     cprintf("%c",r[tip][1]);
     gotoxy(1,y2-y1+3);  cprintf("%c",r[tip][2]);
     for (i=0; i<=x2-x1; i++)
       cprintf("%c",r[tip][4]);
     cprintf("%c",r[tip][3]);
     for (i=0; i<=y2-y1; i++)
     {
       gotoxy(1,i+2);        cprintf("%c",r[tip][5]);
       gotoxy(x2-x1+3,i+2);  cprintf("%c",r[tip][5]);
     }
     if (attr)
       textattr(7);
     window(x1,y1,x2,y2);
   }
  /* --------------------------------------- */
   void delBorder(int x1,int y1,int x2,int y2)
   /* ������ (��ࠥ�) ࠬ�� (�࠭���) � ��������� ���� */
   /* -------------------------------------------------- */
   {
     int i;
     window(x1-1,y1-1,x2+2,y2+2);
     gotoxy(1,1);
     for (i=0; i<x2-x1+3; i++)
       cprintf(" ");
     gotoxy(1,y2-y1+3);
     for (i=0; i<x2-x1+3; i++)
       cprintf(" ");
     for (i=0; i<=y2-y1; i++)
     {
       gotoxy(1,i+2);        cprintf(" ");
       gotoxy(x2-x1+3,i+2);  cprintf(" ");
     }
     window(x1,y1,x2,y2);
   }

#endif     /*  __WIN_H  */
