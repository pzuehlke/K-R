/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 3.4
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <limits.h>

/* The original version does not work for -2^(wordsize - 1) because this
 * number, like 0, is its own 2's complement. In particular, its 2's complement
 * is not positive. */

void reverse(char s[]);
void itoa(int n, char s[]);


/* reverse: reverse the characters of string s. */
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
    // If n is positive, we can follow the same strategy as in the text.
    // If n is negative, instead of trying to invert its sign, we work
    // with n itself. If -10 < d <= -1, then d % 10 = d. Hence,
    // -(d % 10) will give the same digit with a plus sign.
    if ((sign = n) < 0) {     // negative n, record sign
        do {                            // generate digits in reverse order
            s[i++] = -(n % 10) + '0';   // get next digit
            n /= 10;
        } while (n != 0);
    } else {    // positive n, proceed as in the original version
        do {                            // generate digits in reverse order
            s[i++] = (n % 10) + '0';    // get next digit
        } while ((n /= 10) > 0);
    }

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
    printf("%s\n", buffer);     // This should print "-2147483648"
    itoa(-37, buffer);
    printf("%s\n", buffer);
    itoa(37, buffer);
    printf("%s\n", buffer);
    itoa(0, buffer);
    printf("%s\n", buffer);

    return 0;
}