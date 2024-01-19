#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binom(int n, int k);
int fak(int a);
int nf=1, kf=1;
int main(int argc, const char *argv[]){
if(argc!=3){
    return 1;
};
int n,k;
n=atoi(argv[1]);
k=atoi(argv[2]);

printf("%d",binom(n,k));
    return 0;
}

int binom(int n, int k){
    if(k==0){
        return 1;
    }
    if(n>12 || n<0 || k<0){
        return -1;
    }
    if(k>n){
        return 0;
    }

return (fak(n)/(fak(k)*fak((n-k))));
}

int fak(int a){
    if(a<2){return 1;}
    return (a * fak(a-1));
}