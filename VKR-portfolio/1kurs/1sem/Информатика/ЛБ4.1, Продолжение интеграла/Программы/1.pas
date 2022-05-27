var
  a, b, n, h, x, s, i: real ;

function fn(i: real): real;
begin
  fn := sin(0.8 * i * i + 0.3) / (0.7 + cos(1.2 * i + 0.3));
end;

begin
  
  writeln('Границы интегрирования: ');
  readln(a);
  readln(b);
  writeln('Кол-во разбиений: ');
  readln(n);
  h := (b - a) / n;
  writeln('Шаг: ', h);
  x := a + h;
  s := 0;
  while x <= b - h do 
  begin
    s := s + fn(x);
    x := x + h;
  end;
  y:=h * ((fn(a) + fn(b)) / 2 + s)
  writeln('Результат: ',y);
end.