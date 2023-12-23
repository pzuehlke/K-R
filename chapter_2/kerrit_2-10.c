/* Following S. 2.10 of Kernighan and Ritchie, "The C Programming Language" */
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

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            ++b;
    return b;
}

