#include <stdio.h>  // needed for NULL
#include "alloc.h"

#define ALLOCSIZE 10000     /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char* allocp = allocbuf;     /* next free position */

/* alloc: return pointer to n characters */
char* alloc(int n)
{
    if (allocp + n <= allocbuf + ALLOCSIZE) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else {    /* not enough room */
        return NULL;
    }
}

/* afree: free storage pointed to by p */
void afree(char* p)
{
    if (allocbuf <= p && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
