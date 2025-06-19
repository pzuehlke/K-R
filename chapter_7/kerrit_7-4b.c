/* Following S. 7.4 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main()
{
    int day, month, year;
    char monthname[16];
    char line[MAXLINE];

    while (my_getline(line, sizeof(line)) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid: %s\n", line);    // 25 Dec 1998 form
        } else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);    // mm/dd/yy form
        } else {
            printf("invalid: %s\n", line);
        }
    }

    return 0;
}


/* my_getline: read a line into s, return length */
int my_getline(char s[], int lim) {
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}