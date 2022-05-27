var x,a: integer ;
begin
readln (x);
a:= (x mod 10)*100+((x div 10) mod 10)*10+(x div 100);
writeln(a) ;
end.