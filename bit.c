#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define mask1 128
#define mask2 1

unsigned int switchbits(unsigned int byte)
{
    unsigned int wert = byte;
    // angenommen 37 == 0010 0101
    unsigned int temp1 = 0; // 0000 0000
    for (int i = 0; i < 8; i++)
    {
        temp1 = temp1 >> 1;
        temp1 = (wert & mask1) | temp1;
        wert = wert << 1;
    } // 1010 0100 = 4+32+128 = 164
    return temp1;
}
int main(int argc, char const *argv[])
{

    unsigned int wert = atoi(argv[1]);
    static char arr[8];
    while (1)
    {
        if ((wert & mask1) == mask1)
        {
            wert = switchbits(wert);
        }
        else
        {
            wert = wert << 1;
        }
        printf("\n%3d ", wert);
        for (int i = 7; i >= 0; --i) {
    
      unsigned int digit = (wert >> i) & 1;
      putchar('0' + digit);
        arr[i]=digit;

      if (((i & 3) == 0) && (i != 0)) putchar(' ');
    }
    
        Sleep(100);
    } // 5 = 0000 0101
    // 160 = 1010 0000
    //  4  = 0000 0100
    return 0;
}
