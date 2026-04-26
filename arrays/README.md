# Arrays

## Perspectiva abstracta:

- 1.) *Motivatie* — De ce folosim un array?. Ce problema rezolva fata de variabile separate?.

R.: - Folosim un array pentru ca se pot organiza mai multe date de acelasi tip sub un
      singur nume, accesibile printr-un index, in loc sa declaram o variabila separata
      pentru fiecare element.

- 2.) *Ce este* — Cum arata un array in memorie?. Ce il defineste structural?.

R.: - Un array este un sir continuu de octeti in memorie, unde fiecare element ocupa
      exact acelasi spatiu. Asta permite calculul direct al adresei oricarui element:
      adresa_baza + index * dimensiune_tip. Dimensiunea unui array este fixa si trebuie
      cunoscuta la momentul declararii.

- 3.) *Operatii* — Ce poti face cu un array?. inserare, stergere, cautare, traversare:

R.: - Inserarea: se poate face oriunde, dar cel mai eficient este la final. La mijloc
      sau la inceput toate elementele de dupa pozitia respectiva trebuie mutate.
    - Stergerea: similar cu inserarea, cel mai eficient la final. In rest, necesita
      mutarea elementelor ramase pentru a pastra continuitatea.
    - Cautarea: daca stim indexul elementului, accesul este direct si instant. Daca
      nu stim indexul, trebuie sa parcurgem array-ul element cu element.
    - Traversarea: parcurgem toate elementele in ordine.

- 4.) *Complexitate* — Cat costa fiecare operatie ca timp si spatiu?.

R.: - Inserarea: O(1) la final, O(n) in cel mai rau caz (la inceput/mijloc); spatiu auxiliar O(1).
    - Stergerea: O(1) la final, O(n) in cel mai rau caz (la inceput/mijloc); spatiu auxiliar O(1).
    - Cautarea: O(1) daca stim indexul, O(n) daca nu il stim; spatiu auxiliar O(1).
    - Traversarea: O(n) timp; spatiu auxiliar O(1).
    - Spatiu total: O(n)

- 5.) *Avantaje si dezavantaje*

R.: - Avantaje:
      - Acces direct la orice element prin index in O(1).
      - Memorie continua.
      - Simplu de folosit si de inteles.
    - Dezavantaje:
      - Dimensiune fixa declarata la inceput (in C, fara realocare manuala).
      - Inserarea si stergerea in afara finalului sunt costisitoare: O(n).
      - Nu e flexibil cand numarul de elemente variaza mult.

- 6.) *Cazuri de utilizare* — Cand alegi un array si de ce?.

R.: - Cand numarul de elemente este cunoscut si fix de la inceput.
    - Cand ai nevoie de acces rapid la elemente prin index.
    - Cand parcurgi frecvent toate elementele in ordine.
    - Exemple: stocarea notelor studentilor, pixelii unei imagini, un buffer de date.

