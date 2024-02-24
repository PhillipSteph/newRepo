#include <stdlib.h>
#include <stdio.h>


int switchbytes(int wert){
unsigned int temp=0;
unsigned int res;
//1:
temp += (wert>>24) & 0x000000FF;
//2
temp += (wert>>8) & 0x0000FF00;
//3
temp += (wert<<8) & 0x00FF0000;
//4
temp += (wert<<24) & 0xFF000000;
return temp;
}

int main(int argc, char const *argv[])
{

unsigned int wert = atoi(argv[1]);
unsigned int reverse = switchbytes(wert);

printf("%08X -> %08X",wert,reverse);
    return 0;
}
