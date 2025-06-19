/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4-11
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define NUMBER '0'      // signal that a number was found
#define VAR '1'         // signal that a variable was found
#define LAST '2'        // signal that the 'last seen' variable was found

int getop(char s[]);


int main(void)
{
    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != '_') {
        return c;       /* not a number */
    }
    if (c == '_')
        return LAST;
    if (isupper(c))
        return VAR;
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch())) {  // negative number
            s[++i] = c;
        } else {    // not a negative number
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {     /* collect fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getop(char s[])
{
    int i, c;
    static int buf = '\0';

    if (buf != '\0') {
        s[0] = c = buf;
        buf = '\0';
    }
    else {
        while ((s[0] = c = getchar()) == ' ' || c == '\t')
            ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c!= '-' && !isupper(c))
        return c;       /* not a number */
    if (isupper(c))
        return VAR;
    i = 0;
    if (c == '-') {
        if (isdigit(c = getchar()))
            s[++i] = c;
        else {
            buf = c;
            return '-';
        }
    }
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF && c != ' ' && c != '\t')
        buf = c;
    return NUMBER;
}