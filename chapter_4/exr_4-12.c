/* Solution to Exercise 4-12 of K&R */
#include <stdio.h>
#define MAXSIZE 100

void itoa(int n, char s[]);
int recursive_itoa(int n, int i, char s[]);

int main()
{
    int n = -1234;
    char s[MAXSIZE];
    itoa(n, s);
    printf("%s\n", s); // Output: -1234
    return 0;
}

int recursive_itoa(int n, int i, char s[])
{
    int r;

    if (n < 0) {
        s[i] = '-';
        n = -n;
    }

    r = n % 10;
    n /= 10;
    if (n) {
        i = recursive_itoa(n, i, s);
    }   
    s[++i] = r + '0';
    return i;
}

void itoa(int n, char s[])
{
    int i;

    i = recursive_itoa(n, 0, s);
    s[++i] = '\0';
}
