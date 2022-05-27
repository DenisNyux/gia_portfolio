var
  x0, x, x1, E: real;

function f(x: real): real;
begin
  f := x * x * x * x - 18 * x * x + 6;
end;

function f1(x: real): real;
begin
  f1 := 4 * x * x * x - 36 * x;
end;

function Fn(x: real): real;
begin
  Fn := x - (x * x * x * x - 18 * x * x + 6) / (4 * x * x * x - 36 * x);
end;

begin
  E := 10e-6;
  x0:=-10;
  x:=Fn(x0);
  x1:=Fn(x);
  while abs(x1-x)<=E do begin
  x:=x1;
  x1:=Fn(x);
  writeln('+');
  end;
  writeln(x1);
end.
