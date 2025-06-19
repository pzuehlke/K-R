/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4.2
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main(void)
{
    char s1[] = "123.45";
    char s2[] = "-67.89";
    char s3[] = "0.00123";
    char s4[] = "   +42";
    char s5[] = "   -123.45e-6";

    printf("string: %s,\t\tdouble: %f\n", s1, atof(s1));
    printf("string: %s,\t\tdouble: %f\n", s2, atof(s2));
    printf("string: %s,\tdouble: %f\n", s3, atof(s3));
    printf("string: %s,\t\tdouble: %f\n", s4, atof(s4));
    printf("string: %s,\tdouble: %f\n", s5, atof(s5));

    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    int exp = 0, exp_sign = 1;

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
    val *= pow(10.0, exp * exp_sign);
    return val;
}