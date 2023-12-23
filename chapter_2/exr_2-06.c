/* Solution to Exercise 2-6 of K&R */
#include <stdio.h>

unsigned char setbits(unsigned char x, int p, int n, unsigned char y);
void print_binary(unsigned char x);


int main(void)
{
    unsigned char x, y, result;

    // Test 1: Replace middle bits
    x = 0b11011101; // Binary: 1101 1101
    y = 0b10101010; // Binary: 1010 1010
    result = setbits(x, 4, 3, y);
    printf("Test 1: setbits(");
    print_binary(x);
    printf(", 4, 3, ");
    print_binary(y); 
    printf(") \n\t\t= ");
    print_binary(result);
    printf("\nExpected result:  11001001\n\n");

    // Test 2: Replace least significant bits
    x = 0b11011101;
    y = 0b00110011;
    result = setbits(x, 2, 3, y);
    printf("Test 2: setbits(");
    print_binary(x);
    printf(", 2, 3, ");
    print_binary(y); 
    printf(") \n\t\t= ");
    print_binary(result);
    printf("\nExpected result:  11011011\n\n");

    // Test 3: Replace most significant bits
    x = 0b11011101;
    y = 0b10101010;
    result = setbits(x, 7, 4, y);
    printf("Test 3: setbits(");
    print_binary(x);
    printf(", 7, 4, ");
    print_binary(y); 
    printf(") \n\t\t= ");
    print_binary(result);
    printf("\nExpected result:  10101101\n\n");

    return 0;
}


/* print_binary: print binary representation of an unsigned char number */
void print_binary(unsigned char x) {
    int i;
    for (i = 8 * sizeof(unsigned char) - 1; i >= 0; i--) {
        putchar((x & (1u << i)) ? '1' : '0');
    }
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


