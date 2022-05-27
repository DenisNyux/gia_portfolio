var
  x, i, n: integer;
  s,y: real;

function fct(p: integer): real;
var
  i, k: integer;
begin
  k := 1;
  for i := 1 to p do k := k * i;
  fct := k;
end;

begin
  n := 5;
  x := 1;
  s := 0;
  for i := 1 to n do 
  begin
    s := s + 1 / fct(i + 1) * exp(ln(x) * (2 * i + 1)) / (2 * i + 1)
  end;
  y:=s/(5.5+sqr(x)+fct(3*n));
  writeln(y);
  end.
  