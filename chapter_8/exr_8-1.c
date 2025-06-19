/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 8-01
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>    // for O_RDONLY
#include <unistd.h>   // for read, write, close
#include <stdlib.h>   // for exit

int filecopy(int infile_d, int outfile_d);
void error(char* fmt, ...);


/* cat: concatenate files */
int main(int argc, char* argv[])
{
    int fd;
    char* prog = argv[0];
    if (argc == 1) {
        filecopy(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0) == -1)) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }

    return 0;
}


/* filecopy: copy file infile to file outfile */
int filecopy(int infile_d, int outfile_d)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(infile_d, buf, BUFSIZ)) > 0) {
        if (write(outfile_d, buf, n) != n) {
            error("cp: write error on file with descriptor %d", outfile_d);
        }
    }
    return 0;

}

/* error: print an error message and die */
void error(char* fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}