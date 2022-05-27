   { Б и н а р н ы й  поиск наименьшего индекса заданного }
   { элемента одномерного "случайного" числового массива, }
   { строго упорядоченного по возрастанию                 }
   { (рекурсивный вариант)                                }
   { ---------------------------------------------------- }
   PROGRAM Find_4;
      uses  CRT;
      const N=8;               { Количество элементов }
       type Massiv = Array [1..N] of Integer;
        var A       : Massiv;  { Массив, отсортированный }
                               { по возрастанию          }
            Key     : Integer; { Искомый элемент         }
            i       : Integer;
            c       : Char;
   { ---------------------------- }
   FUNCTION BinSearch(A   : Massiv;
                      Low : Integer;
                      High: Integer;
                      X   : Integer): Integer;
      var Mid: Integer; { "Средний" индекс элементов массива }
   BEGIN
      If Low>High
        then BinSearch:=0
        else begin
                Mid:=(Low+High) DIV 2;
                If X=A[Mid]
                  then BinSearch:=Mid
                  else If X<A[Mid]
                         then BinSearch:=BinSearch(A,Low,Mid-1,X)
                         else BinSearch:=BinSearch(A,Mid+1,High,X)
             end
   END;
  { --- }
   BEGIN
      Write('Введите массив, отсортированный строго по возрастанию: ');
      For i:=1 to N do
        Read(A[i]);
      Write('Искомый элемент: '); Read(Key);
      WriteLn;
      If BinSearch(A,1,N,Key)=0
        then WriteLn('Искомый элемент не найден.')
        else WriteLn('Искомый элемент имеет в массиве индекс ',
                      BinSearch(A,1,N,Key));
      c:=ReadKey
   END.
