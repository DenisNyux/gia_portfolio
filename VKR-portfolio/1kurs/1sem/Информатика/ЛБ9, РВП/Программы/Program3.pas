var
  a, x: integer;

begin
  a := random(100 + 1);
  while x <> a do 
  begin
    read(x);
    if x > a then writeln(' ������ ��������')
    else if x < a then writeln(' ������ ��������') else
      writeln('������!');
  end;
end.



