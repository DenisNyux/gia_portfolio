   { Сортировка методом простого выбора }
   { (первый способ)                    }
   { ---------------------------------- }
   PROGRAM SortChoice_1;
      uses  CRT;
      const N=8;
      type  Index=1..N;
            Massiv=Array[Index] of Integer;
       var  x      : Integer;
            A      : Massiv;
            i,j,k,m: Index;
            c      : Char;
   BEGIN
      Write('Исходный массив: ');
      For i:=1 to N do
         Read(A[i]);
      { -------------------------------------------------- }
      { Начало алгоритма сортировки простым выбором        }
      { -------------------------------------------------- }
      WriteLn ('Изменение массива в процессе сортировки: ');
      WriteLn;
      For i:=1 to N-1 do
         begin
            k:=i; x:=A[i];
            For j:=i+1 to N do
              If A[j]<x
                then begin k:=j; x:=A[j] end;
            A[k]:=A[i]; A[i]:=x;
            For m:=1 to N do
               Write(A[m],' ');
            WriteLn
         end;
      WriteLn;
      { ---------------------------------------------- }
      { Окончание алгоритма сортировки простым выбором }
      { ---------------------------------------------- }
      Write('Результат сортировки: ');
      For i:=1 to N do
         Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
