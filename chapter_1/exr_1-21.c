/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.21
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define TABSTOP 8

/* entab: replace strings of consecutive blanks by the minimum number of tabs and
 * blanks to achieve the same spacing. */
int main(void)
{
    int c;
    int space_count = 0;    // pending spaces
    int position = 0;       // position of the cursor (incl. pending spaces)

    while ((c = getchar()) != EOF) {
        ++position;
        if (c == ' ') {
            ++space_count;
            if (position % TABSTOP == 0) {
                putchar('\t');      // Output tab to avoid using spaces
                space_count = 0;
            }
        } else {
            while (space_count > 0) {  // Output pending spaces (< TABSTOP)
                putchar(' ');
                --space_count;
            }
            putchar(c);
            if (c == '\n') {
                position = 0;
            } else if (c == '\t') {
                position += (TABSTOP - position % TABSTOP); 
            }
        }
    }
    return 0;
}
