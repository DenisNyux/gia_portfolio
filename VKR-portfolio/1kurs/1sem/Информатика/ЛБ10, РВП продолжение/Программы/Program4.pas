const
  n = 10;

var
  a: array [0..n] of integer;
  i, j, t, k, max: integer;

begin
  for i := 0 to n do a[i] := random(150);
  writeln(A);
  for i := 0 to n do 
  begin
    max := a[i];
    for j := i + 1 to n do
      if a[j] > max then 
      begin
        max := a[j];
        k := j;
      end;
    if a[k] > a[i]
      then
    begin
      t := a[i];
      a[i] := a[k];
      a[k] := t;
    end;
  end;
  writeln(A);
end.  