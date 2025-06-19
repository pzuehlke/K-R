/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.6
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int main(void)
{
    int c, d;

    // First testing whether the comparison yields 0 or 1 for given characters:
    c = 'a';
    d = EOF;
    printf("%d\n", c != EOF);
    printf("%d\n", d != EOF);

    // Now testing using `getchar`:
    printf("%d\n", (getchar() != EOF));
    printf("%d\n", (getchar() != EOF));

    return 0;
}
