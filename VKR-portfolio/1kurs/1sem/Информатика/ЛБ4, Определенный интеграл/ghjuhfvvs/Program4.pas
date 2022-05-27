var
  a, b, n, h, x, s1,s2,fa,fb: real ;

begin
  writeln('Границы интегрирования: ');
  readln(a);
  readln(b);
  writeln('Кол-во разбиений: ');
  readln(n);
  h := (b - a) / n;
  writeln('Шаг: ', h);
  x := a+h;
  s1 := 0;
  while x <= b-h do 
  begin
    s1 := s1 + sin(0.8 * x * x + 0.3) / (0.7 + cos(1.2 * x + 0.3));
    x := x + 2*h;
  end;
  x := a+2*h;
  s2 := 0;
  while x <= b-2*h do 
  begin
    s2 := s2 + sin(0.8 * x * x + 0.3) / (0.7 + cos(1.2 * x + 0.3));
    x := x + 2*h;
  end;
  fa:=sin(0.8*a*a+0.3)/0.7+cos(1.2*a+0.3);
  fb:=sin(0.8*b*b+0.3)/0.7+cos(1.2*b+0.3);
  writeln('Результат: ', h/3 *(fa+fb+4*s1+2*s2));
end.