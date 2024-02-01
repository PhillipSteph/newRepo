#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    static char directory[50];
    if (argc == 2)
    {
        strcpy(directory, argv[1]);
    }
    else
    {
        strcpy(directory, ".");
    }
    DIR *d = opendir(directory);

    while (1)
    {
        struct dirent *entry = readdir(d);
        if (entry == NULL)
            break;
        printf("%20s", entry->d_name);

        /* FILE *f;
         long numbytes;
         f = fopen(entry->d_name, "r");
         fseek(f, 0L, SEEK_END);
         numbytes = ftell(f);
         fclose(f);*/

        struct stat info;
        stat(entry->d_name, &info);
        printf(" %10d ", info.st_size);
        char c = '?';
        if (S_ISREG(info.st_mode))
            c = 'f';
        if (S_ISDIR(info.st_mode))
            c = 'd';
        putchar(c);
        putchar(' ');
        char *date = ctime(&(info.st_mtime));
        // ... und im Datum hinten das \n suchen
        // und an diese Stelle eine Ende-Markierung schreiben
        *(strchr(date, '\n')) = '\0';
        printf("%s\n", date);
    }
    exit(EXIT_SUCCESS);
    return 0;
}