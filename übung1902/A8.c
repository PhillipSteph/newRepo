#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#define ZEILENLANGE 256

typedef struct eintrag
{
    const char *Dateiname;
    int Zeilennummer;
    char *text;
    struct eintrag *next;
} eintrag;

typedef struct liste
{
    eintrag *head;
    eintrag *tail;
} liste;



void saveline(liste arr[], const char *filename, int zeile, const char *zeilentext)
{

    eintrag *neu = (eintrag *)(malloc(sizeof(eintrag)));
    neu->text = strdup(zeilentext);
    neu->Dateiname = filename;
    neu->Zeilennummer = zeile;
    neu->next = NULL;

    int i = strlen(zeilentext);
    assert(i < ZEILENLANGE);
    if (arr[i].head == NULL)
    {
        arr[i].head = neu;
    }
    else
    {
        arr[i].tail->next = neu;
    }
    arr[i].tail = neu;
}

void usefile(liste arr[], const char *filename)
{
    FILE *file = fopen(filename, "r");

    int cnt = 0;
    char *string;
    while (fgets(string, ZEILENLANGE, file))
    {
        cnt++;
        if (string == NULL || strlen(string) > ZEILENLANGE)
        {
            fprintf(stderr, "Fehler mach dohc was ihr wollt: %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        saveline(arr, filename, cnt, string);
    }

    fclose(file);
}

void ausgabe(liste* arr)
{

    for (int i = 0; i < ZEILENLANGE; i++)
    {

        eintrag *ptr = arr[i].head;
        while (ptr != NULL)
        {

            printf("%s : %d %s", ptr->Dateiname, ptr->Zeilennummer, ptr->text);

            ptr = ptr->next;
        }
    }
}
int main(int argc, const char *argv[])
{
    liste listenarr[ZEILENLANGE]; // pointer oder nicht?

    for(int i=0;i<ZEILENLANGE;i++){
        listenarr[i].tail = listenarr[i].head = NULL;
    }
    if(argc==1) return 1;

    char *string;
    for (int i = 1; i < argc; i++)
    {
        usefile(listenarr,argv[i]);
    }
    ausgabe(listenarr);
}
