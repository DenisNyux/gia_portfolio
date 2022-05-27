var x,y,m,u :real;
begin
readln(x,y);
m:=sin(x+y);
u:=(1+exp(2*ln(m)))/(2+abs(x-((2*exp(2*ln(x))/(1+abs(m))))));
writeln(u);
end.
