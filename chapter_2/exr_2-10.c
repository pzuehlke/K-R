/* Solution to Exercise 2-10 of K&R */
#include <stdio.h>

int lower(int c);


int main(void)
{
    char test_chars[] = {'A', 'Z', 'a', 'z', '0', '#', 'G'};
    int num_tests = sizeof(test_chars) / sizeof(test_chars[0]);

    for (int i = 0; i < num_tests; ++i)
    {
        printf("lower('%c') = '%c'\n", test_chars[i], lower(test_chars[i]));
    }

    return 0;
}


/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return ('A' <= c && c <= 'Z') ? (c - 'A' + 'a') : c;
}
