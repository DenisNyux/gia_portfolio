var
  a, b, n, h, x, s: real ;

begin
  writeln('������� ��������������: ');
  readln(a);
  readln(b);
  writeln('���-�� ���������: ');
  readln(n);
  h := (b - a) / n;
  writeln('���: ', h);
  x := a;
  s := 0;
  while x <= b - h do 
  begin
    s := s + sin(0.8 * x * x + 0.3) / (0.7 + cos(1.2 * x + 0.3));
    x := x + h;
  end;
  writeln('���������: ', h * s);
end.