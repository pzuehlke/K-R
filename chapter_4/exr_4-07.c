/* Solution to Exercise 4-7 of K&R */
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

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

/* ungets: push back an entire string onto the input */
void ungets(char s[])
{
    int i;

    for (i = 0; i < strlen(s); i++)
        ungetch(s[i]);
}
