/* Following S. 7.4 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>

int get_line(char s[], int lim);

int main()
{
    int day, month, year;
    char month_name[20];
    char* line;

    while (get_line(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, month_name, &year) == 3) {
            printf("valid: %s\n", line);
        } else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);
        } else {
            printf("invalid: %s\n", line);
        }
    }
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
