#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wurzel(double n, double base);

int main(int argc, char const *argv[])
{
    printf("%3fe Wurzel aus %3f = %3f",atof(argv[1]),atof(argv[2]),wurzel(atof(argv[1]),atof(argv[2])));
    return 0;
}

double wurzel(double n, double base)
{
    double power = 1 / n;

    double ergebnis = pow(base, power);

    return ergebnis;
}