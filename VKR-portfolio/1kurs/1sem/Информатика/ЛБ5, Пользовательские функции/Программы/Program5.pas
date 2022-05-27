var d :integer;
procedure fib(x:integer);
var x0,x1,s,i: integer;
begin
x0:=1;
x1:=2;
writeln(x0);
writeln(x1);
for i:=3 to x do begin
s:=x0+x1;
writeln(s);
x0:=x1;
x1:=s;
end;
end;
begin 
readln(d);
fib(d);
end.