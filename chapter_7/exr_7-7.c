/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-07
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

long find_pattern(char* pattern, FILE* ifp, char* file_name,
                  int except, int number)
{
    long found_in_file = 0;
    char line[MAXLINE];
    long line_number = 0;
    while (fgets(line, MAXLINE, ifp)) {
        ++line_number;
        if ((strstr(line, pattern) != NULL) != except) {
            if (number) { printf("line %ld ", line_number); }
            printf("in file `%s`: ", file_name);
            printf("%s", line);
            ++found_in_file;
        }
    }
    return found_in_file;
}

/* find: print lines that match pattern from 1st argument */
int main(int argc, char* argv[])
{
    char* prog_name = argv[0];
    char line[MAXLINE];
    long line_number = 0;
    int c, except = 0, number = 0;
    long found = 0;

    // parse options (-x (except) and -n (display line number))
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
                    fprintf(stderr, "%s: illegal option %c\n", prog_name, c);
                    exit(1);
                    break;
            }
        }
    }

    if (argc < 1) {     // no pattern
        fprintf(stderr, "Error: Usage: `find -x -n pattern`\n");
        exit(1);
    }

    char* pattern = *argv++;
    --argc;

    if (argc < 1) {     // no file names, find patterns in stdin
        found += find_pattern(pattern, stdin, "std. input", except, number);
    } else {    // find patterns in list of files
        while (--argc > 0) {
            char* file_name = *argv++;
            FILE* ifp = fopen(file_name, "r");
            if (!ifp) {
                fprintf(stderr, "Error: could not open file `%s`", file_name);
                fclose(ifp);
                exit(2);
            } else {
                found += find_pattern(pattern, ifp, file_name, except, number); 
                fclose(ifp);
            }
        }
    }
    printf("\nFound %ld occurrences in total.\n", found);
    return 0;
}
