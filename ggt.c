#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char *argv[]){

if(argc<3 || argc>3){
    printf("ungueltige Anzahl Argumente");
    return 1;
}

int a,b,r;
a=atoi(argv[1]);
b=atoi(argv[2]);
while(b!=0){
r=a%b;
a=b;
b=r;
}
printf("%d",a);
    return 0;
}