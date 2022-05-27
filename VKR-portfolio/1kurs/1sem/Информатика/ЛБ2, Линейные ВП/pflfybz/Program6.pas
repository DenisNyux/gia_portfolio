var x,a,b : integer ;
begin
readln(x) ;
x:=x-1;
b:= x div 36;
a:=(x mod 36) div 4;
writeln ('подъезд',' ',b+1);
writeln('этаж',' ',a+1) ;
end.