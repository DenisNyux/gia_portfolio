   PROGRAM SortBinInsert;
   { ����஢�� �����묨 ����祭�ﬨ }
      uses  CRT;
      const N=8;
      type  index=0..N;
            Massiv=Array[1..N] of Integer;
      var   x        : Integer;
            A        : massiv;
            i,j,l,r,m: index;
            c        : Char;
   BEGIN
      Write('��室�� ���ᨢ: '); For i:=1 to N do Read(A[i]);
      { ��砫� �����⬠ ���஢�� �����묨 ����祭�ﬨ }
      For i:=2 to N do
        begin
           x:=A[i]; l:=1; r:=i-1;
           While l<=r do
             begin
                m:=(l+r) DIV 2;
                If x<A[m] then r:=m-1 else l:=m+1
             end;
           For j:=i-1 downto l do
             A[j+1]:=A[j];
           A[l]:=x
        end;
      { ����砭�� �����⬠ ���஢�� �����묨 ����祭�ﬨ }
      Write('������� ���஢��: ');
      For i:=1 to N do Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
