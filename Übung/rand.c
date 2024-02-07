#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
srand(time(NULL));

int r = rand()%6+1; // rand()%6+1 liefert werte 1-6

printf("Wuerfel wuerfelt %d",r);
    return 0;
}
