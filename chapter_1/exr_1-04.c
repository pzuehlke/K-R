/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.4
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

/* print Celsius -> Fahrenheit table for celsius = -40, -30, ..., 160 */

int main(void) {
    const int LOWER = -40;
    const int UPPER = 160;
    const int STEP = 10;
    int celsius;
    float fahr;

    celsius = LOWER;
    printf("Celsius \t Fahrenheit\n");
    while (celsius <= UPPER) {
        fahr = 9.0 / 5.0 * celsius + 32.0;
        printf("%3d\t\t %6.1f\n", celsius, fahr);
        celsius += STEP;
    }
    return 0;
}
