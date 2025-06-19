/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.5
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int main(void)
{
    const int LOWER = 0;
    const int UPPER = 300;
    const int STEP = 20;
    int fahr;
    float celsius;

    fahr = UPPER;

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3d %6.1f\n", fahr, celsius);
    }
    return 0;
}