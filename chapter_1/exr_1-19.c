/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.19
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define MAXLINE 1000   // maximum input line size

int get_line(char line[], int maxline);
int reverse_str(char rev[], char original[], int maxline);
int min(int i, int j);

/* Reverses its input one line at a time. */
int main(void)
{
    char line[MAXLINE];
    char rev[MAXLINE];
    int m;

    while ((m = get_line(line, MAXLINE)) > 0) {
        reverse_str(rev, line, MAXLINE);
        printf("%s", rev);
        rev[0] = '\0';  // reset `rev`
    }
    return 0;
}

/* reverse_str: reverse the order of a string `s` to produce `rev`. At most `lim`
 * characters are considered. */
int reverse_str(char rev[], char s[], int lim)
{
    int i, j;
    for (i = 0; i < lim && s[i] != '\0'; ++i) { ; }
    int length = i;  // length of s, not considering the null character

    for (i = 0, j = length - 1 - i; s[i] != '\0' && j >= 0; ++i, --j) {
        if (s[j] == '\n') {
            rev[j] = '\n';
            --j;
        }
        rev[i] = s[j];
    }
    rev[++i] = '\0';

    return length;
}

/* get_line: read (at most lim characters of) a line into s, return length. */
int get_line(char s[], int lim)
{
    int c, i, m;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1)
            s[i] = c;
    }
    if ((c == '\n') && (i < lim - 1)) {
        s[i] = '\n';
        ++i;
    }

    m = min(lim - 1, i);
    s[m] = '\0';
    return m;
}

/* Returns the smallest of two integers i and j. */
int min(int i, int j)
{
    if (i <= j)
        return i;
    else
        return j;

}