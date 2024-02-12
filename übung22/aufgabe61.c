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
        if(e==NULL){
            fprintf(stderr,"Fehler bei Speicherreservierung: %s",strerror);
        }
    e->anzahl = 0;
    e->zahl = zahl;
    e->next = next;

    return e;
}

elem *find(elem* head,int zahl){

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


// Deklaration:
// Pointer auf einen Datentypen werden mit dem Datentypen selber und einem STernchen Deklariert
//BSP: Ein Pointer auf einen Integer deklariert man     int* ptr;
//Nach der DEklaration kann es zu Verwirrung führen, da man werte mit Pointern folgend ablesen kann:

// für eine Variable    int a = 10; kann man die Adresse lesen mit int* ptr = &a;
// wenn man aber die Variable von einem Pointer lesen möchte so nutzt man 
// int a = *ptr;
// also:            Deklaration:    int* ptr; deklariert einen Pointer
//                  Lesen:          int a = *ptr; liest wert von variable auf die der Pointer zeigt
//                  Lesen 2.0:      int* ptr = &a; liest adresse von Variable a