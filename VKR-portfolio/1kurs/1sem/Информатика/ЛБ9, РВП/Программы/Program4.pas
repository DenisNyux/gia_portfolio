var
  x: integer;

begin
  readln(x);
  if (x > 10) and (x < 20) then writeln('�����')
  else 
  begin
    x := x mod 10;
    case x of
      1: writeln('������');
      2, 3, 4: writeln('������');
      5, 6, 7, 8, 9, 0: writeln('�����');
    end;
  end;
end.

