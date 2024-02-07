#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define maxlen 100
#define maxrows 50
struct zeile
{
    int zeilennummer;
    char zeilentext[maxlen];
};
typedef struct zeile zeile;

int cmp(const void *p1, const void *p2)
{
    const zeile *s1 = (const zeile *)p1;
    const zeile *s2 = (const zeile *)p2;
    return strcmp(s1->zeilentext, s2->zeilentext);
}

int main(int argc, void *argv[])
{
    if (argc != 1)
    {
        fprintf(stderr, "Aufruf: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int filledrows = 0;
    zeile line[maxrows];

    for (filledrows = 0;; ++filledrows)
    {
        if (filledrows == maxrows)
            exit(EXIT_FAILURE);
        if (fgets(line[filledrows].zeilentext, sizeof(line[filledrows].zeilentext), stdin) == NULL)
        {
            break;
        }
        if (strchr(line[filledrows].zeilentext, '\n') == NULL)
        {
            fprintf(stderr, "%s: Fehler beim Lesen des Strings", argv[0]);
            exit(EXIT_FAILURE);
        }
        line[filledrows].zeilennummer = filledrows + 1;
    }
    qsort(line, filledrows, sizeof(zeile), cmp);

    for (int i = 0; i < filledrows; ++i)
    {
        printf("%03d  %s", line[i].zeilennummer, line[i].zeilentext);
    }
    return 0;
}
