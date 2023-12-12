#include <stdio.h>
#include <stdlib.h>

float ergebnis;
void berechnepotenz(float basis, int exponent);

int main(int argc, const char *argv[]){

switch(argc){
    case 1: printf("zu wenig Argumente!");
        break;
    case 2: printf("zu wenig Argumente!");
        break;
    case 3: berechnepotenz(atof(argv[1]),atoi(argv[2]));
        break;
    default:
        printf("zu viele Argumente!");
        break;
}
return 0;
}

void berechnepotenz(float basis, int exponent){
ergebnis= basis;
    for(int i=1;i<exponent;++i){
        ergebnis *= basis;
    }
    if(exponent==0){
        ergebnis=1;
    }
    printf("%f ^ %d = %f",basis,exponent,ergebnis);
}