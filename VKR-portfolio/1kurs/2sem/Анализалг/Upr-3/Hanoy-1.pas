   PROGRAM H_a_n_o_y_1;
      Uses CRT;
      type st  = (Left,Middle,Right);
           Nat = 1..MAXINT;
      var  M: Nat;        { M - число дисков }
   { --------------------------------------- }
   PROCEDURE M_o_v_e (N: Nat; S1,SW,SK: st);
   { Перемещение N дисков с S1 на SK; }
   { SW - вспомогательный стержень    }
   { -------------------------------- }
   PROCEDURE  S_t_e_p;
   { Перемещение одного диска с S1 на SK }
   { ----------------------------------- }
   PROCEDURE P_r_i_n_t (S: st);
   BEGIN
      Case S of
        Left  : Write ('Левый');
        Middle: Write ('Средний');
        Right : Write ('Правый')
      end
   END;
  {---- }
   BEGIN
      Write ('Снять диск с '); P_r_i_n_t (S1);
      Write (' Надеть на ');   P_r_i_n_t (SK); WriteLn
   END;
  { --- }
   BEGIN
      If N=1
        then S_t_e_p
        else begin
               M_o_v_e (N-1,S1,SK,SW); S_t_e_p;
               M_o_v_e (N-1,SW,S1,SK)
             end
   END;
  { --- }
   BEGIN
      WriteLn('Введите количество дисков...'); Read (M);
      WriteLn;
      WriteLn('Для ', M:3,
              ' дисков следует произвести следующие действия:');
      M_o_v_e (M,Left,Middle,Right);
      ReadKey
   END.
