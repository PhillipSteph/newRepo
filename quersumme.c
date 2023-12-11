#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bestimmelaenge(int number);
int berechne(int number);


int main(int argc, const char *argv[]){

int ursprung = atoi(argv[1]);
if(argc!=2){
    printf("ungueltige Anzahl Argumente");  //programm funktioniert nur mit 2 argumenten (funktion und wert)
    return 1;
}
bestimmelaenge(atoi(argv[1]));  //returned länge der zahl als int 1-10
berechne(ursprung);

    return 0;
}


int berechne(int number){
    int summe=0;
    int temp=0;
    int laenge = bestimmelaenge(number)-1;

        while(laenge>=0){
            int a= temp*10;
            temp=number/pow(10,laenge);
            summe+=temp-a;
            printf("%d und a=%d\n Summe ist %d\n",temp,a,summe);
            laenge--;
        }
    printf("\nDie Quersumme von %d = %d\n",number,summe);
}

int bestimmelaenge(int number){
int laenge=0;

while(number>=1){
    
    number/=10;
    laenge++;

}
    return laenge;
}