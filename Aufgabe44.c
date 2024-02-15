#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
char *strrepeat(char c, int cnt)
{
    char* dest = (char*)(malloc(sizeof(char)*(cnt+1)));
    char *endptr = dest + cnt;
    for (char *current = dest; current < endptr; ++current)
    {
        *current = c;
    }
    *endptr = '\0';
    return dest;
}
char *strtextcpy(char *dest, char *src)
{

    char *currentsrc = src;
    char *currentdest = dest;

    while (*currentsrc != '\0')
    {
        if (isspace(*currentsrc))
        {
            currentsrc++;
        }
        else
        {
            *currentdest = *currentsrc;
            currentsrc++;
            currentdest++;
        }
    }
    *currentdest = '\0';
}
char *strappend(char *dest, char *src)
{

    char *currentdest = dest;
    char *enddest;
    while (*currentdest != '\0')
    {
        currentdest++;
        enddest = currentdest;
    }
    char *currentsrc = src;
    while (*currentsrc != '\0')
    {
        *enddest = *currentsrc;
        enddest++;
        currentsrc++;
    }
    *enddest = '\0';
}

int main(int argc, char const *argv[])
{
    char *string = (char *)(malloc(sizeof(char) * 100));
    char dest[100] = "Hallo";
    char src[100] = "mama";
    strappend(src, dest);
    printf("%s", src);
    return 0;
}
