/* Solution to exercise 1-21 of K&R */
# include <stdio.h>

# define TABSTOP 8
# define BLANK 1
# define NONBLANK 0


int main(void)
{
    int i = 0, tabs = 0, spaces = 0, blank_count = 0;
    int next, position = 0;
    char c;
    char state = NONBLANK; 

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = BLANK;
            blank_count++;
        }
        else {
            if (state == BLANK) {
                tabs = blank_count / TABSTOP;
                spaces = blank_count % TABSTOP;
                for (i = 0; i < tabs; i++)
                    putchar('\t');
                for (i = 0; i < spaces; i++)
                    putchar(' ');
            }
            state = NONBLANK;
            blank_count = 0;
            putchar(c);
        }
    }

    return 0;
}
