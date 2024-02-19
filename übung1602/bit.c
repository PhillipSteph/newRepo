#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

char wert = 5;   // 0000 0101
//wir können den bit wert verschieben.
char a;
a = wert >> 1; // eins nach rechts
                // 0000 0010
//oder wieder nach links
a = wert << 1;
                // 0000 1010
a = 35 & 15;
                // 0010 0011 
               //& 0000 1111
                // 0000 0011
int zahl = 64;
                // 0100 0000
                // 0000 0011

                // 0100 0011
                // 0000 0011
                // 0000 0011

                //zahl & 3 == 3
                //0100 0000
                //0000 0011
                //0000 0000
if(zahl&3 == 0){
   printf("durch 4 teilbar"); 
}

// printe die dezimalzahl als Dualzahl.
zahl = 29;
// 0001 1101
for(int i=7;i>=0;i--){
    int a = (zahl >> i) & 1; // 0000 0001 || 0000 0000
    putchar('0'+a); //printf("%c",'0'+a);
    
    
    if((i&3)==0){ //i 4 = 0000 0100
                  //i 28= 0001 1100

                  //& 3 = 0000 0011
        putchar(' '); // 
    }
}



    return 0;
}
