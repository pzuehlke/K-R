/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-08
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define LINES_PER_PAGE 80

void filecopy_with_pages(FILE* infile, FILE* outfile, char* filename);

int main(int argc, char* argv[])
{
    if (argc == 1) {
        filecopy_with_pages(stdin, stdout, "stdin");
        return 0;
    }
    
    FILE* fp;
    int exit_status = 0;

    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "Error! Can't open %s\n", *argv);
            exit_status = 1;
        } else {
            filecopy_with_pages(fp, stdout, *argv);
            fclose(fp);
        }
    }

    return exit_status;
}

/* filecopy: copy file infile to file outfile */
void filecopy_with_pages(FILE* infile, FILE* outfile, char* filename)
{
    char line[MAXLINE];
    int page_num = 1;
    int line_count = 0;
    int first_page = 1;     // first page of the file?

    while (fgets(line, MAXLINE, infile) != NULL) {
        if (line_count == 0) {  // print the header
            if (!first_page) {
                fprintf(outfile, "\f");     // form feed to advance to new page
            }
            fprintf(outfile, "\n\n--------------------------------------");
            fprintf(outfile, "\n%s - Page %d\n", filename, page_num);
            fprintf(outfile, "--------------------------------------\n\n");
            line_count = 6;
            first_page = 0;
        }

        // print the line:
        fputs(line, outfile);
        ++line_count;

        // check if page is full:
        if (line_count >= LINES_PER_PAGE) {
            line_count = 0;
            ++page_num;
        }

        // end with a form feed
    }

    if (line_count >= 4 || page_num > 1) {
        fprintf(outfile, "\f");
    }
}