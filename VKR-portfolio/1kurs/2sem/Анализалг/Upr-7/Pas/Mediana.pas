   { Демонстрация поиска медианы в массиве }
   { (реализация алгоритма Ч.Хоара)        }   
   { ------------------------------------- }
   PROGRAM Mediana;
      uses  CRT;
      const N=8;
      type  index=0..N;
            Massiv=Array [0..N] of Integer;
       var  x  : Integer;
            A  : Massiv;
            i,k: index;
            c  : Char;
   { --------------------------- }
   PROCEDURE F_i_n_d (k: Integer);
      var l,          { Наименьший индекс массива }
          r,          { Наибольший индекс массива }
          i,j,w,      { Рабочие переменные        }
          x: Integer;
   BEGIN
      l:=1; r:=n;
      While l<r do
        begin
          x:=A[k]; i:=l; j:=r;
          Repeat
            While A[i]<x do
              i:=i+1;
            While x<A[j] do
              j:=j-1;
            If i<=j
              then begin
                     w:=A[i]; A[i]:=A[j]; A[j]:=w;
                     i:=i+1; j:=j-1
                   end
          until i>j;
          If j<k then l:=i;
          If k<i then r:=j
        end
   END;
  { --- }
   BEGIN
      Write('Исходный массив: ');
      Randomize;
      For i:=1 to N do
        begin A[i]:=Random(40)+1; Write(A[i],' ') end;
      WriteLn; 
      k:=N DIV 2; F_i_n_d(k); 
      WriteLn('Результат: ',A[k]); c:=ReadKey
   END.
