# Queue

## Perspectiva abstracta:

- 1.) *Motivatie* — De ce avem nevoie de o coada?. Ce problema rezolva?.

    - In multe situatii trebuie sa procesam elementele in ordinea in care
      au fost adaugate (ex: task-uri, cereri, procese).
      Stiva nu este potrivita deoarece foloseste LIFO.
      Coada ofera un model FIFO (First In, First Out), unde primul element
      adaugat este primul procesat.

- 2.) *Ce este* — Cum arata o coada?. Ce o defineste?.

    - O coada este o structura de date liniara in care:
      - inserarea se face la un capat (rear / tail);
      - stergerea se face la celalalt capat (front / head).
    - Respecta principiul FIFO.
    - Pentru eficienta, se folosesc de obicei doi pointeri:
      - front (inceputul cozii);
      - rear (sfarsitul cozii).
    - Poate fi implementata folosind:
      - array (circular);
      - lista simplu inlantuita (cu pointer la head si tail).

- 3.) *Operatii* — Ce poti face cu o coada?.

    - Enqueue (inserare):
      - Adauga un element la finalul cozii;
    - Dequeue (stergere):
      - Elimina elementul de la inceputul cozii;
    - Front / Peek:
      - Returneaza elementul din fata fara sa il elimine;
    - IsEmpty:
      - Verifica daca coada este goala;
    - Traversare:
      - De la front la rear.

- 4.) *Complexitate* — Costuri timp si spatiu

    - Enqueue: O(1);
    - Dequeue: O(1);
    - Front: O(1);
    - IsEmpty: O(1);
    - Traversare: O(n);
    - Spatiu total: O(n).

    - Observatie:
      - Daca NU ai pointer la tail:
        - enqueue devine O(n) (foarte prost);
      - De aceea, coada corecta are si front si rear.

- 5.) *Avantaje si dezavantaje*

    - Avantaje:
      - Ordine naturala FIFO;
      - Operatii eficiente O(1);
      - Model simplu pentru sisteme de procesare;

    - Dezavantaje:
      - Acces limitat (doar la capete);
      - Nu permite cautare eficienta;
      - Implementarea cu array necesita gestionare circulara;

- 6.) *Cazuri de utilizare* — Cand alegi o coada?.

R.: - Planificare procese (scheduling);
    - Buffere (ex: I/O, streaming);
    - BFS (Breadth-First Search);
    - Sisteme de mesaje / task queues;
    - Simulari de tip "linie de asteptare".

## Implementare:

  *** TODOS: ***

- Definirea structurii:
  - pointer la front;
  - pointer la tail;

- Creare nod;

- Enqueue;

- Dequeue;

- Front / Peek;

- IsEmpty;

- Traversare / afisare;

- Distrugere.

