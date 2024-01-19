#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reverse(int a);

int main(int argc, const char *argv[]){
    if(argc!=2){
        return 1;
    }

int wert = atoi(argv[1]);
reverse(wert);
return 0;
}

void reverse(int a){
    if(a>9){
        putchar(a%10+'0');
        reverse(a/10);
    
    }else (
        putchar(a%10+'0')
    );
}