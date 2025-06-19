/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.3
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int htoi(char s[]);

int main(void)
{
    char number[] = "0x1eb";    // in base ten: 491

    printf("The hexadecimal number '%s' represents %i\n",
            number, htoi(number));
    return 0;
}

/* htoi: convert a hexadecimal string representing a positive integer
 * to base 10. */
int htoi(char s[])
{
    int i = 0;
    char c;
    int digit;
    int number = 0;

    // Skip the optional '0x' or '0X':
    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        i += 2;
    }

    while ((c = s[i]) != '\0') {
        if ('0' <= c && c <= '9') {
            digit = c - '0';
        } else if ('a' <= c && c <= 'f') {
            digit = c - 'a' + 10;
        } else if ('A' <= c && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            printf("ERROR: Invalid hexadecimal number!");
            return -1;
            }
        number = 16 * number + digit;
        ++i;
    }
    return number;
}