/* Solution to Exercise 4-2 of K&R */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define NUMBER '0'      // signal that a number was found */
#define MAXLINE 1000    // maximum input line length
#define BUFSIZE 100     // size of buffer


int getch(void);
void ungetch(int);
double atof(char s[]);
int get_line(char s[], int lim);

/* rudimentary calculator */
int main(void)
{
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);
    char s1[] = "123.45";
    char s2[] = "-67.89";
    char s3[] = "0.00123";
    char s4[] = "   +42";
    char s5[] = "   -123.45e-6";

    printf("string: %s, double: %f\n", s1, atof(s1));
    printf("string: %s, double: %f\n", s2, atof(s2));
    printf("string: %s, double: %f\n", s3, atof(s3));
    printf("string: %s, double: %f\n", s4, atof(s4));
    printf("string: %s, double: %f\n", s5, atof(s5));

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    int exp = 0, exp_sign = 0;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }
    exp *= exp_sign;
    val *= pow(10.0, exp);
    return val;
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c!= '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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
