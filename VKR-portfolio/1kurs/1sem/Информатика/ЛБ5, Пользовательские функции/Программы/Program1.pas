var i : integer;
procedure sm(x:integer);
begin
writeln(x,' ','|',' ',x*2.5);
end;
begin 
for i:=0 to 100 do sm(i);
end.