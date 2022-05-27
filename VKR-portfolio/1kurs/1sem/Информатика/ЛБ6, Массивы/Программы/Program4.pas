var
  A: array [1..5] of integer;
  B: array [1..5] of integer;
  C: array [1..10] of integer;
  i: integer;

begin
  writeln('Введите массив A:');
  for i := 1 to 5 do readln(A[i]); 
  writeln('Введите массив B:');
  for i := 1 to 5 do readln(B[i]); 
  for i := 1 to 5 do 
  begin
    C[i] := A[i];
    C[i + 5] := B[i];
  end;
  writeln('Массив С:', C);
end.

