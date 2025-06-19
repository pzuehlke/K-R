/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.17
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define MAXLINE 1000   // maximum input line size

int get_line(char line[], int maxline);

/* Print only lines having > 80 characters. */
int main(void)
{
    int length;    // current line length
    char line[MAXLINE];  // current input line

    while ((length = get_line(line, MAXLINE)) > 0)
        if (length > 80)
            printf("%s\n", line);
    return 0;
}

/* get_line: read a line into s, return length. */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
