male(jamesI).
male(charlesI).
male(jamesII).
male(charlesII).
male(georgeI).

female(elizabeth).
female(sophia).
female(catherine).

parent(jamesI,charlesI).
parent(jamesI,elizabeth).

parent(charlesI,catherine).
parent(charlesI,charlesII).
parent(charlesI,camesII).

parent(elizabeth,sophia).

parent(sophia,georgeI).

father(X,Y):-
    male(X),parent(X,Y).

mother(X,Y):-
    female(X),parent(X,Y).

son(X,Y):-
    male(X),parent(Y,X).

daughter(X,Y):-
    female(X),parent(Y,X).

grandfather(X,Y):-
    male(X),parent(X,Somebody),parent(Somebody,Y).

grandmother(X,Y):-
    female(X),parent(X,Somebody),parent(Somebody,Y).

brother(X,Y) :-  male(X),parent(Somebody,X),parent(Somebody,Y), X \= Y.

sister(X,Y) :- female(X),parent(Par,X),parent(Par,Y), X \= Y.


