/* Solution to Exercise 1-15 of K&R */
#include <stdio.h>
#define LOWER -40
#define UPPER 300
#define STEP 20

float convert(int fahr);

/* print Fahrenheit-Celsius table. */
int main(void) {
    int fahr;
    float celsius;

    printf("FAHR    CELSIUS\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        celsius = convert(fahr);
        printf("%3d\t%5.1f\n", fahr, celsius);
    }
    return 0;
}

/* float: convert a temperature in Fahrenheit to Celsius. */
float convert(int fahr) {
    return 5.0 * (fahr - 32) / 9.0;
}
