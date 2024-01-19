#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, const char *argv[]){

    if(argc!=2){
        printf("Ungültige Anzahl an Argumenten.");
        return 1;
    }
    if(atoi(argv[1])<=2){

        return 1;

    }
        int grenze = atoi(argv[1]);
        bool wert[grenze];
        //array wird erstellt
        for(int i=0;i<=grenze;i++){
            wert[i]=true;
        }

        for(int i=2;i<=grenze;i++){

            for(int j=i+i;j<=grenze;j+=i){
                    wert[j]=false;
            }
            if(wert[i]==true){
                printf("\n%d",i);
            }

        }



    return 0;
}