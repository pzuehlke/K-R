/* Solution to Exercise 4-1 of K&R */
#include <stdio.h>
#define MAXLINE 1000        // maximum input line length

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";   // pattern to search for

/* find all lines matching pattern */
int main(void)
{
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
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

/* strindex: return index of t in s, -1 if none */
/* WARNING: Differs from the version in the book (it is simpler). */
int strindex(char s[], char t[])    // s: source; t: target
{
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; t[j] != '\0' && s[i + j] == t[j]; j++)
            ;
        if (j > 0 && t[j] == '\0')
            return i;
    }
    return -1;
}
