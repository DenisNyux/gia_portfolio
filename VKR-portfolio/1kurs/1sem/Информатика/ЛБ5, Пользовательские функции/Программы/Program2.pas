var i: integer;
procedure Y(x:real);
begin
writeln(sin(x)+cos(x)/sin(x));
end;
begin
for i:=1 to 10 do Y(i*pi/5-pi);
end.
 