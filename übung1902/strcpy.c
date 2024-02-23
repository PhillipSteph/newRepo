#include <stdlib.h>
#include <stdio.h>

char *strcopy(char *dest, char *src) // src ptr darf maximal 100 char lang sein
{ // dest -> "'H'allo hobt ihr hunger+'\0'"

    char *dptr = (char *)(malloc(sizeof(char)*101));
    char *sptr;

    for (dptr = dest, sptr = src; *sptr != '\0'; dptr++, sptr++)
    {
        *dptr = *sptr;
    }
    *dptr = '\0';

    return dest;
}

int main(int argc, char const *argv[])
{
    char str1[100] = "Max guckt sehr lieb zu";
    char str2[100];

    strcopy(str2,str1);

    printf("%s",str2);

    return 0;
}
