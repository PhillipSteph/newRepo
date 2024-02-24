#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void convertbin(unsigned int wert)
{

    for (int i = 31; i >= 0; i--)
    {
        unsigned int temp = (wert >> i) & 1;
        putchar('0' + temp);
        if((i&3)==0){
            putchar(' ');
        }
    }
}

void converthex(unsigned int wert){

for(int i=28;i>=0;i-=4){

char temp = (wert>>i)&15;
if(temp>9){
    putchar('A'+temp-10);
}else{
    putchar('0'+temp);
}

}


}

int main(int argc, char const *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        unsigned int wert = atoi(argv[i]);
        convertbin(wert);
            putchar('\n');
        converthex(wert);
    }

    return 0;
}
