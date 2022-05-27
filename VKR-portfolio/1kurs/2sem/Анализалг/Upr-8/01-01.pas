   { Демонстрация однопроходного алгоритма для определения }
   { наибольшей по длине последовательности идущих  подряд }
   { одинаковых элементов одномерного массива              }
   { ----------------------------------------------------- }
   PROGRAM Primer_1;
      Uses CRT;
      const N=35;
      var   A    : Array[1..N] of Integer;
            i,
            Flag,
            k,m  : Integer;
   { -------------------- }
   BEGIN
      Randomize;
      For i:=1 to N do 
        A[i]:=Random(2);
      For i:=1 to N do 
        Write(A[i],' ');
      WriteLn; k:=1; Flag:=0;
      For i:=1 to n-1 do
        begin
          If A[i]=A[i+1]
            then begin k:=k+1; m:=k end
            else begin m:=k; k:=1   end;
          If m>Flag
            then Flag:=m
        end;
      WriteLn('Flag=',Flag);
      ReadKey
   END.
