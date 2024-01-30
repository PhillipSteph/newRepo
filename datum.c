#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
        return 1;
    int tag = atoi(argv[1]),
        monat = atoi(argv[2]),
        jahr = atoi(argv[3]);

    struct tm heute = {0, 0, 12, tag, monat - 1, jahr - 1900, 0, 0, -1};
    time_t time = mktime(&heute);

    if (time == -1)
    {
        printf("du bist schlecht");
        return 1;
    }
    struct tm *ptr = localtime(&time);
    const char *arr[7] = {"sonndach", "mohntach", "dienschtach", "mettwoch", "dönerstach", "frétoch", "sönnabent"};
    struct tm ausgang = *ptr;
    ausgang.tm_mon++;
    ausgang.tm_mday++;
    ausgang.tm_year += 1900;
    printf("%d.%d.%d", --ausgang.tm_mday, ausgang.tm_mon, ausgang.tm_year);
    printf("\n det is 'n %s und der %d. Tag im Jahr", arr[ausgang.tm_wday], ++ausgang.tm_yday);

    return 0;
}