/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4-12
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define MAXSIZE 100

void itoa(int n, char s[]);
int recursive_itoa(int n, int i, char s[]);

int main()
{
    char s[MAXSIZE];

    int n = -1234;
    itoa(n, s);
    printf("%s\n", s); // Output: -1234

    char t[MAXSIZE];
    n = 12345;
    itoa(n, t);
    printf("%s\n", t); // Output: 12345
    return 0;
}

int recursive_itoa(int n, int i, char s[])
{
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    int r = n % 10;
    n /= 10;
    if (n) {
        i = recursive_itoa(n, i, s);
    }   
    s[i++] = r + '0';
    return i;
}

void itoa(int n, char s[])
{
    int i;

    i = recursive_itoa(n, 0, s);
    s[++i] = '\0';
}
