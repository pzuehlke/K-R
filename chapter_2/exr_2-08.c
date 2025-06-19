/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.8
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

unsigned char rightrot(unsigned char x, int n);
int number_of_digits(int x);
void print_binary(unsigned char x);


int main(void)
{
    unsigned char x, result;

    // Test 1
    x = 0b10001010; // Binary: 1000 1010
    result = rightrot(x, 4);
    printf("Test 1: rightrot(");
    print_binary(x);
    printf(", 4) = ");
    print_binary(result);
    printf("\n");

    // Test 2
    x = 0b11110000; // Binary: 1111 0000
    result = rightrot(x,2);
    printf("Test 2: rightrot(");
    print_binary(x);
    printf(", 2) = ");
    print_binary(result);
    printf("\n");

    // Test 3
    x = 0b00001111; // Binary: 0000 1111
    result = rightrot(x, 8);
    printf("Test 3: rightrot(");
    print_binary(x);
    printf(", 8) = ");
    print_binary(result);
    printf("\n");

    return 0;
}


/* print_binary: print binary representation of an unsigned char number */
void print_binary(unsigned char x) {
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; i--) {
        putchar((x & (1u << i)) ? '1' : '0');
    }
}


/* number_of_digits: compute the number of significant bits of an integer */
int number_of_digits(int x)
{
    int digits = 0;
    while (x) {
        x >>= 1;
        ++digits;
    }
    return digits;
}


/* rightrot(x, n): return x rotated to the right by n bit positions */
unsigned char rightrot(unsigned char x, int n)
{
    unsigned char rightmost;
    int d = number_of_digits(x);

    n %= d;
    rightmost = x & ~(~0 << n);
    x = x >> n;
    return (rightmost << (d - n)) | x;
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