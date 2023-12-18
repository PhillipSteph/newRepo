#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printgraph(int arr[]);

int main(int argc, const char *argv[]){
    //befehl: nagelbrett (Anzahl Stufen) (Anzahl Kugeln)
if(argc!=3){
    printf("\nUngueltige Anzahl Argumente: 'nagelbrett (anzahl Stufen) (anzahl Kugeln)'\n");
    return 1;
}
if(atoi(argv[2])>=1000000){

    printf("WILLST DU DEINEN COMPUTER UMBRINGEN???");
    return 1;

}
srand(time(NULL));

int k = atoi(argv[2]);
int r = atoi(argv[1]);
int wert = 0;
int arr[r];
int i=0,j=0;
int zufall;
    for(i=0;i<=r;i++){  //für r stufen endArray mit 0en gefüllt
        arr[i]=0;
    }

    for(j=1;j<=k;++j){  //von 1..k Kugeln
        wert=0;
        for(i=1;i<=r;++i){
            zufall = rand() % 2;
            wert+=zufall;
        }
        printf("\nSpalte %d/%d erhoeht um eins!",wert,r+1);
    arr[wert]+=1;
    }
    for(int i=0;i<=r;i++){  //printet fertiges Array
        printf(" | %d",arr[i]);
    }
    printf(" |");
    

    //get max diagramm
    
    int max=arr[0];
   
    for(int i=1;i<r;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
//max 150 X

//calculate factor
float faktor=1;
while(max<=90){
    max*=2;
    faktor/=2;
}
while(max>150){
    max/=2;
    faktor*=2;
}
for(int i=0;i<=r;i++){
        if(arr[i]<10){
            printf(" ");
        }
        if(arr[i]<100){
            printf(" ");
        }
        if(arr[i]<1000){
            printf(" ");
        }
        printf("%d | ",arr[i]);
        for(j=0;j<arr[i]/faktor;j++){
            printf("X");
        }
        printf("\n");
    }
    return 0;
}