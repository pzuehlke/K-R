/* Following S. 7.6 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files, version 2 */
int main(int argc, char* argv[])
{
    FILE* fp;
    void filecopy(FILE*, FILE*);
    char* prog = argv[0];   /* program name for errors */

    if (argc == 1) {    /* no arguments, copy standard input */
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
