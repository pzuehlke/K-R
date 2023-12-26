/* Solution to Exercise 4-9 of K&R */
/* It suffices to change the type of buf from an array of characters
 * to an array of integers */
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);

int main() {
    int c;
    while ((c = getch()) != EOF) {
        putchar(c);
    }
    return 0;
}

int buf[BUFSIZE];       /* buffer for ungetch */
int bufp = 0;           /* next free position in buffer */

/* getch: Get a (possibly pushed back) character */
int getch(void)     
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ERROR in ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}
