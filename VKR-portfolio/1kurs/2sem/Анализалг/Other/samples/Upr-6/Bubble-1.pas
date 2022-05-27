   { Сортировка методом простого обмена }
   { (первый способ)                    }
   { ---------------------------------- }
   PROGRAM BubbleSort_1;
      uses  CRT;
      const N=8;
      type  Index=1..N;
            Massiv=Array[Index] of Integer;
      var   x    : Integer;
            A    : Massiv;
            i,j,k: Index;
            c    : Char;
   BEGIN
      Write('Исходный массив: ');
      For i:=1 to N do
         Read(A[i]);
      { ------------------------------------------------- }
      { Начало алгоритма сортировки простым обменом       }
      { ------------------------------------------------- }
      WriteLn('Изменение массива в процессе сортировки: ');
      WriteLn;
      For i:=2 to N do
        For j:=n downto i do
          If A[j-1]>A[j]
            then begin
                    x:=A[j-1]; A[j-1]:=A[j]; A[j]:=x;
                    For k:=1 to N do
                       Write(A[k],' ');
                    WriteLn
                 end;
      WriteLn;
      { ---------------------------------------------- }
      { Окончание алгоритма сортировки простым обменом }
      { ---------------------------------------------- }
      Write('Результат сортировки: ');
      For i:=1 to N do
         Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
