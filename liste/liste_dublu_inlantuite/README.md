# Doubly Linked List

## Perspectiva abstracta:

- 1.) *Motivatie* — De ce avem nevoie de o lista dublu inlantuita?. Ce problema rezolva fata de lista simplu inlantuita?.

    - Lista simplu inlantuita ne permite sa traversam lista doar intr-un singur sens,
      de la head catre coada. Daca vrem sa ajungem la nodul anterior unui nod dat,
      suntem obligati sa reluam traversarea de la head. Lista dublu inlantuita rezolva
      aceasta problema prin adaugarea unui pointer catre nodul anterior, permitand
      traversarea in ambele directii si operatii mai eficiente in anumite cazuri.

- 2.) *Ce este* — Cum arata o lista dublu inlantuita in memorie?. Ce o defineste structural?.

    - O lista dublu inlantuita este o colectie de noduri unde fiecare nod contine trei
      lucruri: o valoare (data), un pointer catre nodul urmator (next) si un pointer
      catre nodul anterior (prev). Primul nod (head) are prev setat la NULL, iar ultimul
      nod are next setat la NULL. Ca lista simplu inlantuita, nodurile nu stau neaparat
      continuu in memorie, ci sunt legate intre ele prin pointeri.

- 3.) *Operatii* — Ce poti face cu o lista dublu inlantuita?. inserare, stergere, cautare, traversare:

    - Inserarea: eficienta la inceput si la final in O(1) daca avem pointer si la coada
      (tail). La mijloc necesita traversare pana la pozitia dorita;
    - Stergerea: mai simpla decat la lista simplu inlantuita, deoarece nu mai avem
      nevoie sa traversam lista pentru a gasi nodul anterior — il accesam direct prin
      pointerul prev;
    - Cautarea: la fel ca la lista simplu inlantuita, trebuie sa parcurgem nodurile
      unul cate unul. Putem insa porni fie de la head fie de la tail;
    - Traversarea: putem parcurge lista in ambele sensuri, de la head la tail si
      de la tail la head.

- 4.) *Complexitate* — Cat costa fiecare operatie ca timp si spatiu?.

    - Inserarea: O(1) la inceput si la final (cu pointer la tail), O(n) la mijloc; spatiu auxiliar O(1);
    - Stergerea: O(1) daca avem pointer direct la nod, O(n) daca trebuie sa il cautam; spatiu auxiliar O(1);
    - Cautarea: O(n) in orice caz; spatiu auxiliar O(1);
    - Traversarea: O(n) timp; spatiu auxiliar O(1);
    - Spatiu total: O(n), dar fiecare nod consuma mai multa memorie decat la lista simplu inlantuita.

- 5.) *Avantaje si dezavantaje*

    - Avantaje:
      - Traversare in ambele sensuri;
      - Stergerea unui nod dat este O(1) daca avem pointer direct la el, fara
        a mai cauta nodul anterior;
      - Inserarea la final este O(1) daca mentinem un pointer la tail.
    - Dezavantaje:
      - Fiecare nod consuma mai multa memorie din cauza pointerului prev;
      - Implementare mai complexa, mai multe redirectionari de pointeri la fiecare
        operatie, deci mai multe surse de bug-uri;
      - Nu rezolva problema accesului prin index, cautarea ramane O(n).

- 6.) *Cazuri de utilizare* — Cand alegi o lista dublu inlantuita si de ce?.

R.: - Cand ai nevoie de traversare in ambele directii;
    - Cand stergerile sunt frecvente si ai deja pointer la nodul de sters;
    - Cand ai nevoie de inserare si stergere eficienta la ambele capete;
    - Exemple: istoricul unui browser (inainte/inapoi cu eficienta), editoare de
      text (navigare in ambele directii).

## Implementare:

  *** TODOS: ***

- Definirea structurii nodului (struct);

- Creare nod nou;

- Inserare la inceput;

- Inserare la final;

- Inserare la o pozitie data;

- Stergere la inceput;

- Stergere la final;

- Stergere la o pozitie data;

- Cautare;

- Traversare / afisare;

- Distrugere.

