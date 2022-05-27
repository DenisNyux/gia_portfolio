var p,a,x,s,h,b,i,n: real ;
function fn(x:real):real;
begin 
fn:=sin((0.8*x*x+1)*pi/180)/(0.7+sin(1.2*x+0.3));
end;
begin 
a:=0.2;
b:=1;
writeln('Кол-во разбиений: ');
read(n) ;
h:=(b-a)/n;
i:=a+h;
s:=0;
while p<=b-h do 
begin
s:=s+fn(p);
i:=i+h;
end;
writeln(h*(fn(a)+fn(b))/2+s);
end.
