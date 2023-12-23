/* Following S. 2.7 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int atoi(char s[]);
char lower(char c);
int my_rand(void);
int my_srand(unsigned int seed);
unsigned long int next = 1;


int main(void)
{
    char number[] = "12345";
    char c = 'P';

    printf("The given number is: %i.\n", atoi(number));
    printf("The lowercase version of '%c' is: '%c'\n", c, lower(c));

    return 0;
}


int atoi(char s[])
{
    int i, n;

    for (i = 0; '0' <= s[i] && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}


char lower(char c)
{
    if ('A' <= c && c <= 'Z')
        c = c - 'A' + 'a';
    return c;
}


int my_rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}


int my_srand(unsigned int seed)
{
    next = seed;
}
