/* Solution to Exercise 6-3 of K&R */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
char *strdup(const char *);
void tree_to_array(struct tnode *, struct tnode **, int *);
int compare(const void *, const void *);


int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];
    struct tnode *array[MAXWORD];
    int n = 0;

    // Read words from input:
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    // Convert tree to array:
    tree_to_array(root, array, &n);

    // Sort array by frequency of occurrence:
    qsort(array, n, sizeof(struct tnode *), compare);

    // Print words with their counts:
    for (int i = 0; i < n; i++) {
        printf("%4d %s\n", array[i]->count, array[i]->word);
    }

    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

/* tree_to_array: convert the tree to an array */
void tree_to_array(struct tnode *p, struct tnode **array, int *n) {
    if (p != NULL) {
        tree_to_array(p->left, array, n);
        array[(*n)++] = p;
        tree_to_array(p->right, array, n);
    }
}

/* compare: comparison function for qsort */
int compare(const void *a, const void *b) {
    struct tnode *node1 = *(struct tnode **)a;
    struct tnode *node2 = *(struct tnode **)b;
    return node2->count - node1->count;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    // Skip whitespace:
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* talloc: allocate memory for a tree node */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: duplicate a string */
char *strdup(const char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#define BUFSIZE 100

char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;       // Next free position in buf

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
