var
  A: array [1..5] of integer;
  B: array [1..5] of integer;
  C: array [1..10] of integer;
  i: integer;

begin
  writeln('������� ������ A:');
  for i := 1 to 5 do readln(A[i]); 
  writeln('������� ������ B:');
  for i := 1 to 5 do readln(B[i]); 
  for i := 1 to 5 do 
  begin
    C[i] := A[i];
    C[i + 5] := B[i];
  end;
  writeln('������ �:', C);
end.

