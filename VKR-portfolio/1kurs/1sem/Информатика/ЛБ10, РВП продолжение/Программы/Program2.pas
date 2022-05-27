const
  n = 10;

var
  A: array [0..n] of integer;
  i, x, s: integer;

begin
  for i := 0 to n do a[i] := random(15);
  writeln(A);
  readln(x);
  s:=0;
  for i := 0 to n do
    if A[i] > x then 
    begin
      s := s + A[i];
      write(i, ' '); 
      end;
  writeln('');
  writeln(s);
end.