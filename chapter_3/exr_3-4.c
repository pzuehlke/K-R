/* Solution to Exercise 3-4 of K&R */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* The original version does not work for -2^(wordsize - 1) because this
 * number, like 0, is its own 2's complement. In particular, its 2's complement
 * is not positive. */

void reverse(char s[]);
void itoa(int n, char s[]);

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert an integer n to characters in a string s */
void itoa(int n, char s[])
{
    int i, sign;

    i = 0;
    if ((sign = n) < 0) {     // record sign
        do {                            // generate digits in reverse order
            s[i++] = -(n % 10) + '0';   // get next digit
            n /= 10;
        } while (n != 0);               // delete it
    }
    else
        do {                            // generate digits in reverse order
            s[i++] = (n % 10) + '0';    // get next digit
        } while (n /= 10 > 0);          // delete it
    if (sign < 0)
        s[i++] = '-';
    else
        s[i++] = '+';
    s[i] = '\0';
    reverse(s);
}


int main() {
    char buffer[50];

    itoa(INT_MIN, buffer);
    printf("%s\n", buffer);     // This should print "-2147483648" on a typical
                                // 32-bit system

    return 0;
}
