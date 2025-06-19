/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4.8
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int getch(void);
void ungetch(int);

int buf = EOF;      /* buffer for ungetch */


/* getch: Get a (possibly pushed back) character */
int getch(void)     
{
    if (buf == EOF) {
        getchar();
    } else {
        int c = buf;
        buf = EOF;
        return c;
    }
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