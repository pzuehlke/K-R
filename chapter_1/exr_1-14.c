/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.14
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define ASCII_SIZE 128  // Size of the ASCII character set

/* Prints a histogram of the frequencies of characters in the input. */
int main(void) {
    int c, i, j;
    int frequencies[ASCII_SIZE] = {0};

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        ++frequencies[c];
    }
    printf("\nCHARACTER  FREQUENCY");
    for (i = 0; i < ASCII_SIZE; ++i) {
        if (frequencies[i] > 0) {
            if (i == '\n')
                printf("\n\\n\t   ");
            else if (i == '\t')
                printf("\n\\t\t   ");
            else if (i == ' ')
                printf("\nspace\t   ");
            else
                printf("\n%c\t   ", i);
            for (j = 1; j <= frequencies[i]; ++j)
                printf("*");
        }
    }
    printf("\n");
    return 0;
}
