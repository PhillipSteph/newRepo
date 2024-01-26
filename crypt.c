#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int main(int argc, const char *argv[]){
FILE *read,*write;

if(argc!=4){
    return 1;
}
read = fopen(argv[1],"r");
write = fopen(argv[2],"w");



     int key = atoi(argv[3]);

if(read==NULL){
    fprintf(stderr, "%s: Fehler beim Zugriff der Datei %s: %s!", argv[0], argv[1], strerror(errno));
    EXIT_FAILURE;
}

char text,temp;

while(text = fgetc(read),text != EOF){
        fputc(text+key,write);
        temp = text;
}

fclose(read);
fclose(write);
    return 0;
}