/* Following S. 5.4 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 1000  /* size of variable space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

char *alloc(int n);  // Function declaration
void afree(char *p); // Function declaration

int main() {
    char *p1, *p2;

    // Test alloc function
    p1 = alloc(10);
    if (p1 != NULL) {
        strcpy(p1, "Hello");
        printf("p1 points to: %s\n", p1);
    } else {
        printf("Allocation for p1 failed.\n");
    }

    p2 = alloc(20);
    if (p2 != NULL) {
        strcpy(p2, "World");
        printf("p2 points to: %s\n", p2);
    } else {
        printf("Allocation for p2 failed.\n");
    }

    // Test afree function
    afree(p2);
    afree(p1);

    // Check if memory is freed by attempting to allocate again
    p1 = alloc(30);
    if (p1 != NULL) {
        strcpy(p1, "Memory Freed");
        printf("Memory freed successfully, p1 now points to: %s\n", p1);
    } else {
        printf("Memory not freed.\n");
    }

    return 0;
}

char *alloc(int n)  /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else {    /* not enough room */
        return NULL;
    }
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
