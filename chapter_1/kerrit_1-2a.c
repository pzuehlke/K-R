/* Follows the content of section 1-2 of K&R */
# include <stdio.h>

/* Prints the size of several types in C. */

int main(void) {
    printf("Size of int: %ld\n", sizeof(int));
    printf("Size of short: %ld\n", sizeof(short));
    printf("Size of long: %ld\n", sizeof(long));
    printf("Size of float: %ld\n", sizeof(float));
    printf("Size of double: %ld\n", sizeof(double));
    printf("Size of long double: %ld\n", sizeof(long double));
    printf("Size of char: %ld\n", sizeof(char));
    return 0;
}
