#include <stdlib.h>
#include <stdio.h>

void printbinary(int wert)
{

    for (int i = 8; i > 0; i--)
    {
        if (wert & 128)
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
        wert = wert << 1;
    }
}
void printhex(int wert)
{
    printf(" = 0x");
    for (int i = 4; i >= 0; i -= 4)
    {

        char temp = (wert >> i) & 0xf;

        if (temp > 9)
        {
            putchar('A' + temp - 10);
        }
        else
        {
            putchar('0' + temp);
        }
    }
}
int main(int argc, char const *argv[])
{
    unsigned char wert = atoi(argv[1]);
    unsigned char temp = 0;
    printf("%d = ",wert);
    printbinary(wert);
    printhex(wert);
    for (int i = 0; i < 8; i++)
    {
        temp = temp << 1;
        temp = temp + (wert & 1);
        wert = wert >> 1;
    }

    printf(" -> %d = ", temp);
    printbinary(temp);
    printhex(temp);

    return 0;
}
