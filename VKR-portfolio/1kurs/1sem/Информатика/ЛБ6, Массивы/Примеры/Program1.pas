
var
  A: array [1..5] of real;
  i: integer;

begin
  randomize;
  for i := 1 to 5 do  
  begin
    A[i] := random(10);
    writeln(A[i]);   
  end;
  writeln(A);
end.