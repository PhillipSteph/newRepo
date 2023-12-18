#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void teilewert(int wert);
int main(int argc, const char *argv[]){

if(argc!=2){
    printf("ungueltige Anzahl Argumente!");
    return 1;
}

int wert=atoi(argv[1]);
teilewert(wert);
printf("1\n");
    return 0;
}

void teilewert(int wert){

for(int i=2;i<=wert;++i){
    while(wert%i==0){
        printf("%d * ",i);
        wert /= i;
       // teilewert(wert);
        //break;
    }
}
//printf("%d ",wert);

}