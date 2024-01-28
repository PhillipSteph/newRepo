#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int main(int argc, const char* argv[]){

FILE *read;

read = fopen(argv[1],"r");
if(read==NULL){
    fprintf(stderr, "%s: Fehler beim Zugriff der Datei %s: %s!", argv[0], argv[1], strerror(errno));
    exit(EXIT_FAILURE);
    }
char c;int i=0;
static char arr[20];

while(c = fgetc(read), c!=EOF){

switch(c){

case '(':arr[i]=1;i++;
    break;
case '[':arr[i]=2;i++;
    break;
case '{':arr[i]=3;i++;
    break;
case ')': if(arr[i-1]==1){
        arr[i-1]=0;i--;
        }else{
            if(arr[0]!=0){
            printf("Klammer ) frühzeitig gesetzt");
            }else{
                printf("mehr Klammern geschlossen als geöffnet");
                }
    fclose(read);
    return 1;
    }
    break;
    case ']': if(arr[i-1]==2){
            arr[i-1]=0;i--;
        }else{
        if(arr[0]!=0){
        printf("Klammer ] frühzeitig gesetzt");
        }else{
            printf("mehr Klammern geschlossen als geöffnet");
        }
    fclose(read);
    return 1;
    }
    break;
    case '}': if(arr[i-1]==3){
            arr[i-1]=0;i--;
        }else{
    if(arr[0]!=0){
    printf("Klammer } frühzeitig gesetzt");
    }else{
    printf("mehr Klammern geschlossen als geöffnet");
    }
    fclose(read);
    return 1;
    }
    break;
default: 
    break;
}

}
if(arr[0]!=0){
    printf("nicht alle Klammern geschlossen!");
}else{
    printf("alle Klammern korrekt gesetzt und geschlossen!");
}
    fclose(read);
    return 0;
}