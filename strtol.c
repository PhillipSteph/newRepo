#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int strtolo(const char arr[],char** ende){

    int length = strlen(arr);
    int wert=0,a,i;
    if(arr[0]=='-'){
        i=1;
        a=-1;
    }else{
        i=0;
        a=1;
    }
    for(i;i<length;++i){

        if(arr[i]<'0' || arr[i]>'9'){
            exit(EXIT_FAILURE);
        }
        
         wert = wert*10+(arr[i]-'0');

    
            return wert*a;
        }
}

int main(int argc, const char *argv[]){

char* ende;
for(int i=1;i<argc;i++){
   strtolo(argv[i],&ende); 
}
    return 0;
}
