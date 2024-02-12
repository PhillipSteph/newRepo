// Ausgabe von Zahlen binär und hexadezimal
//
// Aufruf: binhex n1 n2 ...
//
// Klaus Kusche

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Aufruf: %s n1 n2 ...\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  for (int arg = 1; arg < argc; ++arg) {
    unsigned int n = atoi(argv[arg]);
    printf("%10u: ", n);

    for (int i = 28; i >= 0; i -= 4) {  // Schleife 28, 24, 20, ..., 0

      unsigned int digit = (n >> i) & 0xf;
      if (digit < 10) putchar('0' + digit);
      else putchar('A' + digit - 10);
      if (i == 16) putchar(' ');    // nach Bits 16-19 Zwischenraum machen
    }

    putchar(' ');
    putchar(' ');

    // Binär
    for (int i = 31; i >= 0; --i) {
    
      unsigned int digit = (n >> i) & 1;
      putchar('0' + digit);

      if (((i & 3) == 0) && (i != 0)) putchar(' ');
    }

    putchar('\n');
  }

  exit(EXIT_SUCCESS);
}