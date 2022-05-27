var
  a, x, s, k, p, i: integer;

begin
  readln(a);
  s:= 0;
  k:= 0;
  p:= 1;
  while s <= a do 
    begin
    k:= k + 1;
    p:= p*k;
    s:= s + p
    end;
  writeln(k-1,'!');
  for i:=1 to k-2 do
    write(i,'+');
  write(k-1,'=',s-p);
end.