const
  U_in = 50;

const
  RC = 2 * 0.01;

const
  E = 10e-3;

var
  U_out, t, x, k: real;

begin
  t := 0.01;
  writeln('t    |   U_out');
  writeln('______________');
  repeat
    
    U_out := U_in * (1 - exp((-t) / RC));
    write(t:2:2,' ','|',' ');
    writeln(U_out);
   
    t := t + 0.01;
    
  until abs(U_in - U_out) < E;
end.
