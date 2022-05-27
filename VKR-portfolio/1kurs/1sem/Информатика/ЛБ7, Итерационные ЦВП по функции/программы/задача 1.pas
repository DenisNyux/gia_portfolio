var
  a: integer;

begin
  readln(a);
  while (a mod 10 + a div 100 + a div 10 mod 10) > 10 do 
  begin
    writeln('+');
    readln(a);
  end;
end.