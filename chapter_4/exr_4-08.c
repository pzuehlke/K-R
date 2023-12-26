/* Solution to Exercise 4-8 of K&R */
#include <stdio.h>

int getch(void);
void ungetch(int);

int buf = EOF;      /* buffer for ungetch */

/* getch: Get a (possibly pushed back) character */
int getch(void)     
{
    return (buf == EOF) ? getchar() : buf;
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (buf != EOF)
        printf("ERROR in ungetch: Too many characters!\n");
    else
        buf = c;
    return;
}
