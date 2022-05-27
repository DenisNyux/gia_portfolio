program LabW2;
const
Eps = 1e-6;
var
precedent, current : double;

function f(x : double) : double;
begin
f := x * x * x * x - 4 * x * x * x - 8 * x * x + 1;
end;

function derived(x : double) : double;
begin
derived := 4 * x * x * x - 12 * x * x - 16 * x;
end;

begin
current := 8.1; //x0
repeat
precedent := current; 
current := precedent - f(precedent) / derived(precedent); //Xi+1
until abs(current - precedent) <= Eps;
writeln(current:1:6);
end.

begin
  x1:=-10;
  repeat
  x:=x1;
  x1:=Fn(x);
  writeln(x,x1);
  until abs(x1-x) <=E;
  writeln(x1);
  end.
