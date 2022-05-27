   -- Демонстрация конструирования конечных списков,
   -- содержащих "часть" решения заданного рекуррент-
   -- ного соотношения  д е к о м п о з и ц и и
   -- *****************************************

   --------------------------------------------------
   -- Функция - рекуррентное соотношение декомпозиции
   --------------------------------------------------
   abc :: Integer -> Integer
   abc n | n==2 = 0
         | True = 3 * abc (n `div` 2) 
                    + n * truncate (sqrt (fromInteger n+1.0))
   ----------------------------------------------------------
   -- Функция - значения аргумента рекуррентного
   -- соотношения, являющиеся степенями 2
   --------------------------------------
   step = map (\x -> 2^x) [2..30]

   ------------------------------------
   test7  = map (\x -> (x, abc x)) step
   test7' = map (\x -> (x,(fromInteger x) ** logBase 2.0 3.0))
                step
   test7''= map (\x -> (x,fromInteger (abc x) -
                          (fromInteger x) ** logBase 2.0 3.0))
                step

   -- ***********************
   abc' :: Integer -> Integer
   abc' n | n==2 = 0
          | True = 8 * abc' (n `div` 2) 
                     + (n * n) `div` (truncate $ logBase 2 (fromInteger n))
   ------------------------------------------------------------------------
   step_1 = map (\x -> 2^x) [2..30]
   --------------------------------
   test8  = last $ map abc' step_1
   test8' = last $ map (\x -> fromInteger (x*x*x)) step_1

   -- ************************
   abc'' :: Integer -> Integer
   abc'' n | n==2 = 0
           | True = 2 * abc'' (n `div` 2) 
                      + truncate (logBase 2 (fromInteger n))
   ---------------------------------------------------------
   step_2 = map (\x -> 2^x) [2..30]
   --------------------------------
   test9  = last $ map abc'' step_2
   test9' = last $ map (\x -> truncate $ (2*fromInteger x) 
                             - logBase 2 (fromInteger x))
                       step_2

   -- *************************
   abc''' :: Integer -> Integer
   abc''' n | n==3 = 0
            | True = 8 * abc''' (n `div` 3) + 2 ^ n
   ------------------------------------------------
   step_3 = map (\x -> 3^x) [2..9]
   --------------------------------------------------
   test10  = length $ show $ last $ map abc''' step_3 
   test10' = length $ show $ last $ map (\x -> 2^x) step_3

   -- **************************
   abc'''' :: Integer -> Integer
   abc'''' n | n==1 = 1
             | True = 8 * abc'''' (n `div` 2) + 1000 * n ^ 2
   ---------------------------------------------------------
   step_4 = map (\x -> 2^x) [2..30]
   --------------------------------
   test11  = map abc'''' step_4
   test11' = map (\x -> (abc'''' x,
                           1001*(fromInteger x)^3-
                           1000*(fromInteger x)^2)) step_4

   -- ************************
   abc_5 :: Integer -> Integer
   abc_5 n | n==1 = 1
           | True = 2 * abc_5 (n `div` 2) + 10 * n
   -----------------------------------------------
   step_5 = map (\x -> 2^x) [2..30]
   --------------------------------
   test12  = map abc_5 step_5
   test12' = map (\x -> (abc_5 x, x + 10*x*
                         (truncate $ logBase 2 (fromInteger x)))) 
                 step_5
