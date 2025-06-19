/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.7
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

unsigned char invert(unsigned char x, int p, int n);
unsigned char setbits(unsigned char x, int p, int n, unsigned char y);
void print_binary(unsigned char x);


int main(void)
{
    unsigned char x, result;

    // Test 1
    x = 0b10101010; // Binary: 1010 1010
    result = invert(x, 4, 3);
    printf("Test 1: invert(");
    print_binary(x);
    printf(", 4, 3) = ");
    print_binary(result);
    printf("\n");

    // Test 2
    x = 0b11110000; // Binary: 1111 0000
    result = invert(x, 7, 4);
    printf("Test 2: invert(");
    print_binary(x);
    printf(", 7, 4) = ");
    print_binary(result);
    printf("\n");

    // Test 3
    x = 0b00001111; // Binary: 0000 1111
    result = invert(x, 3, 4);
    printf("Test 3: invert(");
    print_binary(x);
    printf(", 3, 4) = ");
    print_binary(result);
    printf("\n");

    return 0;
}


/* print_binary: print binary representation of an unsigned char number */
void print_binary(unsigned char x) {
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; --i) {
        putchar((x & (1u << i)) ? '1' : '0');
    }
}


/* invert(x, p, n): return x with the n bits from position p on inverted */
unsigned char invert(unsigned char x, int p, int n)
{
    unsigned char y;
    
    y = ~(x >> (p + 1 - n));    // delete rightmost digits, invert others
    return setbits(x, p, n, y);
}

/* setbits(x, p, n, y): return x with the n bits beginning at p
 * set to the rightmost n bits of y */
unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{
    unsigned char x_right, y_rightmost_n, x_left;

    x_right = x & ~(~0 << (p + 1 - n));      // bits after position p - n
    y_rightmost_n = y & ~(~0 << n);          // n rightmost bits of y
    x_left = (x >> (p + 1)) << n;            // n zeros from position p on
    return ((x_left | y_rightmost_n) << (p + 1 - n)) | x_right;
}
