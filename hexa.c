#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

    int hextoint(char zeichen);
    char converthex(char zeichen);
int main(int argc, const char *argv[]){
int ergebnis=0;
char c=0;
    for(int i=0;i<argc-1;++i){

                int k=0;
            for(int j=strlen(argv[i+1]);j>0;--j){

                c = converthex(argv[i+1][k]);
                ergebnis=ergebnis*16+c;printf("\n%d",ergebnis);
                k++;      
            }
ergebnis=0;
    }
    return 0;
}

char converthex(char zeichen){

    if(zeichen>='0' && zeichen<='9'){
        return zeichen-48;
    }
    else if(zeichen>='A' && zeichen<='F'){
        return zeichen-'A'+10;
    }
    else if(zeichen>='a' && zeichen<='f'){
        return zeichen-'a'+10;
    }
}