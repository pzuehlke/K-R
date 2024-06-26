/* Following S. 6.5 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {              // the tree node:
    char *word;             // points to the text
    int count;              // number of occurrences
    struct tnode *left;     // left child
    struct tnode *right;    // right child
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *mystrdup(char *);


/* print repeated variable names */
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}


/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {        // a new word has arrived
        p = talloc();       // make a new node
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;         // repeated word
    else if (cond < 0)      // less than, into left subtree
        p->left = addtree(p->left, w);
    else                    // greater than, into right subtree
        p->right = addtree(p->right, w);
    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);}
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* mystrdup: make a duplicate of s */
char *mystrdup(char *s) {
    char *p;

    p = (char *) malloc(strlen(s) + 1);     // +1 for \0
    if (p != NULL)
        strcpy(p, s);
    return p;
}
