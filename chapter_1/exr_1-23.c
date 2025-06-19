/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.23
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define OUT 0
#define INLINE 1
#define MULTILINE 2
#define IN_STRING 3

/* remove_comments: remove all comments from a C program. */
int main(void) {
    int c;
    char b = '\0';      // buffer character
    char state = OUT;

    while ((c = getchar()) != EOF) {
        // OUTSIDE of any comments or string constants:
        if (state == OUT) {
            if (b == '/' && c == '/') {
                state = INLINE;
            } else if (b == '/' && c == '*') {
                state = MULTILINE;
            } else {
                if (b == '/')
                    putchar(b);
                if (c != '/')
                    putchar(c);
            }
            b = c;
        }
        // Inside an INLINE comment:
        else if (state == INLINE) {
            if (c == '\n') {
                state = OUT;
                putchar(c);
                b = '\0';
            }
        }
        // Inside a MULTILINE comment:
        else if (state == MULTILINE) {
            if (b == '*' && c == '/') {
                state = OUT;
                b = '\0';
            } else { b = c; }
        }
    }

    return 0;
}
