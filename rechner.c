#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char *argv[]){

    if(argc%2!=0){
        printf("falsche Anzahl Argumente");
        return 1;
    }

double wert = atof(argv[1]); 

    for(int i=2;i<argc;i+=2){
char c = argv[i][0];
        switch(c){
            case '+': wert=wert+atof(argv[i+1]);
            break;
            case '-': wert=wert-atof(argv[i+1]);
            break;
            case 'x': wert=wert*atof(argv[i+1]);
            break;
            case '/': wert=wert/atof(argv[i+1]);
            break;
            case 'p': wert=pow(wert,atof(argv[i+1]));
            break;
            default:
            return 1;
            break;
        }

    }
printf("%f",wert);
    return 0;
}