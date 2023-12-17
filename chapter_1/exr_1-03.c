/* Solution to Exercise 1-3 of K&R */
#include <stdio.h>

int main(void) {
    const int LOWER = 0;
    const int UPPER = 300;
    const int STEP = 20;
    int fahr;
    float celsius;

    fahr = LOWER;

    printf("=== TEMPERATURE CONVERSION ===\n");
    printf("Fahr Celsius\n");
    while (fahr <= UPPER) {
        celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
    return 0;
}




