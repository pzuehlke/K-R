/* Solution to exercise 1-23 of K&R */
#include <stdio.h>

#define OUT 0
#define INLINE 1
#define MULTILINE 2

int main(void) {
    int c;
    char b = '\0';      // buffer character
    char state = OUT;

    while ((c = getchar()) != EOF) {
        // OUTSIDE of any comments:
        if (state == OUT) {
            if (b == '/' && c == '/')
                state = INLINE;
            else if (b == '/' && c == '*')
                state = MULTILINE;
            else {
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
            }
        }
        // Inside a MULTILINE comment:
        else if (state == MULTILINE) {
            if (b == '*' && c == '/')
                state = OUT;
            b = c;
        }
    }

    return 0;
}
