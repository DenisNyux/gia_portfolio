var m,q:real ;
i:integer;
begin
m:=13.5*pi/3*cos(q);
for i:=0 to 90 do begin
q:=i*pi/180;
writeln(((1+sin(q))*cos(m))/((pi/2)*(pi/2)-m*m));
end;
end.
