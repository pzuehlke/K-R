/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-12 (entab)
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8

/* entab: replace strings of consecutive blanks by the minimum number of tabs and
 * blanks to achieve the same spacing. */
int main(int argc, char* argv[])
{
    int c;
    int space_count = 0;    // pending spaces
    int position = 0;       // position of the cursor (incl. pending spaces)
    int start = 1;
    int every = TABSTOP;

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

    while ((c = getchar()) != EOF) {
        ++position;
        if (c == ' ') {
            ++space_count;
            if (start <= position && (position - start + 1) % every == 0) {
                putchar('\t');      // Output tab to avoid using spaces
                space_count = 0;
            }
        } else {
            while (space_count > 0) {  // Output pending spaces
                putchar(' ');
                --space_count;
            }
            putchar(c);
            if (c == '\n') {
                position = 0;
            } else if (c == '\t') {
                if (position < start) { position = start; }
                else { position += every - (position - start + 1) % every; }
            }
        }
    }
    return 0;
}
