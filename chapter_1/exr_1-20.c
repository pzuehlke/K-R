/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.20
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define TABSTOP 8

/* detab: replace tabs in the input with the proper number of blanks to space
   until the next tab stop. */
int main(void)
{
    int i = 0, position = 0, next;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            next = TABSTOP - (position % TABSTOP);
            for (i = 0; i < next; ++i) {
                putchar(' ');
                ++position;
            }
        } else if (c == '\n') {
            putchar('\n');
            position = 0;
        } else {
            putchar(c);
            ++position;
        }
    }

    return 0;
}