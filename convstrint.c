#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int strtoint(const char arr[]);
int main(int argc, const char *argv[]){

    if(argc!=2) return 1;

    
       int zahl = strtoint( argv[1] );
    printf("%d",zahl);

    return 0;
}

int strtoint(const char arr[]){

    int length = strlen(arr);
    int wert=0;    
    for(int i=length-1,j=0;i>=0;--i,++j){

        if(arr[i]<'0' || arr[i]>'9'){
            exit(EXIT_FAILURE);
        }

         wert += (arr[i]-'0')*pow(10,j);

    }
return wert;
}