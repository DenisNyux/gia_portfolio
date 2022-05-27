   { Линейный поиск наименьшего индекса заданного элемента }
   { одномерного "случайного" числового массива            }
   { ----------------------------------------------------- }
   PROGRAM Find_1;
      uses  CRT;
      const N=8;        { Количество элементов в массиве   }
      var   i: Integer; { Параметр циклов                  }
            Q: Boolean; { Флаг - результат поиска элемента }
            A: Array [1..N] of Integer;  { Исходный массив }
            X: Integer;                  { Искомый элемент }
            c: Char;
   BEGIN
      For i:=1 to N do
         A[i]:=Random(12)+1; { Случайный ввод массива }
      Write('Исходный массив: ');
      For i:=1 to N do 
         Write(A[i],' ');    { Контрольный вывод }
      WriteLn; Write('Искомый элемент: '); Read(X);
      i:=0;
      Repeat
         i:=i+1; Q:=(A[i]=X)
      until Q OR (i=N);
      WriteLn;
      If Q
        then begin
               Write('Элемент найден; его минимальный ');
               WriteLn('индекс в массиве: ',i)
             end
        else WriteLn('Элемент не найден.');
      c:=ReadKey
   END.
