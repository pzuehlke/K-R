/* Following S. 1.6 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int power(int b, int n);

/* test power function */
int main(void) {
    int i;

    printf("exp b = 2 b = -3\n");
    for (i = 0; i < 11; ++i)
        printf("%2d %4d %6d\n", i, power(2, i), power(-3, i));

    return 0;
}

/* power: raise base b to the n-th power; works only for n >= 0 */
int power(int b, int n) {
    int i, p;

    p = 1;
    for (i = 1; i < n + 1; ++i)
        p *= b;
    return p;
}
