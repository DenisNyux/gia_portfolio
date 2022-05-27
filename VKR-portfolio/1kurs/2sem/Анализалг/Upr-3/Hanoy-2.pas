   PROGRAM H_a_n_o_y_2;
      Uses CRT;
      var Source,Help,Destination: Char;
   { -------------------------------------------------- }
   PROCEDURE Hanoi (n: Integer; Source: Char; Help: Char;
                    Destination: Char);
   BEGIN
      If n>2
        then begin
               Hanoi (n-1,Source,Destination,Help);
               WriteLn (Source,'-->',Destination);
               Hanoi (n-1,Help,Source,Destination)
             end
        else WriteLn(Source,'-->',Help,' ',
                     Source,'-->',Destination,' ',
                     Help,  '-->',Destination);
   END;
  { --- }
   BEGIN
      Source:='A'; Help:='B'; Destination:='C';
      Hanoi(3,Source,Help,Destination);
      ReadKey
   END.
