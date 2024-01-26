#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char *argv[]){

FILE *writeptr,*readptr;

char outputfile[20];
printf("Geben Sie den Namen des Output Files an! (mit Dateikürzel)\n");
scanf("%s",&outputfile);

int key;
printf("Geben Sie einen schlüssel ein: (3 Stellig von 0-9)\n");
scanf("%d",&key);

char inputfile[20];
printf("Gib nun die File mit dem zu verschlüsselnden text an. (mit kürzel)\n");
scanf("%s",&inputfile);

writeptr = fopen(outputfile,"w");
readptr = fopen(inputfile,"r");

printf("%d",fgetc(readptr));
int c,a;
while(c = fgetc(readptr),c!=EOF){
    a = c-key;
    fputc(a,writeptr);
}


fclose(writeptr);
fclose(readptr);
    return 0;
}