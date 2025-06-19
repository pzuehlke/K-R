/* Following S. 7.7 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>

/* fgets: get at most n chars from iop */
char* fgets(char* s, int n, FILE* iop)
{
    register int c;
    register char* cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) == '\n') { break; }
    }
}