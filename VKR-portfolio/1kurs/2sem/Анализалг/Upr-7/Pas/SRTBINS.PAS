   PROGRAM SortBinInsert;
   { Сортировка бинарными включениями }
      uses  CRT;
      const N=8;
      type  index=0..N;
            Massiv=Array[1..N] of Integer;
      var   x        : Integer;
            A        : massiv;
            i,j,l,r,m: index;
            c        : Char;
   BEGIN
      Write('Исходный массив: '); For i:=1 to N do Read(A[i]);
      { Начало алгоритма сортировки бинарными включениями }
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
      { Окончание алгоритма сортировки бинарными включениями }
      Write('Результат сортировки: ');
      For i:=1 to N do Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
