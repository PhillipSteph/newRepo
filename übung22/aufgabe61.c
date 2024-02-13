#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct elem
{
    int zahl;
    unsigned int anzahl;
    struct elem *next;
} elem;

elem *neu(int zahl, elem *next)
{

    elem *e = (elem *)(malloc(sizeof(elem)));
    if (e == NULL)
    {
        fprintf(stderr, "Fehler bei Speicherreservierung: %s", strerror(errno));
        exit(1);
    }
    e->anzahl = 0;
    e->zahl = zahl;
    e->next = next;

    return e;
}

elem *find(elem **head_p, int zahl)
{

    // Leer oder erstes ELement größer
    // head zeigt auf kleinstes Element
    // in sortierten Liste.
    elem *first = *head_p;
    if (first == NULL || first->zahl > zahl)
    {
        elem *n = neu(zahl, first);
        *head_p = n;
        return n;
    }
    else
    {
        elem *ptr = first;
        while (1)
        {
            if (ptr->zahl == zahl)
            {
                return ptr;
            }
            else if (ptr->next == NULL || ptr->next->zahl > zahl)
            {
                elem *n = neu(zahl, ptr->next);
                ptr->next = n;
                return n;
            }
            ptr = ptr->next;
        }
    }
    // legt neues ELement an, welches Auf vorheriges
    // erstes Zeigt oder auf NULL wenn kein vorheriges existiert.
}

void print(elem *head)
{
    elem *ptr = head;
    while (ptr != NULL)
    {
        printf("%d:%d ", ptr->zahl, ptr->anzahl);
        ptr = ptr->next;
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    elem *head = NULL;
    for (int i = 1; i < argc; i++)
    {

        elem *e = find(&head, atoi(argv[i]));
        ++(e->anzahl);
        print(head);
    }
    return 0;
}








// Deklaration:
// Pointer auf einen Datentypen werden mit dem Datentypen selber und einem STernchen Deklariert
// BSP: Ein Pointer auf einen Integer deklariert man     int* ptr;
// Nach der DEklaration kann es zu Verwirrung führen, da man werte mit Pointern folgend ablesen kann:

// für eine Variable    int a = 10; kann man die Adresse lesen mit int* ptr = &a;
// wenn man aber die Variable von einem Pointer lesen möchte so nutzt man
// int a = *ptr;
// also:            Deklaration:    int* ptr; deklariert einen Pointer
//                  Lesen:          int a = *ptr; liest wert von variable auf die der Pointer zeigt
//                  Lesen 2.0:      int* ptr = &a; liest adresse von Variable a