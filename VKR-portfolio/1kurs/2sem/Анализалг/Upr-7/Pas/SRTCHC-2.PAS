   PROGRAM SortChoice_2;
   { ����஢�� ��⮤�� ���⮣� �롮� (��ன ᯮᮡ) }
      uses  CRT;
      const N=8;
      type  Index=1..N;
            Massiv=Array[Index] of Integer;
      var   A: Massiv;
            i: Index;
            c: Char;
  { ------------------------------------------------ }
   FUNCTION Imin(Start: Integer; A: Massiv): Integer;
   { �㭪�� ��室�� ��������� ������� "�ࠢ��" Start }
   { (������ Start) � �����頥� ��� �����             }
      var m,i: Integer;
   BEGIN
      m:=Start;
      For i:=Start+1 to N do
        If A[i]<A[m] then m:=i;
      Imin:=m
   END;
  { ------------------------------- }
   PROCEDURE Swap(var a,b: Integer);
   { ��楤�� ������ ���祭�ﬨ ���� ��६����� }
      var c: Integer;
   BEGIN
      c:=a; a:=b; b:=c
   END;
  { ----------------------------------- }
   PROCEDURE Sort_Choice(var t: Massiv);
   { ��楤�� ���஢�� �롮஬ }
      var i: Integer;
   BEGIN
      For i:=1 to N-1 do
        Swap(A[Imin(i,A)],A[i])
   END;
  { --- }
   BEGIN
      Write('��室�� ���ᨢ: '); For i:=1 to N do Read(A[i]);
      Sort_Choice(A);
      Write('������� ���஢��: ');
      For i:=1 to N do Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
