#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
if(argc<=1 || atof(argv[1])<1){
    printf("ungueltiger Zahlenbereich");
    return 1;
}
double basis = atof(argv[1]);
double ergebnis=basis;
while(!(ergebnis*ergebnis-basis<basis*10e-10)){
ergebnis=(ergebnis+(basis/ergebnis))/2;
}

printf("%f",ergebnis);
    return 0;
}