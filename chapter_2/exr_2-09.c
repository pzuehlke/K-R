/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.9
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>


int bitcount(unsigned x);


int main(void)
{
    int i;
    unsigned test_values[] = {0, 1, 2, 3, 255, 256, 1023, 1024};
    int expected_results[] = {0, 1, 1, 2, 8, 1, 10, 1};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; ++i) {
        printf("bitcount(%u) = %i\n", test_values[i], bitcount(test_values[i]));
        printf("exp. result = %i\n\n", expected_results[i]);
    }

    return 0;
}


/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
            ++b;
    return b;
}

/* Reasoning: Given any positive integer x, we can decompose its binary
 * representation as n = (ab)_2 where:
 *  - b = 100...0 (of length, say, m bits). That is, b consists of the
 *    rightmost 1 bit and whatever comes after that;
 *  - a is whatever sequence of bits is to the left of the rightmost 1 bit.
 *
 * Then x - 1 equals (ac)_2, where c is the inverse of b:
 *  - c = 011...1 (negate each of the m bits of b) .
 *
 * Consequently x & (x - 1) equals (ad)_2 where d = 000...0 (m bits). It
 * follows that everytime this operation is performed, we delete the rightmost
 * 1 bit of the current value of x, leaving the remaining bits unchanged. */