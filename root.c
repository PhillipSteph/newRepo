#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, const char *argv[]){
if(argc<=1 || atof(argv[1])<0){
    printf("ungueltiger Zahlenbereich");
    return 1;
}
double basis = atof(argv[1]);
double ergebnis=basis;
while(!(fabs(ergebnis*ergebnis-basis)<basis*10e-10)){
printf("%.15g\n",ergebnis);
ergebnis=(ergebnis+(basis/ergebnis))/2;
}

printf("%.15g",ergebnis);
    return 0;
}