   { Демонстрация  эффективного ("однопроходного") }
   { определения первого элемента массива, больше- }
   { го его минимального элемента (ЕГЭ, 2009)      }
   { --------------------------------------------- }
   PROGRAM Primer_6;
      Uses CRT;
      const n=10;
      var k     : Array[1..n] of LongInt;
          i,num : Integer;
          min   : Integer;
          second: Integer;
   BEGIN
      Randomize;
      min:=0;
      For i:=1 to n do
        begin k[i]:=1+Random(234); Write(k[i],' ') end;
      WriteLn; WriteLn;
      min:=k[1]; second:=k[2];
      For i:=1 to n do
        begin
          If k[i]<min
            then begin second:=min; min:=k[i] end;
          If k[i]<>min
            then If k[i]<second
                   then second:=k[i]
                   else
            else
        end;
      WriteLn('Минимальный элемент: ',min);
      WriteLn('Второй элемент     : ', second); WriteLn;
      ReadKey
   END.
