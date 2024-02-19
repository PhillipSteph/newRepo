#include <stdlib.h>
#include <stdio.h>


void bit(unsigned char zahl){

// zahl = 17 = 0001 0001


// zahl = 100 = 0110 0100   
// zahl = 101 = 0110 0101
// zahl = 131 = 1000 0011
// zahl = 40 =  0010 1000
//wenn hinteren beide 0 sind -> durch vier teilbar

// zahl & 3 == 0


}




int main(int argc, char const *argv[])
{
    // invertiere eine allgemeine Integer bitweise. 0001 1010 -> 0101 1000
    //  1111 0000 -> 0000 1111
    //
    // erstelle eine Funktion, welche die Ausgangszahl und das Ergebnis bitweise auf die
    // kommandozeile ausgibt.

    for (int i = 1; i < argc; i++)
    {
        unsigned char wert = atoi(argv[i]);
        unsigned char temp = 0;
        for (int i = 0; i < 8; i++)
        {
            temp = temp << 1;
            unsigned char a = (wert >> i) & 1;
            temp += a;
        }
        printf("%d ", temp);
    }
    return 0;
}
