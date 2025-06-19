/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.18
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define MAXLINE 1000   // maximum input line size

int get_line_until_last_nonblank(char line[], int maxline);

/* Removes trailing blanks and tabs from each line of input. */
int main(void)
{
    char line[MAXLINE];
    char slice[MAXLINE];
    int len;

    while ((len = get_line_until_last_nonblank(line, MAXLINE)) > 0) {
        printf("%s", line);
    }
    return 0;
}

/* get_line: read a line into s, removing all trailing blanks and tabs; return
 * length (including the newline at the end). */
int get_line_until_last_nonblank(char s[], int lim)
{
    int c, i, m;

    m = -1;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        if ((c != '\n') && (c != '\t') && (c != ' '))
            m = i;
    }
    i = m + 1;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}