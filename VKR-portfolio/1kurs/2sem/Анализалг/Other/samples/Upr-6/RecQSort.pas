   { Рекурсивная реализация алгоритма быстрой сортировки }
   { --------------------------------------------------- }
   PROGRAM RecursiveQuickSort;
      Uses CRT;
      const N=10;
      type  Index=0..N;
            Massiv=Array [0..N] of Integer;
      var   A: Massiv;
            i: Index;
  { ------------------------------ }
   PROCEDURE  S_o_r_t (l,r: Index);
      var i,j: Index;
          x,w: Integer;
   BEGIN
      i:=l; j:=r; x:=A[(l+r) DIV 2];
      Repeat
         While A[i]<x do i:=i+1;
         While x<A[j] do j:=j-1;
            If i<=j
              then begin
                      w:=A[i]; A[i]:=A[j]; A[j]:=w;
                      i:=i+1; j:=j-1
                   end
      until i>j;
      If l<j then S_o_r_t (l,j);
      If i<r then S_o_r_t (i,r)
   END;
  { --- }
   BEGIN
      Randomize; WriteLn;
      Write('Элементы массива: ');
      For i:=1 to N do
        begin A[i]:=Random(25); Write(A[i]:2,' ') end;
      WriteLn;
      S_o_r_t (1,N);
      Write('Результат       : ');
      For i:=1 to N do
        Write(A[i]:2,' ');
      WriteLn;
      ReadKey
   END.
