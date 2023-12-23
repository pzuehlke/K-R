/* Solution to Exercise 2-1 of K&R */
#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Summary (for my computer):
 * Char: 1 Byte
 * Short: 2 Bytes
 * Int: 4 Bytes
 * Long: 8 Bytes
 * Long Long: 8 Bytes
 * Float: 4 Bytes
 * Double: 8 Bytes
 * Long Double: 16 Bytes    */

/* Determines the ranges of `char`, `int`, `float` and `double` of
 * various kinds. */
int main(void) {
    printf("Ranges of Data Types\n");
    printf("--------------------\n");

    printf("Char:\n");
    printf("Size: %ld bytes\n", sizeof(char));
    printf("Minimum: %d\n", CHAR_MIN);
    printf("Maximum: %d\n\n", CHAR_MAX);

    printf("Unsigned Char:\n");
    printf("Size: %ld bytes\n", sizeof(unsigned char));
    printf("Minimum: 0\n");
    printf("Maximum: %u\n\n", UCHAR_MAX);

    printf("Short:\n");
    printf("Size: %ld bytes\n", sizeof(short));
    printf("Minimum: %d\n", SHRT_MIN);
    printf("Maximum: %d\n\n", SHRT_MAX);

    printf("Unsigned Short:\n");
    printf("Size: %ld bytes\n", sizeof(unsigned short));
    printf("Minimum: 0\n");
    printf("Maximum: %u\n\n", USHRT_MAX);

    printf("Int:\n");
    printf("Size: %ld bytes\n", sizeof(int));
    printf("Minimum: %d\n", INT_MIN);
    printf("Maximum: %d\n\n", INT_MAX);

    printf("Unsigned Int:\n");
    printf("Size: %ld bytes\n", sizeof(unsigned int));
    printf("Minimum: 0\n");
    printf("Maximum: %u\n\n", UINT_MAX);

    printf("Long:\n");
    printf("Size: %ld bytes\n", sizeof(long));
    printf("Minimum: %ld\n", LONG_MIN);
    printf("Maximum: %ld\n\n", LONG_MAX);

    printf("Unsigned Long:\n");
    printf("Size: %ld bytes\n", sizeof(unsigned long));
    printf("Minimum: 0\n");
    printf("Maximum: %lu\n\n", ULONG_MAX);

    printf("Long Long:\n");
    printf("Size: %ld bytes\n", sizeof(long long int));
    printf("Minimum: %lld\n", LLONG_MIN);
    printf("Maximum: %lld\n\n", LLONG_MAX);

    printf("Float:\n");
    printf("Size: %ld bytes\n", sizeof(float));
    printf("Minimum: %E\n", FLT_MIN);
    printf("Maximum: %E\n\n", FLT_MAX);

    printf("Double:\n");
    printf("Size: %ld bytes\n", sizeof(double));
    printf("Minimum: %E\n", DBL_MIN);
    printf("Maximum: %E\n\n", DBL_MAX);

    printf("Long Double:\n");
    printf("Size: %ld bytes\n", sizeof(long double));
    printf("Minimum: %LE\n", LDBL_MIN);
    printf("Maximum: %LE\n\n", LDBL_MAX);

    return 0;
}
