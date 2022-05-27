const
  k = 3;

const
  a = 10;

const
  n = 15;

var
  Ar: array [1..n] of real;
  x: real;
  i,d3,d4,d1,d2: integer;

function fact(x:integer):real;
var 
  i,s: integer;
begin
  s:= 1;
  for i:=1 to x do
    s:= s*i;
  fact:=s;
end;

function y1(x: real): real;
begin
  y1 := power((a + x), (1 / k));
end;

function y2(x:real): real;
var 
  z,s: real;
begin
  z:=0;
  s:=0;
  while z <= 10 do
    begin
    s:= s + (power(z,x) + x)/fact(10);
    z:=z+2;
    end;
  y2:=s;
end;
begin
  for i:=1 to n do 
    Ar[i]:=random(15);
  writeln(Ar);
  write('¬ведите первый диапазон: ');
  readln(d1,d2);
  write('¬ведите второй диапазон: ');
  readln(d3,d4);
  for i:=d1 to d2 do
    Ar[i]:= y1(Ar[i]);
  for i:=d3 to d4 do 
    Ar[i]:= y2(Ar[i]);
  write(Ar);
end.