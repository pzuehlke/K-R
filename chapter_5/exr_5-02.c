/* Solution to Exercise 5-2 of K&R */
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100     // size of buffer

int getch(void);
void ungetch(int);
int getfloat(float *px);

int main(void) {
    float number;
    while (getfloat(&number) != EOF) {
        printf("Read float: %f\n", number);
    }
    return 0;
}


/* getfloat: get next float from input into *px */
int getfloat(float *px)
{

    int c, sign, power = 1;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c!= EOF && c!= '+' && c != '-' && c != '.') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*px = 0; isdigit(c); c = getch())
        *px = 10 * *px + (c - '0');
    if (c == '.') {
        while (isdigit(c = getch())) {
            *px = 10 * *px + (c - '0');
            power *= 10.0;
        }
    }
    *px = sign * *px / power;
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

