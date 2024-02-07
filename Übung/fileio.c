#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    FILE *input;
    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "%s : Fehler beim Zugriff der datei %s ; %s", argv[0], argv[1], strerror(errno));
    }
    FILE *output;
    output = fopen(argv[2], "w");

    // zeichenweise lesen und schreiben
    char c;

    while (c = fgetc(input), c != EOF)
    {
       // if (c != ' ' && c!= '\n' && c!= '\t' )    //aufgabe: überprüfe auf leerzeilen und printe sie nicht.
       // {
            fputc(c, output);
       // }
    }

    // zeilenweise
    /*char s[100]; // jede Zeile darf 100 Zeichen besitzen
    while (fgets(s, 10, input))
    {
        fputs(s, output);
    }*/
    // for (int i = 0; i < 10; i++)
    //{
    //     fgets(s, 100, input);         Zehn Zeilen werden gelesen
    //     fputs(s, output);
    // }

    fclose(input);
    fclose(output);
    return 0;
}
