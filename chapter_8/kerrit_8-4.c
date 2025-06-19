/* Following S. 8.4 of Kernighan and Ritchie, "The C Programming Language" */

long lseek(int fd, long offset, int origin);

lseek(fd, 0L, 2);   // append
lseek(fd, 0L, 0);   // rewind

#include "syscalls.h"

/* get: read n bytes from position pos */
int get(int fd, long pos, char* buf, int n) {
    if (lseek(fd, pos, 0) >= 0) {
        return read(fd, buf, n);
    } else {
        return -1;
    }
}