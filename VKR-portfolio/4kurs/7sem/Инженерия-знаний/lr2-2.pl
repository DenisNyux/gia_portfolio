price(phone, 100).
price(monitor, 150).
price(tablet, 300).
price(laptop, 350).


imeet(ivan, 400).
imeet(kolya, 200).

imeet1(C, V):-
    imeet(C, M1),
    price(V, M2),
    M1 > M2.

ne_imeet(C, V):-
    imeet(C, M1),
    price(V, M2),
    M2 > M1.

compare_item(C1, C2, V1):-
    imeet1(C1, V1),
    ne_imeet(C2, V1),
    write(V1).

compare(C1, C2):-
    compare_item(C1, C2, phone);
    compare_item(C1, C2, tablet);
    compare_item(C1, C2, laptop);
    compare_item(C1, C2, monitor).