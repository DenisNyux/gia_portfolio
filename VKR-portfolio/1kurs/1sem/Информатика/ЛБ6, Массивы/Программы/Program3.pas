const
  n = 7;

var
  A: array [1..n] of integer;
  i, t: integer ;

begin
  for i := 1 to n do readln(A[i]);
  writeln(A);
  i:=1;
  while i<=n-1  do 
  begin
    t := A[i];
    A[i] := A[i + 1];
    A[i + 1] := t;
    i := i + 2;
  end;
  writeln(A);
end.
