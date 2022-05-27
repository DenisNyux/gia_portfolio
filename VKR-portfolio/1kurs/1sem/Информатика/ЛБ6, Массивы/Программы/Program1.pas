var
  F: array [1..7] of real;
  R, C, L, Xc, Xi, j, Z: real;
  i: integer;

begin
  C := 15E-12;
  R := 2;
  L := 1E-3;
  for i := 1 to 7 do 
  begin
    write(i, ')', 'Fi=');
    readln(F[i]);
    Xc := 1 / (2 * pi * F[i] * C);
    Xi := 2 * pi * F[i] * L;
    j := arctan(Xi / R - (Xi * Xi) / (R * Xc) - R / Xc);
    Z := Xc * sqrt(Xi * Xi + R * R) / sqrt(R * R + (Xi - Xc) * (Xi - Xc));
    writeln('j:=', j, ' ; ', 'Z:=', z);
  end;
end.
