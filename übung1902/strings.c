#include <stdlib.h>
#include <stdio.h>

char* strcopy(char* src){
char* dest = (char *)(malloc(sizeof(char)*250));

char* dptr = dest; char* sptr;
for(sptr = src;*sptr!='\0';sptr++){
*dptr = *sptr;
dptr++;
}
*dptr = '\0';
return dest;
}
char* strreverse(char* src){
char* dest = (char *)(malloc(sizeof(char)*250));
char* dptr = dest;
char* sptr;
for(sptr = src;*sptr!='\0';sptr++){}
sptr--;

for(char* ptr = sptr;ptr>=src;ptr--){
    *dptr = *ptr;
    dptr++;
} *dptr = '\0';

return dest;
}

int main(int argc, char const *argv[])
{

char str1[250]="Hallo dieser Text wird kopiert";

char *str2 = strcopy(str1);

printf("\n%s\n",str2);
printf("%s\n",strreverse(str2));

    return 0;
}
