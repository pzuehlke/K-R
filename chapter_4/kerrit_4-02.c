/* Following S. 4.2 of Kernighan and Ritchie, "The C Programming Language" */
#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
int main(void)
{
    double sum, atof(char []);
    char line[MAXLINE];
    int get_line(char line[], int max);
    int atoi(char s[]);
    char s1[] = "123.45";
    char s2[] = "-67.89";
    char s3[] = "0.00123";
    char s4[] = "   +42";

    printf("String: %s, Double: %f\n", s1, atof(s1));
    printf("String: %s, Double: %f\n", s2, atof(s2));
    printf("String: %s, Double: %f\n", s3, atof(s3));
    printf("String: %s, Double: %f\n", s4, atof(s4));

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
    return sign * val / power;
}

int atoi(char s[])
{
    double atof(char s[]);

    return (int) atof(s);
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
