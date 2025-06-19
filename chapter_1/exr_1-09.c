/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.9
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int main(void)
{
    unsigned blank_count = 0;
    int c;

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank_count;
            if (blank_count == 1) { putchar(c); }
        } else {
            putchar(c);
            blank_count = 0;
        }
    }

    return 0;
}
