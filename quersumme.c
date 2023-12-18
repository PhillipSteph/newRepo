#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bestimmelaenge(int number);
int berechne(int number);

int main(int argc, const char *argv[]){
if(argc!=2){
    printf("ungueltige Anzahl Argumente");  //programm funktioniert nur mit 2 argumenten (funktion und wert)
    return 1;
}
  berechne(atoi(argv[1]));
  return 0;
}

int berechne(int number){
    int summe=0;
    int temp=number;
    int laenge=0;
while(temp>=1){   
    temp/=10;
    laenge++;       //bestimmt länge des Integers, indem Wert solange durch 10 geteilt wird bis <1, jede division wird länge++
}
    temp=0;
        while(laenge>=0){
            int a= temp*10;
            temp=number/pow(10,laenge);
            summe+=temp-a;
            printf("%d und a=%d\n Summe ist %d\n\n",temp,a,summe);  //arbeitet Zahl So oft ab, wie Länge groß ist.
            laenge--;
        }
    printf("\nDie Quersumme von %d = %d\n",number,summe);
    if(summe>9){
        printf("%d ist nicht einstellig. Wiederhole das Verfahren.\n\n",summe); //rekursion der Funktion bis Quersumme >=9
        berechne(summe);
    }
}