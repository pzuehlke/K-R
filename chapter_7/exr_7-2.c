/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-02
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 80    // maximum length of a line
#define TAB_WIDTH 8

unsigned char_width(int c, unsigned position)
{
    if (c == '\t') {
        return TAB_WIDTH - (position % TAB_WIDTH);
    } else if (isprint(c)) {
        return 1;
    } else if (c == '\n') {
        return 0;
    } else {    // will print octal code of `c`
        return 4;
    }
}

int main() {
    int c;
    unsigned position = 0;

    while ((c = getchar()) != EOF) {
        unsigned width = char_width(c, position);

        // If line limit is exceeded, move to the next line:
        if (MAX_LENGTH < position + width && c != '\n') {
            putchar('\n');
            position = 0;
            width = char_width(c, 0);   // need to recalculate for tabs
        }

        // Print the character:
        if (isprint(c) || c == ' ' || c == '\t' || c == '\n') {
            putchar(c);
        } else {
            printf("\\%03o", c);
        }

        // Update position:
        position += width;
    }

    return 0;
}