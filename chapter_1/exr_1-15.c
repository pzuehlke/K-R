/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.15
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define LOWER -40
#define UPPER 300
#define STEP 20

float convert_fahr_to_celsius(float fahr);

/* print Fahrenheit-Celsius table. */
int main(void) {
    int fahr;
    float celsius;

    printf("FAHR    CELSIUS\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        celsius = convert_fahr_to_celsius(fahr);
        printf("%3d\t%5.1f\n", fahr, celsius);
    }
    return 0;
}

/* convert_fahr_to_celsius: convert a temperature in Fahrenheit to Celsius. */
float convert_fahr_to_celsius(float fahr) {
    return 5.0 * (fahr - 32) / 9.0;
}
