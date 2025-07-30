/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-12 (detab)
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8
/* detab: replace tabs in the input with the proper number of blanks to space
   until the next tab stop. */
int main(int argc, char* argv[])
{
    int start = 1;
    int every = TABSTOP;
    int c;

    while (--argc > 0 && ((c = **++argv) == '-' || c == '+')) {
        int n = atoi(++*argv);
        switch (c) {
            case '-':
                start = n;
                break;
            case '+':
                every = n;
                break;
            default:
                printf("ERROR: invalid option %c", c);
                break;
        }
    }

    int i = 0, position = 0, next;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (position < start) { next = start; }
            else { next = every - (position - start + 1) % every; }
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
