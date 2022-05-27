var
  a, x: integer;

begin
  a := random(100 + 1);
  while x <> a do 
  begin
    read(x);
    if x > a then writeln(' Больше искомого')
    else if x < a then writeln(' Меньше искомого') else
      writeln('Победа!');
  end;
end.



