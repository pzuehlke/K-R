#ifndef SYSCALLS_H
#define SYSCALLS_H

// int open(char* name, int flags, int perms);
// int creat(char* name, int perms);
int read(int fd, char* buf, int n);
int write(int fd, char* buf, int n);
int close(int fd);
int unlink(char *name);

#endif
