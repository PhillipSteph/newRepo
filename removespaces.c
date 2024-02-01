#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int main(int argc, const char *argv[]){

FILE *read,*write;

if(argc!=3){
    return 1;
}
read = fopen(argv[1],"r");
write = fopen(argv[2],"w");

if(read==NULL){
    fprintf(stderr, "%s: Fehler beim Zugriff der Datei %s: %s!", argv[0], argv[1], strerror(errno));
    exit(EXIT_FAILURE);
}

char text,temp;
int c = 0;
while(text = fgetc(read),text != EOF){
    if(isspace(text)){
        temp = text;
    }
    else{
       // printf("%c",text);   
        fputc(text,write);
        temp = text;
        c++; if(c==30){
            fputc('\n',write);
            c=0;
        }
    }
}

fclose(read);
fclose(write);
    return 0;
}