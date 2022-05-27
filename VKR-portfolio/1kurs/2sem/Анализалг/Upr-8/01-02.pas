   { Демонстрация поиска количества максимальных элемен- }
   { тов в массиве с помощью однопроходного алгоритма    }
   { --------------------------------------------------- }
   PROGRAM Primer_2;
      Uses CRT;
      const n=10;
            r=10;
      type  Arr=Array[1..n] of Integer;
      var   A    : Arr;
      var   j,m,k: Integer;
   { -------------------- }
   BEGIN
      Randomize;
      For j:=1 to n do 
        A[j]:=Random(r);
      For j:=1 to n do 
        Write(A[j]:2,' ');
      WriteLn;
      m:=A[1]; k:=1;
      For j:=2 to n do
        if m<A[j]
          then begin m:=A[j]; k:=1 end
          else if m=A[j]
                 then k:=k+1;
      WriteLn; WriteLn('Результат: ',k);
      ReadKey
   END.
