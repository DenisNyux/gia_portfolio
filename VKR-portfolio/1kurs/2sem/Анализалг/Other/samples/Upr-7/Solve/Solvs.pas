   (** One-pass algorithms on integer numeric arrays **)
   (** by Elina V. Kibitkina (16.04.1998)            **)
   (** --------------------------------------------- **)
   Program Arrays;
      Uses CRT;
      const n=20;                       { Array size           }
            r=20;                       { Random numbers range }
      type  arr=array[1..n] of integer;
      var   a: arr;                     { Array of numeric data}
            t: boolean;                 { Trace flag           }
            c: char;                    { Optuion variable     }
      label trace;
   { -------------------------------------------------- }
   Procedure getarr (var a: arr; i: integer; k: integer);
      var j: integer;
   begin
      Randomize;
      Write
      ('Generating a numeric array [1..',i,'] in range 0-',k,'...');
      For j:=1 to i do
        a[j]:=random(k);
      writeln(' complete.')
   end;
   { ---------------------------------------- }
   Procedure writearr (var a: arr; i: integer);
      var j: integer;
   begin
      Write('The array is: ');
      For j:=1 to i do Write(a[j]:2,' ');
      WriteLn
   end;
   { ------------------------------------------ }
   Function max(var a: arr; i: integer): integer;     { 6-0-1-2 }
      var j,m: integer;
   begin
      m:=a[1];
      for j:=2 to i do if a[j]>m then m:=a[j];
      max:=m
   end;
   { ---------------------------------------------- }
   Function maxnum (var a: arr; i: integer): integer; { 6-0-1-3 }
      var j,m,k: integer;
   begin
      m:=a[1]; k:=1;
      for j:=2 to i do
        if m<a[j]
          then begin m:=a[j]; k:=1 end
          else if m=a[j]
                 then inc(k);
      maxnum:=k
   end;
   { ------------------------------------------- }
   Function min (var a: arr; i: integer): integer;    { 6-0-2-4 }
      var j,m: integer;
   begin
      m:=a[1];
      for j:=2 to i do
        if a[j]<m
          then m:=a[j];
      min:=m
   end;
   { -------------------------------------------- }
   Function cond (var a: arr; i: integer): integer;   { 6-0-2-10 }
      var j,m: integer;
   begin
      m:=0;
      for j:=1 to i do
        if a[j]<10
          then inc(m);
      cond:=m
   end;
   { ------------------------------------------- }
   Function seq (var a: arr; i: integer): integer;    { 6-0-1-4 }
      var j,m,k,l: integer;
   begin
      m:=a[1]; k:=1; l:=1;
      for j:=2 to i do
        begin
          if m=a[j]
            then inc(k)
            else begin
                   if k>l
                     then l:=k;
                   k:=1
                 end;
          m:=a[j]
        end;
      seq:=l
   end;
   { ---------------------------------- }
   Function mseq (var a: arr; i: integer;
                      b: boolean): integer;           { 6-0-2-16 }
      var j,m,k: integer;
   begin
      m:=a[1];
      if b
        then begin
               WriteLn;
               Write(#09,'(checking the subsequences'' maximums:')
             end;
      k:=0;
      for j:=2 to i do
        if m<a[j]
          then begin
                 inc(k); m:=a[j];
                 if b
                   then write(' [',a[j]:2,']')
               end;
      if b
        then begin Writeln(')'); write(#09) end;
      mseq:=k
   end;
   { ----------------------------------------------------- }
   Function lseq (var a: arr; i: integer; b: boolean): real;
                                                      { 6-0-2-22 }
      var j,m,k,l,s,f: integer;
   begin
      m:=a[1];
      if b
        then begin
               writeln;
               writeln(#09,'(checking the growing sequences:')
             end;
      k:=0;                { Sequence's length counter   }
      s:=0;                { Number of sequences counter }
      l:=0;                { Sum container               }
      f:=0;                { Sequence end flag           }
      For j:=2 to i do
        begin
          if m<a[j]
             then begin
                    inc(k);
                    if b then write(' [',m:2,']->[',a[j],']');
                    f:=1;
                    if j=i then inc(s)
                  end
             else begin
                    if f=1 then begin inc(s); dec(f) end;
                    l:=l+k;
                    k:=0;
                    if b then write('  *')
                  end;
          m:=a[j]
        end;
      l:=l+s;
      if b
        then begin
               writeln(') -> ',l,'/',s,' ->');
               write(#09)
             end;
      lseq:=l/s
   end;
   { - }
   begin
      writeln;
      writeln('**** ONE-PASS ALGORITHMS ON ARRAYS ****');
      getarr(a,n,r); writearr(a,n);
      writeln('***************************************');
      trace:
      write('Trace the sequences? (y/n): '); readln(c);
      case c of
        'y':  t:=true;
        'n':  t:=false;
        else  goto trace
      end;
      Writeln('*************************************************');
      Writeln('The maximum is                               : ',
               max(a,n));
      Writeln('The number of maximums is                    : ',
               maxnum(a,n));
      Writeln('The minimum is                               : ',
               min(a,n));
      Writeln('The number of elements<10 is                 : ',
               cond(a,n));
      Writeln('The maximum number of elements in sequence is: ',
               seq(a,n));
      Writeln('The number of subsequences'' maximums is      : ',
               mseq(a,n,t));
      Writeln('The average length of growing sequences is   : ',
               lseq(a,n,t):2:4);
      Writeln('*****************************************************');
      ReadKey
   end.
