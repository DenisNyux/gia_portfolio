   { Демонстрация однопроходного алгоритма нахождения  чаще }
   { всего встречающегося элемента в целочисленном одномер- }
   { ном массиве, который содержит N элементов, а некоторый }
   { элемент встречается в массиве более N/2 раз            }
   { ------------------------------------------------------ }
   PROGRAM Primer_3;
      Uses  CRT;
      const N=11;
       type R=1..N;
            Q=Array[R] of Integer;
        var A: Q;
            k: Integer;
            i: Integer; { Перемещение по массиву             }
            m: Integer; { Переменная для хранения количества }
                        { повторений элемента массива        }
   { ------------------------------------------------------- }
   BEGIN
      Randomize;
      Write('Исходный массив: ');
      k:=1;
      While k<=N do
        begin A[k]:=Random(3)+1; k:=k+2 end;
      k:=2;
      While k<=N do
        begin A[k]:=Random(3)+1; k:=k+2 end;
      For k:=1 to N do
        Write(A[k]:2,' ');
      WriteLn;
      { ------- }
      k:=0; i:=0;
      While i<>N do
        If k=0
          then begin k:=1; m:=i+1; i:=i+1 end
          else If A[i+1]=A[m]
                 then begin i:=i+1; k:=k+1 end
                 else begin i:=i+1; k:=k-1 end;
      WriteLn;
      Write('Результат будет неверным, если массив ');
      WriteLn('"устроен" неправильно!');
      Write('Результат      : ',A[m]:2,' '); WriteLn;
      ReadKey
   END.
