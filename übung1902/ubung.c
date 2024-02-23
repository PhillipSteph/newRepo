#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char *strreverse(char *input);

int main(int argc, const char **argv)
{

    char *str1;
    static char str2[200];
    for(int i=1;i<argc;i++){

        strcat(str2,argv[i]);
        strcat(str2," ");

    }
    printf("%s\n", str2);

    str1 = strreverse(str2);
    printf("%s", str1);
    return 0;
}
char *strreverse(char *input)
{
    char *output = (char *)(malloc(sizeof(char) * 200));

    char *optr = output;
    char *inpend;
    for (inpend = input; *inpend != '\0'; inpend++){}
    inpend--;
    for (char *lptr = inpend; lptr >= input; lptr--){
        if(isspace(*lptr)){
            if(isspace(*(lptr-1))){
                continue;
            }else{
                *optr = *lptr;
            }
        }else{
            *optr = *lptr;
        }
        optr++;
    }
    *optr = '\0';

    return output;
}