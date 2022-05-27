roditel(ivan, maria).
roditel(anna, maria).
roditel(maria, pavel).
roditel(maria, petr).

suprug(ivan, anna).
suprug(pavel, yulia).

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

has_sibling(X):-
    roditel(A, X),
    roditel(A, Y),
    X\=Y.

roditel2(X):-
    roditel(X, Y),
    has_sibling(Y).