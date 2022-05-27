var a :string ;
t: char;
begin
readln(a);
t:=a[1];
a[1]:=a[3];
a[3]:=t ;
writeln(a) ;
end.

