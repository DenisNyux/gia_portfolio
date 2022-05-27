const
  E = 10e-4;

var
  x: real ;

function sinus(x: real): real;
var
  k, u, s: real;
begin
  k := 1;
  u := x;
  s := x;
  repeat
    u := u * (-1) * x * x / (4 * k * k + 2 * k);
    k := k + 1;
    s := s + u;
  until u < E;
  sinus := s;
end;

begin
  x:=pi/6;
  writeln('sin=', sinus(x));
end.
