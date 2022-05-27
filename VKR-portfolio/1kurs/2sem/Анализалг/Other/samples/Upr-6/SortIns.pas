   { Сортировка простыми включениями }
   { ------------------------------- }
   PROGRAM SortInsert;
       uses  CRT;
       const N=8;
       type  Index=0..N;
             Massiv=Array[Index] of Integer;
       var   A    : Massiv;
             i,j,k: Index;
             c    : Char;
   BEGIN
      Write('Исходный массив: ');
      For i:=1 to N do
         Read(A[i]);
      { ------------------------------------------------- }      
      { Начало алгоритма сортировки простыми включениями  }
      { ------------------------------------------------- }
      WriteLn('Изменение массива в процессе сортировки: ');
      WriteLn;
      For i:=2 to N do
         begin
            A[0]:=A[i]; j:=i-1;
            While A[0]<A[j] do 
               begin A[j+1]:=A[j]; j:=j-1 end;
            A[j+1]:=A[0];
            For k:=1 to N do
               Write(A[k],' ');
            WriteLn
         end;
      WriteLn;
      { ----------------------------------------- }
      { Окончание сортировки простыми включениями }
      { ----------------------------------------- }
      Write('Результат сортировки: ');
      For i:=1 to N do
         Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
