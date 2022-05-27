var y,a,b,c,d: real;
function fn(m,n:real):real;
begin
fn:=sin(m+n);
end;
begin
readln(a);
readln(b);
readln(c);
y:=fn(a,b)/fn(c,d)*fn(5*a,c);
writeln(y);
end.
