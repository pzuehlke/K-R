/* Following S. 5.10 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char* line, int max);

/* find: print lines that match pattern from 1st argument */
int main(int argc, char* argv[])
{
    char line[MAXLINE];
    long line_number = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++*argv) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (get_line(line, MAXLINE) > 0) {
            ++line_number;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) { printf("%ld:", line_number); }
                printf("%s", line);
                ++found;
            }
        }
    }

    return found;
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
