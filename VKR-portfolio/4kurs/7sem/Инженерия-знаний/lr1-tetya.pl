roditel(ivan, maria).
roditel(anna, maria).
roditel(maria, pavel).
roditel(maria, petr).
roditel(maria, alina).
roditel(pavel, liza).
roditel(yulia, liza).

suprug(ivan, anna).
suprug(pavel, yulia).

sister(alina, petr).
sister(alina, pavel).

male(ivan).
male(pavel).
male(petr).

female(maria).
female(anna).
female(yulia).
female(alina).

father(F, C):-
    roditel(F,C),
    male(F).

mother(M,C):-
    roditel(M,C),
    female(M).  

vnuk(G, C):-
    roditel(G, R),
    roditel(R, C).

sibling(X, Y):-
    roditel(A, X),
    roditel(A, Y).

tetya(X, Y):-
    roditel(B, Y),
    sister(X, B).