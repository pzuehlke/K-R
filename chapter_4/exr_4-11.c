/* Solution to Exercise 4-10 of K&R */

#include <stdio.h>

int getop(char s[])


int main(void)
{
    return 0;
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
