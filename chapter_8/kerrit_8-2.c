/* Following S. 8.2 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"

/* main: copy input to output */
int main()
{
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0) { 
        write(1, buf, n);
    }
    return 0;
}

/* getchar: unbuffered single character input */
int my_getchar()
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/* getchar: simple buffered version */
int my_getchar_2()
{
    static char buf[BUFSIZ];
    static char* bufp = buf;
    static int n = 0;

    if (n == 0) {   // buffer is empty
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
