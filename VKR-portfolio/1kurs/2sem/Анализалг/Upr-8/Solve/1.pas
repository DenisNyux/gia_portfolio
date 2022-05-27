   { Дан одномерный массив X. Все его элементы, не равные }
   { нулю, переписать (сохраняя их порядок) в начало мас- }
   { сива, а нулевые элементы - в конец массива (при этом }
   { новый массив не использовать)                        }
   { ---------------------------------------------------- }
   PROGRAM v14;
      Uses CRT;
      var k,
          n,
          i: Integer; 
          X: Array [1..8] of Integer;
   BEGIN
     k:=0;
     Write('Введите n: '); ReadLn(n);
     for i:=1 to n do
       Read(X[i]);
     for i:=1 to n do
       if X[i]<>0
         then X[i-k]:=X[i]
         else k:=k+1;
     for i:=n-k+1 to n do
       X[i]:=0;
     Write('Результат: ');
     For i:=1 to n do
       Write(X[i],' ');
     ReadKey
   END.
