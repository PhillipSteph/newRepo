#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    
    unsigned int wert = atoi(argv[1]);
    for(int i=28;i>=0;i-=4){

        unsigned int bytes = (wert >> i) & 0xf;
        if(bytes>9){
            char hexa = 'A'+bytes-10;
            putchar(hexa);
        }else if(bytes < 10){
            putchar('0'+bytes);
        }

    }


    return 0;
}
