/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.12
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define IN 1    // Inside a word
#define OUT 0   // Outside a word

/* Prints its input one word per line */
int main(void)
{
    int c, state;

    state = OUT;
    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            state = IN;
        }
    }

    return 0;
}