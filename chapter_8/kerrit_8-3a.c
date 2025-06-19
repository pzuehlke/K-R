/* Following S. 8.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <fcntl.h>

int fd;
int open(char* name, int flags, int perms);
int creat(char* name, int perms);

fd = open(name, flags, perms);
fd = creat(name, perms);