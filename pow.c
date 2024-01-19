#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hoch(double a, int n);

int main(int argc, const char *argv[]){

    if(argc!=3){
        return 1;
    }
double a=atof(argv[1]);
int n=atoi(argv[2]);

printf("%f",hoch(a,n));
    return 0;
}

double hoch(double a, int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 1/(hoch(a,-n));
    }
    if(n%2==0){
        return hoch((a*a),n/2);
    }else {
        return a * hoch(a,n-1);
    }
}