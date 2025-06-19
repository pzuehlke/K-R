/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.16
 * Author: pzuehlke
 ****************************************************************************/

# include <stdio.h>

# define MAXLINE 10   // maximum input line size

void copy(char to[], char from[]);
int get_line(char line[], int maxline);
int min(int i, int j);

/* Print longest input line. */
int main(void)
{
    int len;    // current line length
    int max;    // maximum length seen so far
    char line[MAXLINE];  // current input line
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {    // there was a line
        printf("The longest line, up to the %d-th character", MAXLINE - 1);
        printf(" is: \n%s", longest);
        printf("\nIts complete length is %d.\n", max);
    }
    return 0;
}

/* get_line: read a line into s, return length. */
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
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough. */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

/* Returns the smallest of two integers i and j. */
int min(int i, int j)
{
    if (i <= j)
        return i;
    else
        return j;

}