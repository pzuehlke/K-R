/* Following S. 6.7 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <stdlib.h>
#define MAXLINES 1000
#define MAXLENGTHS 100


typedef int Length;
typedef char *String;

Length len, maxlen;
Length *lengths[MAXLENGTHS];

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);

typedef struct tnode *Treeptr;

typedef struct tnode {      // the tree node:
    char *word;             // points to the text
    int count;              // number of occurrences
    Treeptr left;           // left child
    Treeptr right;          // right child
} Treenode;

typedef int (*PFI)(char *, char *);


int main(void)
{

    p = (String) malloc(100);
    return 0;
}


Treeptr talloc(void)
{
    return (Treeptr) malloc(sizeof(Treenode));
}
