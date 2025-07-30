/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-13
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINES 100

int get_line(char* line, int max);
void write_lines(char* line_array[], int newest, int n);

/* tail: print the last n lines of its input. By default, n = 10. */
int main(int argc, char* argv[])
{
    int n = 10;
    while (--argc > 0) {
        if (**++argv == '-') {
            n = atoi(++*argv);
        }
    }

    char line[MAX_LINE_LENGTH];
    char line_buffer[n * MAX_LINE_LENGTH];
    char* line_array[n];

    for (int i = 0; i < n; ++i) {
        line_array[i] = line_buffer + i * MAX_LINE_LENGTH;
        *line_array[i] = '\0';
    }

    int newest = -1;
    while (get_line(line, MAX_LINE_LENGTH) > 0) {
        newest = (newest + 1) % n;
        strcpy(line_array[newest], line);
    }
    write_lines(line_array, newest, n);
}

/* write_lines: write the lines, from most to least recently seen. */
void write_lines(char* line_array[], int newest, int n)
{
    int count = 0;
    int i = newest;

    printf("\nHere are the most recent lines:\n");
    while (count < n && *line_array[i] != '\0') {
        printf("%s", line_array[i]);
        ++count;
        i = (i - 1 + n) % n;    // decrease by 1, wrap around
    }
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
