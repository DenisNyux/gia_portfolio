var
  a, b, n, h, x, s,fa,fb: real ;

begin
  writeln('������� ��������������: ');
  readln(a);
  readln(b);
  writeln('���-�� ���������: ');
  readln(n);
  h := (b - a) / n;
  writeln('���: ', h);
  x := a+h;
  s := 0;
  while x <= b-h do 
  begin
    s := s + sin(0.8 * x * x + 0.3) / (0.7 + cos(1.2 * x + 0.3));
    x := x + h;
  end;
  fa:=sin(0.8*a*a+0.3)/0.7+cos(1.2*a+0.3);
  fb:=sin(0.8*b*b+0.3)/0.7+cos(1.2*b+0.3);
  writeln('���������: ', h *((fa+fb)/2+s));
end.