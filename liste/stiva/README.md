# Stack

## Perspectiva abstracta:

- 1.) *Motivatie* — De ce avem nevoie de o stiva?. Ce problema rezolva?.

    - In multe situatii avem nevoie de o structura unde ultimul element adaugat
      este primul care trebuie procesat (ex: undo, apeluri de functii).
      Structurile precum array-ul sau lista nu impun aceasta disciplina.
      Stiva ofera un model simplu si eficient bazat pe principiul LIFO
      (Last In, First Out).

- 2.) *Ce este* — Cum arata o stiva?. Ce o defineste?.

    - O stiva este o structură de date liniara in care inserarea si stergerea
      se fac doar la un singur capat, numit varf (top).
    - Respecta principiul LIFO: ultimul element introdus este primul eliminat.
    - Poate fi implementata folosind:
      - array (static sau dinamic);
      - lista simplu înlantuita (de obicei cu inserare/stergere la inceput).

- 3.) *Operatii* — Ce poti face cu o stiva?.

    - Push (inserare):
      - Adauga un element în varful stivei;
    - Pop (stergere):
      - Elimina elementul din varful stivei;
    - Peek / Top:
      - Returnează elementul din varf fara sa il elimine;
    - IsEmpty:
      - Verifica daca stiva este goala;
    - Traversare:
      - Nu este operație standard (stiva nu este gandita pentru acces arbitrar),
        dar se poate face de la top in jos.

- 4.) *Complexitate* — Costuri timp si spatiu

    - Push: O(1);
    - Pop: O(1);
    - Peek: O(1);
    - IsEmpty: O(1);
    - Traversare: O(n) (daca este necesara);
    - Spatiu total: O(n).

    - Observatii:
      - Pentru implementare cu array:
        - risc de overflow daca dimensiunea este fixa;
      - Pentru implementare cu lista:
        - nu exista limita fixa, dar exista overhead de pointeri.

- 5.) *Avantaje si dezavantaje*

    - Avantaje:
      - Operatii foarte rapide (O(1));
      - Implementare simpla;
      - Model natural pentru multe probleme (recursivitate, backtracking);

    - Dezavantaje:
      - Acces limitat (doar la top);
      - Nu permite cautare eficienta (O(n));
      - In varianta cu array fix: limitare de capacitate;
      - In varianta cu lista: consum suplimentar de memorie.

- 6.) *Cazuri de utilizare* — Când alegi o stiva?.

R.: - Evaluarea expresiilor (ex: paranteze, postfix/prefix);
    - Backtracking (ex: DFS);
    - Istoric operatii (undo/redo);
    - Gestionarea apelurilor de functii (call stack);
    - Parsere (ex: compilatoare, validare sintactica).

## Implementare:

  *** TODOS: ***

- Definirea structurii stivei:
  - varianta cu lista (pointer la top);

- Initializare stiva;

- Push;

- Pop;

- Peek / Top;

- IsEmpty;

- Traversare / afisare;

- Distrugere.

