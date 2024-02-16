#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
void strings(void)
{
    char *str1 = (char *)(malloc(sizeof(char) * 100));
    char *str2 = (char *)(malloc(sizeof(char) * 100));

    str1 = "Ich bin String";

    strcpy(str2, str1); // string copy (destination, origin)
    printf("%s\n", str2);
    int Stelle = strchr(str1, 'S') - str1; // strchr String gesChar
    printf("S an Stelle %d gefunden\n", Stelle);
    Stelle = strstr(str1, "bin") - str1; // strstr String substring
    printf("bin an Stelle %d gefunden\n", Stelle);

    printf("%d = gleich\n", strcmp(str1, str2));
    printf("%d = Größe vom '%s'\n", strlen(str2), str2);
    str2[12] = '\0';
    printf("%d = Größe vom '%s'\n", strlen(str2), str2);
     printf("%d = 1>2\n", strcmp(str1, str2));
     printf("%d = 2>1\n", strcmp(str2, str1));
    fprintf(stderr,"test: %s",strerror(errno));
printf("%s\n",str1);

}

int main(int argc, char const *argv[])
{

    strings();

    return 0;
}
