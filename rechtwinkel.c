#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char *argv[]){
        if(argc!=2){
        printf("Syntax: rechtwinkel (Knoten)");
        return 1;
    }
    int k = atoi(argv[1]);
    int u = k;
    int a,b,c,ab,tempc,tempu;
    int counter=0;
    k--;
    for(int c=1;c<u;c++){
        k--;
        for(int j=1;j<=k;j++){
            a=j;
            b=0;
            while(b<=k-a+1){
                b++;
                if(c==sqrt((a*a)+(b*b)) && (c>tempc||a+b+c>tempu)){
                    counter++;
                   printf("\nRechtwinkliges Dreieck fuer: %d = c, %d = b, %d = a\n  u=%d",c,b,a,a+b+c); 
                   tempc = c;
                   tempu = a+b+c;
                }
            }
        }
    }
printf("\n Counter = %d",counter);
    return 0;
}