var square,x,y,z:real;
i: integer;
function squaretr(a,b,c:real):real;
var p:real;
begin 
p:=(a+b+c)/2;
squaretr:=sqrt(p*(p-a)*(p-b)*(p-c));
end;
begin 
square:=0;
writeln('������� ������� �������������:');
for i:=1 to 4 do begin
readln(x,y,z);
writeln('������� ������������: ',squaretr(x,y,z));
square:=square+squaretr(x,y,z);
end;
writeln('������� ������:',square);
end.