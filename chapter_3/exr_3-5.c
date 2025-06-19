/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 3.5
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);


/* itob: convert an integer n to characters into its base b representation.
 * Store the result in string s */
void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (b < 2 || b > 36)
        printf("ERROR: The base b must lie between 2 and 36.");
    if (sign < 0)
        n = -n;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/* reverse: reverse the characters of string s. */
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


int main() {
    char buffer[64];
    char buffer2[64];
    int number = -54321;
    int number2 = 255;
    int base = 16;

    itob(number, buffer, base);
    itob(number2, buffer2, base);
    printf("The base-%d form of %d is: %s\n", base, number, buffer);
    printf("The base-%d form of %d is: %s\n", base, number2, buffer2);

    return 0;
}