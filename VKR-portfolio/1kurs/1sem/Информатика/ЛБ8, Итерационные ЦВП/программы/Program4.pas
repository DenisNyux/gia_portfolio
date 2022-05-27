const
  E = 10e-4;

var
  x: real ;

function cosinus(x: real): real;
var
  k, u, s: real;
begin
  k := 1;
  u := 1;
  s := 1;
  repeat
    u := u * (-1) * x * x / (4 * k * k - 2 * k);
    k := k + 1;
    s := s + u;
  until u < E;
  cosinus := s;
end;

begin
  x:=pi/6;
  writeln('cos = ', cosinus(x));
end.
