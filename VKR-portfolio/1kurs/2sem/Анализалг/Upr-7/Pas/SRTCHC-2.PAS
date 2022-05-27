   PROGRAM SortChoice_2;
   { Сортировка методом простого выбора (второй способ) }
      uses  CRT;
      const N=8;
      type  Index=1..N;
            Massiv=Array[Index] of Integer;
      var   A: Massiv;
            i: Index;
            c: Char;
  { ------------------------------------------------ }
   FUNCTION Imin(Start: Integer; A: Massiv): Integer;
   { Функция находит минимальный элемент "правее" Start }
   { (включая Start) и возвращает его номер             }
      var m,i: Integer;
   BEGIN
      m:=Start;
      For i:=Start+1 to N do
        If A[i]<A[m] then m:=i;
      Imin:=m
   END;
  { ------------------------------- }
   PROCEDURE Swap(var a,b: Integer);
   { Процедура обмена значениями двух переменных }
      var c: Integer;
   BEGIN
      c:=a; a:=b; b:=c
   END;
  { ----------------------------------- }
   PROCEDURE Sort_Choice(var t: Massiv);
   { Процедура сортировки выбором }
      var i: Integer;
   BEGIN
      For i:=1 to N-1 do
        Swap(A[Imin(i,A)],A[i])
   END;
  { --- }
   BEGIN
      Write('Исходный массив: '); For i:=1 to N do Read(A[i]);
      Sort_Choice(A);
      Write('Результат сортировки: ');
      For i:=1 to N do Write(A[i],' ');
      WriteLn; c:=ReadKey
   END.
