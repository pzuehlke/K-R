/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4.7
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>     // for strlen

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


/* ungets: push back an entire string onto the input. Since the buffer
   is a stack, we push s in reverse order. */
void ungets(char s[])
{
    int i;

    for (i = strlen(s) - 1; i >= 0; --i)
        ungetch(s[i]);
}