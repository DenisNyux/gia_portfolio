var
  l, d, j, sina, cosa, a, c: real;

begin
  l := 0.1;
  d := 30 * pi / 180;
  j := 45 * pi / 180;
  sina := cos(j) * sin(l) / sin(d);
  cosa := (sin(j) - sin(j) * cos(d)) / cos(j) * sin(d);
  a := arcsin(sina);
  if (sina > 0) 
    then
    if (cosa > 0) then begin c := 1;a := abs(a); end
    else begin c := 2;a := pi - abs(a); end
  else 
  if (cosa < 0) then begin c := 3;a := pi + abs(a); end
  else begin c := 3;a := 2 * pi - abs(A); end;
  writeln(a, ' ', c)
end. 