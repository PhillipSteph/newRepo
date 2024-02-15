#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    

    int wert = 2604;

    for(int i=28; i>=0; i-=4){
        int temp = (wert >> i) & 0xf;
        if(temp>=10){
            putchar('A'+temp-10);
        }else if(temp>=0){
            putchar('0'+temp);
        }
    }
    printf("\n");
    return 0;
}
