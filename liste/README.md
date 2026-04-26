# Linked List

## Perspectiva abstracta:

- 1.) *Motivatie* — De ce avem nevoie de o lista inlantuita?. Ce problema rezolva fata de array?.

R.: - Array-ul are dimensiune fixa declarata la inceput. Daca nu stim de la inceput
      cate elemente vom avea, fie alocam prea mult si pierdem memorie, fie alocam prea
      putin si ramanem fara spatiu. In plus, inserarea si stergerea, in afara finalului,
      sunt costisitoare deoarece necesita mutarea elementelor. Lista inlantuita rezolva
      ambele probleme: creste si scade dinamic, iar inserarea si stergerea sunt eficiente
      odata ce stim pozitia.

- 2.) *Ce este* — Cum arata o lista inlantuita in memorie?. Ce o defineste structural?.

R.: - O lista inlantuita este o colectie de noduri unde fiecare nod contine doua lucruri:
      o valoare (data) si un pointer catre urmatorul nod. Nodurile nu stau neaparat
      continuu in memorie, ci sunt legate intre ele prin pointeri. Primul nod se numeste
      head, iar ultimul nod are pointerul catre urmatorul setat la NULL, semnalizand
      sfarsitul listei.

- 3.) *Operatii* — Ce poti face cu o lista inlantuita?. inserare, stergere, cautare, traversare:

R.: - Inserarea: cel mai eficient la inceput (la head), deoarece nu necesita traversare.
      La mijloc sau la final necesita traversarea listei pana la pozitia dorita.

    - Stergerea: similar cu inserarea, cel mai eficient la inceput. In rest, necesita
      traversarea pana la nodul anterior celui de sters, apoi redirectionarea pointerului.

    - Cautarea: nu avem acces direct prin index, deci trebuie sa parcurgem lista
      element cu element de la head pana gasim valoarea cautata.

    - Traversarea: parcurgem toate nodurile in ordine, urmand pointerii de la head pana
      la NULL.

- 4.) *Complexitate* — Cat costa fiecare operatie ca timp si spatiu?.

R.: - Inserarea: O(1) la inceput, O(n) la mijloc sau la final; spatiu auxiliar O(1).

    - Stergerea: O(1) la inceput, O(n) la mijloc sau la final; spatiu auxiliar O(1).

    - Cautarea: O(n) in orice caz; spatiu auxiliar O(1).

    - Traversarea: O(n) timp; spatiu auxiliar O(1).

    - Spatiu total: O(n).

- 5.) *Avantaje si dezavantaje*

R.: - Avantaje:
      - Dimensiune dinamica, creste si scade dupa nevoie.

      - Inserarea si stergerea la inceput sunt O(1), fara mutarea elementelor.

      - Nu necesita alocare continua de memorie.

    - Dezavantaje:

      - Nu avem acces direct prin index, cautarea este intotdeauna O(n).

      - Fiecare nod consuma memorie extra pentru pointer.

      - Nu este prietenos cu procesorul, deoarece nodurile nu sunt
        continue in memorie.

- 6.) *Cazuri de utilizare* — Cand alegi o lista inlantuita si de ce?.

R.: - Cand numarul de elemente variaza frecvent si nu este cunoscut la inceput.

    - Cand inserarile si stergerile sunt frecvente, mai ales la inceputul colectiei.

    - Cand nu ai nevoie de acces rapid prin index.

    - Exemple: istoricul unui browser (inainte/inapoi), lista de melodii intr-un
      playlist, implementarea stivelor si cozilor, gestionarea proceselor in sistemele
      de operare.

## Implementare:

  *** TODOS: ***

- Definirea structurii nodului (struct);

- Creare nod nou;

- Inserare la inceput;

- Inserare la final;

- Inserare la o pozitie data;

- Stergere la inceput;

- Stergere la final;

- Stergere dupa valoare;

- Cautare;

- Traversare / afisare;

- Distrugere.

