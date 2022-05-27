var
  A: array [1..10] of integer;
  i, s: integer;

begin
  randomize;
  for i := 1 to 10 do
  begin
    A[i] := random(20);
    writeln(A[i]);
    s := s + A[i];
  end;
  writeln('Сумма элементов:', s, ' ; Среднее арифметическое:', s / 10);
end.