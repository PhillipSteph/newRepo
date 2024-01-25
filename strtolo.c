#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int my_strtol(const char str[],char **pointer){
    int erg = 0;
    char *p;
    for(p = str; isdigit(*p); ++p) {
        erg = erg * 10 + (*p -'0');
    }
    if (pointer != NULL) {
        *pointer = p;  // ... = str + i;
    }
    return erg;
}

int main(int argc, const char *argv[])
{
    for (int i = 1; i < argc; ++i) {
        char *ende;
        int zahl = my_strtol(argv[i], &ende);
        if (ende == argv[i]) {
            printf("\"%s\": Keine Zahl?\n", ende);
        } else if (*ende != '\0') {
            printf("Vorne %d, hinten %s\n", zahl, ende);
        } else {
            printf("%d ok\n", zahl);
        }
    }
    return 0;
}
