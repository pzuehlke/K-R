/* Solution to Exercise 6-3 of K&R */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXLINES 1000

struct lnode {              // Structure to hold a list of line numbers
    int line;
    struct lnode *next;
};

struct tnode {              // The tree node:
    char *word;             // Points to the text
    struct lnode *lines;    // Points to the list of line numbers
    struct tnode *left;     // Left child
    struct tnode *right;    // Right child
};

struct tnode *addtree(struct tnode *, char *, int);
struct lnode *addline(struct lnode *, int);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
struct lnode *lalloc(void);
char *strdup(const char *);


int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];
    int line = 1;
    int c;

    // Read words from input:
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word, line);
        }
        if (c == '\n') {
            line++;
        }
    }

    // Print the words and their line numbers:
    treeprint(root);

    return 0;
}

/* addtree: add a word to the tree and record the line number */
struct tnode *addtree(struct tnode *p, char *w, int line) {
    int cond;

    if (p == NULL) {
        // New word:
        p = talloc();
        p->word = strdup(w);
        p->lines = addline(NULL, line);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        // Repeated word:
        p->lines = addline(p->lines, line);
    } else if (cond < 0) {
        // Less than, into left subtree:
        p->left = addtree(p->left, w, line);
    } else {
        // Greater than, into right subtree:
        p->right = addtree(p->right, w, line);
    }
    return p;
}

/* addline: add a line number to the list of lines */
struct lnode *addline(struct lnode *p, int line) {
    if (p == NULL) {
        p = lalloc();
        p->line = line;
        p->next = NULL;
    } else if (p->line != line) {
        p->next = addline(p->next, line);
    }
    return p;
}

/* treeprint: print the tree of words and their line numbers */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%s: ", p->word);
        struct lnode *ln = p->lines;
        while (ln != NULL) {
            printf("%d ", ln->line);
            ln = ln->next;
        }
        printf("\n");
        treeprint(p->right);
    }
}

/* getword: read the next word from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    // Skip whitespace characters:
    while (isspace(c = getchar()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getchar()) && *w != '_') {
            ungetc(*w, stdin);
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

/* lalloc: allocate memory for a line node */
struct lnode *lalloc(void) {
    return (struct lnode *) malloc(sizeof(struct lnode));
}

/* strdup: duplicate a string */
char *strdup(const char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
