/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-06
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINE 80

/* compare_files: compare two files for equality, printing the first line where
 * the differ. */
int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Error! Usage: %s file_1 file_2\n", argv[0]);
        return 1;
    }

    // Try to open the files:
    FILE* file_1 = fopen(argv[1], "r");
    if (file_1 == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        return 1;
    }
    FILE* file_2 = fopen(argv[2], "r");
    if (file_2 == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[2]);
        fclose(file_1);
        return 1;
    }
    
    char line_1[MAXLINE], line_2[MAXLINE];
    char *p1, *p2;
    int count = 0;
    
    do {
        p1 = fgets(line_1, MAXLINE, file_1);
        p2 = fgets(line_2, MAXLINE, file_2);
        ++count;
        
        if (p1 != NULL && p2 != NULL && strcmp(line_1, line_2) != 0) {
            printf("Mismatch in line %d:\nFile %s: %s\nFile %s: %s\n",
                   count, argv[1], line_1, argv[2], line_2);
            fclose(file_1);
            fclose(file_2);
            return 0;
        }
    } while (p1 != NULL && p2 != NULL);

    if (p1 != p2) {  // One file ended before the other
        printf("Files differ in length.\n");
    } else {
        printf("Files %s and %s are identical.\n", argv[1], argv[2]);
    }
    
    fclose(file_1);
    fclose(file_2);
    return 0;
}
