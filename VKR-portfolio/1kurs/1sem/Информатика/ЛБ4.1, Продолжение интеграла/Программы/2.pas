var
  a, b, n, h, x, s1, s2,y: real ;

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
  s1 := 0;
  while x <= b - h do 
  begin
    s1 := s1 + fn(x);
    x := x + 2 * h;
  end;
  x := a + 2 * h;
  s2 := 0;
  while x <= b - 2 * h do 
  begin
    s2 := s2 + fn(x);
    x := x + 2 * h;
  end;
  y:=h / 3 * (fn(a) + fn(b) + 4 * s1 + 2 * s2);
  writeln('Результат: ',y );
end.