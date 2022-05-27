   { Ф и б о н а ч ч и е в  поиск наименьшего индекса за- }
   { данного  элемента  одномерного  "случайного"  строго }
   { упорядоченного по возрастанию числового массива      }
   { (рекурсивный вариант)                                }
   { ---------------------------------------------------- }
   PROGRAM Find_5;
      uses  CRT;
      const N = 8;            { Количество элементов в массиве }
      type  Massiv = Array [1..N] of Integer;
      var   A     : Massiv;   { Массив, отсортированный по  }
                              { возрастанию                 }
            Key   : Integer;  { Искомый элемент             }
            Search: 0..N;     { Индекс найденного элемента  }
                              { 0, если элемент не найден   }
            Mid    : Integer; { Индекс внутреннего элемента }
            j,i    : Integer;
            F1,F2,t: Integer;
            Finish : Boolean;
            c      : Char;
  { ------------------------------------ }
   FUNCTION  F_i_b (N: Integer): Integer;
      var F1,F2: Integer;
   BEGIN
      If (N=0) OR (N=1)
        then F_i_b:=N
        else If N>=2
               then begin
                       F1:=F_i_b (N-1); F2:=F_i_b (N-2);
                       F_i_b:=F1+F2
                    end
   END;
  { --- }
   BEGIN
      Write('Введите отсортированный массив: ');
      For i:=1 to N do
         Read(A[i]);
      Write('Искомый элемент: '); Read(Key);
      j:=1;
      While F_i_b(j)<N+1 do
         j:=j+1;
      Mid:=N-F_i_b(j-2)+1;
      F1:=F_i_b(j-2); F2:=F_i_b(j-3);
      Finish:=FALSE;
      While (Key<>A[Mid]) AND (Finish=FALSE) do
         If (Mid<=0) OR (Key>A[Mid])
           then If F1=1
                  then Finish:=TRUE
                  else begin
                          Mid:=Mid+F2; F1:=F1-F2; F2:=F2-F1
                       end
           else If F2=0
                  then Finish:=TRUE
                  else begin
                          Mid:=Mid-F2; t:=F1-F2; F1:=F2; F2:=t
                       end;
      If Finish
        then Search:=0 
        else Search:=Mid;
      WriteLn;
      WriteLn('Индекс искомого элемента в массиве: ',Search);
      c:=ReadKey
   END.
