#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc < 2 || argc > 5)
    {
        return 1;
    }
    FILE *filein, *fileout;

    if (argc > 3)
    {
        filein = fopen(argv[3], "r");
        if (argc == 5)
        {
            fileout = fopen(argv[4], "w");
        }
        else
        {
            fileout = stdout;
        }
    }
    else
    {
        filein = stdin;
        fileout = stdout;
    }
    // search = argv[1]
    // write = argv[2]

    char string[80];
    while (fgets(string, 80, filein))
    {
        char *str = string;
        // printf("%s\n",string);
        for (;;)
        {
            char *ptr = strstr(str, argv[1]);
            if (ptr == NULL)
                break;
            *ptr = '\0';
            printf("%s", str);fputs(str,fileout);
            printf("%s", argv[2]);fputs(argv[2],fileout);
            str = ptr + strlen(argv[1]);
        }
        printf("%s", str);fputs(str,fileout);
    }
    fclose(filein);
    fclose(fileout);

    return 0;
}