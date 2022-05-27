const
  n = 10;

var
  A: array [0..n] of integer;
  B: array [0..n] of integer;
  i: integer;
  s: real;

begin
  s:=0;
  for i := 0 to n do 
  begin
    a[i] := random(15);
    s := s + A[i]; 
  end;
  s := s / n;
  writeln(A);
  writeln(s);
  for i := 0 to n do
    if A[i] > s then 
      B[i] := A[i]
    else 
      B[i] := 0;
  writeln(B);
end.

