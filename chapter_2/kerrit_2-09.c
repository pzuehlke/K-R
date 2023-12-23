/* Following S. 2.9 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);


int main(void)
{
    unsigned x;
    int p, n;

    /* Test 1 */
    x = 0b10101010; // Binary: 1010 1010
    p = 4;
    n = 3;
    printf("getbits(%u, %d, %d) = %u\n", x, p, n, getbits(x, p, n));
    // Expected output: 5 (binary 101)

    /* Test 2 */
    x = 0b11110000; // Binary: 1111 0000
    p = 7;
    n = 4;
    printf("getbits(%u, %d, %d) = %u\n", x, p, n, getbits(x, p, n));
    // Expected output: 15 (binary 1111)

    /* Test 3 */
    x = 0b00001111; // Binary: 0000 1111
    p = 3;
    n = 4;
    printf("getbits(%u, %d, %d) = %u\n", x, p, n, getbits(x, p, n));
    // Expected output: 15 (binary 1111)

    return 0;
}


/* getbits: get n bits from position p to the right */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p - n + 1)) & ~(~0 << n);
}
