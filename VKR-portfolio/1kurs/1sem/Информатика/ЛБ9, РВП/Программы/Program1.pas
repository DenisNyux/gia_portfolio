var
  A: array [1..5] of integer;
  i, x: integer;

begin
  readln(x);
  for i := 1 to 5 do A[i] := 0;
  for i := 1 to 5 do
  begin
    A[i] := A[i] + x mod 10;
    x := x div 10;
  end;
  if (A[1] = A[5]) and (A[2] = A[4]) then 
    writeln('Палиндром')
  else writeln('Не палиндром');
end.