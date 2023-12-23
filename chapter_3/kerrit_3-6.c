/* Following S. 3.6 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <string.h>

/* Function prototypes */
void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char buffer[50];
    itoa(-12345, buffer);
    printf("%s\n", buffer);  // This should print "-12345"

    itoa(67890, buffer);
    printf("%s\n", buffer);  // This should print "+67890"
    
    return 0;
}

/* itoa: convert an integer n to characters in a string s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = n % 10 + '0';      /* get next digit */
    } while ((n /= 10) > 0);        /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
