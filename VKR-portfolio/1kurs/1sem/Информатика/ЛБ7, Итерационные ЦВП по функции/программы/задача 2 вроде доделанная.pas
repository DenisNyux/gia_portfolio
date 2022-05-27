const
  E = 10e-6;

var
  x, x1: real;

function Fn(x: real): real;
begin
  Fn := x - (-x * x * x * x - 18 * x * x + 6) / (-4 * x * x * x - 36 * x);
end;

begin
  x1 := -10;
  repeat
    x := x1;
    x1 := Fn(x);
  until abs(x1 - x) <= E;
  writeln(x1);
  x1 := 10;
  repeat
    x := x1;
    x1 := Fn(x);
  until abs(x1 - x) <= E;
  writeln(x1);
  
end.
