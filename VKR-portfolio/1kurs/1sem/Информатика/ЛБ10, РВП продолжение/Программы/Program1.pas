const
  n = 10;

var
  a: array [0..n] of integer;
  i, s: integer;

begin
  for i := 0 to n do a[i] := random(15);
  writeln(A);
  s:=0;
  for i := 0 to n do 
    if i mod 2 = 0 
      then
      s := s + A[i];
  writeln(s);
end.
