   PROGRAM BubbleSort_2;
   { ����஢�� ��⮤�� ���⮣� ������ (��ன ᯮᮡ) }
      uses  CRT;
      const N=8;
      type  Index=1..N;
            Massiv=Array[Index] of Integer;
      var   x  : Integer;
            A  : Massiv;
            i,j: Index;
            c  : Char;
  { ------------------------------- }
   PROCEDURE Swap(var a,b: Integer);
   { ��楤�� ������ ���祭�ﬨ ���� ��६����� }
      var c: Integer;
   BEGIN
      c:=a; a:=b; b:=c
   END;
  { ---------------------------------- }
   PROCEDURE BubbleSort(var A: Massiv);
      var i,j,k: Index;
          f    : Boolean; { �᫨ �� �����, � f=TRUE,   }
                          { � ��⨢��� ��砥 - f=FALSE }
   BEGIN
      f:=TRUE; i:=N-1;
      While (i>=1) AND f do
        begin
          f:=FALSE;
          For j:=1 to i do
            If A[j]>A[j+1]
              then begin
                      f:=TRUE; Swap(A[j],A[j+1]);
                      For k:=1 to N do Write(A[k],' ');
                      WriteLn
                   end;
          i:=i-1
        end
   END;
  { --- }
   BEGIN
      Write('��室�� ���ᨢ: '); For i:=1 to N do Read(A[i]);
      WriteLn('��������� ���ᨢ� � ����� ���஢��: ');
      BubbleSort(A);
      Write('������� ���஢��: ');
      For i:=1 to N do Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
