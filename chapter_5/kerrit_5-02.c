/* Following S. 5.2 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100     // size of buffer

int getch(void);
void ungetch(int);
void swap(int *px, int *py);

int main(void)
{
    int a, b;
    a = 1;
    b = 2;
    swap(&a, &b);
    printf("x = %d,\t y = %d\n", a, b);
}

/* swap: interchange *px and *py */
void swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
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

