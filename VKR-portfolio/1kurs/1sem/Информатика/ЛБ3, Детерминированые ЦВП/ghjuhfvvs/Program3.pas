var s1,p1,p2,s2,k:real;
n,i:integer;
begin
n:=14;
s1:=0;
p1:=1;
for i:=2 to n do begin 
s1:=s1+i*i;
p1:=p1*i*i;
end;
s2:=0;
p2:=1;
for i:=2 to n do begin
k:=i;
s2:=s2+i/(i+2);
p2:=p2*i/(i+2);
end;
writeln ((3*s1+p2)/(p1+2*s2));
end.

