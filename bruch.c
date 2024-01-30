#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct bruch strtobruch(const char *str);
struct bruch
{
    int zahler;
    int nenner;
};

int main(int argc, const char *argv[])
{
    for(int i=1;i<argc;i++){
    struct bruch eingang = strtobruch(argv[i]);
    printf("%d durch %d\n",eingang.zahler,eingang.nenner);
    }
    return 0;
}

struct bruch strtobruch(const char *str)
{
    char *ptr;
    struct  bruch eingang;
    eingang.zahler = atoi(str);
    if (ptr = strchr(str, '/'))
    {
        eingang.nenner = atoi(ptr + 1);
    }
    return eingang;
}