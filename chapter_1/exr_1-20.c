/* Solution to exercise 1-20 of K&R */
# include <stdio.h>

# define TABSTOP 8

int detab(void);


int main(void)
{
    detab();
    return 0;
}


int detab(void)
{
    int i = 0, position = 0, next;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            next = TABSTOP - (position % TABSTOP);
            for (i = 0; i < next; i++) {
                putchar(' ');
                position++;
            }
        }
        else if (c == '\n')
        {
            putchar('\n');
            position = 0;
        }
        else {
            putchar(c);
            position++;
        }
    }

    return 0;
}
