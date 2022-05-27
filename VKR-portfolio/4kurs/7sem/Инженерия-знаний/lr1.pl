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

father(F, C):-
    roditel(F,C),
    male(F).

mother(M,C):-
    roditel(M,C),
    female(M).  