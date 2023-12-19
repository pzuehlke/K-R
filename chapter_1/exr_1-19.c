/* Solution to exercise 1-19 of K&R */
# include <stdio.h>
# define MAXLINE 1000   /* maximum input line size */

int get_line(char line[], int maxline);
int reverse_str(char rev[], char original[], int maxline);

/* Reverses its input one line at a time. */
int main(void)
{
    char line[MAXLINE];
    char rev[MAXLINE];

    while ((reverse_str(rev, line, MAXLINE)) > 0) {
        printf("%s", rev);
        /* Reset rev */
        rev[0] = '\0';
    }
    return 0;
}

/* reverse_str: read a line into s and reverse the order of its characters,
 * storing the result in the argument 'rev'. */
int reverse_str(char rev[], char s[], int lim)
{
    int c, i, m;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    m = i;  /* m is 1 + last index of the original string, discarding '\n' */
    for (i = 0; i < m; ++i)
        rev[i] = s[m - 1 - i];
    /* If the last character of s is '\n', record it as well in s and rev */
    if (c == '\n') {
        s[m] = c;
        rev[m] = c;
    }
    /* Terminate both strings properly */
    s[m + 1] = '\0';
    rev[m + 1] = '\0';

    return m;
}
