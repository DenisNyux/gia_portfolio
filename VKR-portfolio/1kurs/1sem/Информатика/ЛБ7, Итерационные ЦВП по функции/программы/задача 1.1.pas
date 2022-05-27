var
  x: integer;

function f(n: integer): integer;
var
  s: integer;
begin
  s := 0;
  while n > 0 do 
  begin
    s := s + n mod 10;
    n := n div 10; 
  end;
  f := s
end;

begin
  readln(x);
  while f(x) > 10 do 
  begin
    writeln('+');
    readln(x);
  end;
end.