/* Solution to exercise 1-18 of K&R */
# include <stdio.h>
# define MAXLINE 1000   /* maximum input line size */

int get_line(char line[], int maxline);
void slice_str(char slice[], char original[], int min, int max);

/* Removes trailing blanks and tabs from each line of input. */
int main(void)
{
    char line[MAXLINE];
    char slice[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        slice_str(slice, line, 0, len);
        printf("%s\n", slice);
    }
    return 0;
}

/* get_line: read a line into s, return length. */
int get_line(char s[], int lim)
{
    int c, i, m;

    m = -1;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        if ((c != '\n') && (c != '\t') && (c != ' '))
            m = i;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return m + 1;
}

/* slice_str: takes a slice of 'original'; starts at min, ends at max - 1 */
void slice_str(char slice[], char original[], int min, int max)
{
    int i;
    
    for (i = min; i < max; ++i)
        slice[i - min] = original[i];
    slice[i] = '\0';
}
