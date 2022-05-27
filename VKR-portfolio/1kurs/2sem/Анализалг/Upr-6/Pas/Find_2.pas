   { Линейный поиск с "барьером" наименьшего индекса заданно- }
   { го элемента одномерного "случайного" числового массива   }
   { -------------------------------------------------------- }
   PROGRAM Find_2;
      uses  CRT;
      const N=7;        { Количество элементов в массиве   }
            N1=N+1;     { Важно, что выполняется N1=N+1    }
      type  R=0..N1;
      var   i: R;       { Параметр циклов                  }
            Q: Boolean; { Флаг - результат поиска элемента }
            A: Array [1..N1] of Integer; { Исходный массив }
            X: Integer;                  { Искомый элемент }
            c: Char;
   BEGIN
      Write('Исходный массив: ');
      For i:=1 to N do
         A[i]:=Random(12)+1;
      For i:=1 to N do
         Write(A[i],' ');
      WriteLn; Write('Искомый элемент: '); Read(X);
      i:=0; A[N+1]:=X;
      Repeat i:=i+1 until A[i]=X;
      WriteLn;
      If i<>N+1
        then begin
               Write('Элемент найден; его минимальный ');
               WriteLn('индекс в массиве: ',i)
             end
        else Write('Элемент не найден.');
      WriteLn; c:=ReadKey
   END.
