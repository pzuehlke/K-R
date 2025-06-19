/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.13
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define IN 1            // Inside a word
#define OUT 0           // Outside a word
#define MAXLENGTH 50    // Maximum length of a word

/* Extracts the maximum of two integers. */
int max(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }   

/* Prints a histogram of the lengths of words in the input. */
int main(void) {
    int c, i, j;
    int length = 0, max_length = 0;
    int state = OUT;
    int counts[MAXLENGTH] = {0};
    
    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                max_length = max(length, max_length);
                ++counts[length];
                length = 0;
                state = OUT;
            }   
        } else {
            ++length;
            state = IN;
        }   
    }

    printf("LENGTH \t # OF WORDS");
    for (i = 0; i <= max_length; ++i) {
        if (counts[i] != 0) {
            printf("\n  %d\t   ", i);
            for (j = 1; j <= counts[i]; ++j)
                printf("*");
        }
    }
    printf("\n");
    return 0;
}