#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct elem
{
    int zahl;
    int anzahl;
    struct elem *next;
};
typedef struct elem elem;

elem *neu(int z, elem *n)
{
    // leg neuen Speicher für einen Eintrag an und lass p darauf zeigen
    elem *p = (elem *)(malloc(sizeof(elem)));
    if (p == NULL)
    {
        fprintf(stderr, "Speicher anlegen schiefgegangen?!\n");
        exit(EXIT_FAILURE);
    }
    p->zahl = z;
    p->anzahl = 0;
    p->next = n;
    return p; // Returnwert = Pointer auf den neuen Eintrag
}
elem *find(elem **head_p, int z)
{
  elem *akt_elem_p;  // Zeiger auf das aktuelle Element der Liste
  elem *next_elem_p; // Zeiger auf das Element nach akt_elem_p
  elem *neu_elem_p;  // Zeiger auf das neu angelegte Element

  // Lass akt_elem_p auf das erste Element der Liste zeigen
  // also auf das Element, auf das der head im main zeigt
  akt_elem_p = *head_p;
  // Wenn es noch kein erstes Element gibt (Liste leer),
  // oder wenn die Zahl im ersten Element größer als die gesuchte Zahl ist...
  if ((akt_elem_p == NULL) || (akt_elem_p->zahl > z)) {
    // ... dann erzeuge ein neues Element mit der Zahl
    // und dem bisher ersten Element der Liste als Nachfolger
    // (bei bisher leerer Liste ist der Nachfolger eben NULL)...
    neu_elem_p = neu(z, akt_elem_p);
    // das neue Element soll vorderstes Element der Liste werden
    // ==> speichere den Pointer darauf im Head-Pointer von main
    *head_p = neu_elem_p;
    // und gib den Pointer auf das neue Element zurück
    return neu_elem_p;
  } else {
    // Liste durchlaufen: akt_elem_p zeigt auf das aktuelle Element
    for (;;) {   
      if (akt_elem_p->zahl == z) {
        // Das aktuelle Element enthält die gesuchte Zahl
        // ==> den Pointer auf das aktuelle Element zurückgeben
        return akt_elem_p;
      }
      next_elem_p = akt_elem_p->next;  // Nachfolger des aktuellen Elementes
      // Wenn es keinen Nachfolger gibt
      // (d.h. akt_elem_p ist das letzte Element der Liste)
      // oder wenn die Zahl im Nachfolger größer ist als die gesuchte Zahl ...
      if ((next_elem_p == NULL) || (next_elem_p->zahl > z)) {
        // ... dann erzeuge ein neues Element mit der Zahl
        // und dem bisherigen Nachfolger des aktuellen Elementes als Nachfolger
        // (war das aktuelle Element das letzte Element der Liste,
        // dann ist der Nachfolger des neuen Elementes eben NULL) ...
        neu_elem_p = neu(z, next_elem_p);
        // ... und hänge das neue Element
        // als neuen Nachfolger von akt_elem_p in die Liste
        akt_elem_p->next = neu_elem_p;
        // und gib den Pointer auf das neue Element zurück
        return neu_elem_p;
      }
      // Sonst: Geh für den nächsten Schleifendurchlauf in der Liste eins weiter
      // d.h. der Nachfolger des aktuellen Elementes wird das aktuelle Element
      akt_elem_p = next_elem_p;  
    }
  }
}
int main(int argc, char *argv[])
{
    elem *head = NULL;
    if (argc == 1)
    {
        return 1;
    }
    int i = 1;
    elem *p = head;
    while (i < argc)
    {
        
        elem *q = neu(atoi(argv[i]), p);
        p = q;
        i++;
    }
elem *ptr = p;
while(ptr!=NULL){
   printf("%d, ",ptr->zahl);
   ptr = ptr->next;
}
    return 0;
}