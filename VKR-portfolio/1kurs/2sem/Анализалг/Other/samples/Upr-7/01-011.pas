   { Демонстрация однопроходного алгоритма для определения }
   { наибольшей по длине последовательности идущих  подряд }
   { одинаковых элементов одномерного массива              }
   { ----------------------------------------------------- }
   PROGRAM Primer_11;
      Uses  Crt;
      const n=20;
            r=2;
      type  Arr=Array[1..n] of Integer;
      var   a       : Arr;
            j,m,k,k1: Integer;
            c       : Char;
   { -------------------- }
   BEGIN
      Randomize;
      For j:=1 to n do 
        a[j]:=Random(r);
      For j:=1 to n do 
        Write(a[j],' ');
      WriteLn;
      m:=a[1]; k:=1; k1:=1;
      For j:=2 to n do
        If m<>a[j]
          then begin
                 m:=a[j];
                 If k1<k
                   then k1:=k;
                 k:=1
               end
          else if m=a[j]
                 then k:=k+1;
      If k1<k
        then k1:=k;
      WriteLn; WriteLn('Результат: ',k1);
      ReadKey
   END.
