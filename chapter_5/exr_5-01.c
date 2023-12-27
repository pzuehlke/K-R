/* Solution to Exercise 5-1 of K&R */
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100     // size of buffer

int getch(void);
void ungetch(int);

int main(void)
{
    int n, array[5], getint(int *);

    for (n = 0; n < 5 && getint(&array[n]) != EOF; n++) {
        printf("Stored in array[%d]: %d\n", n, array[n]);
    }

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{

    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c!= EOF && c!= '+' && c != '-') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

char buf[BUFSIZE];      /* buffer for ungetch */
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

