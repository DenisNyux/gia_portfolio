const
  E = 10e-4;

var
  x: real ;

function eksp(x: real): real;
var
  k, u, s: real;
begin
  k := 1;
  u := 1;
  s := 0;
  repeat
    s := s + u;
    u := u * x / k;
    k := k + 1;
  until u < E;
  eksp := s;
end;

begin
  write('¬ведите х: ');
  readln(x);
  writeln('e^x=', eksp(x));
end.


