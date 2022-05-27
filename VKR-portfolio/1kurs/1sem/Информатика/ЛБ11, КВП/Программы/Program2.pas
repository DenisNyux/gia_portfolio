var x : real;
function y(x:real):real;
  begin
  if x<0 then
    y:=abs(x)*1/4
  else if (x<1) and (x>=0) then
    y:=1/3*x
  else 
    y:=1/2*x;
  end;
begin
readln(x) ;
writeln(y(x));
end.