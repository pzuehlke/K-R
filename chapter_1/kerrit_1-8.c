/* Following S. 1.8 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int power(int base, int n);

/* power: raise base to n-th power; n >=; version 2 */
int power(int base, int n) {
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

/* test power function */
int main(void) {
    int i;

    printf("exp b = 2 b = -3\n");
    for (i = 0; i < 11; ++i)
        printf("%2d %4d %6d\n", i, power(2, i), power(-3, i));

    return 0;
}
