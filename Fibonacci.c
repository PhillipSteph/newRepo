#include <stdio.h>
#include <stdlib.h>

const double pi = 3.14159265358979;
double kreisumfangberechnung(double radius);
void fibonacci(int anzahl);
long double gr;
int main(int argc,const char *argv[]){

    fibonacci(25);
    return 0;
}

double kreisumfangberechnung(double radius){
    return 2.0*pi*radius;
}

void fibonacci(int anzahl){
    int arr[anzahl];
    arr[0]=1;
    arr[1]=1;

    for(int i=2;i<anzahl;++i){
        arr[i]=arr[i-2]+arr[i-1];
        gr = arr[i]/arr[i-1];
        printf(" %f",gr);
    }
    for(int j=0;j<anzahl;++j){
        printf("%d\n",arr[j]);
    }
    gr=5/6;
    printf("Golden Ratio is %Lf\n",gr);
}
