/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 6-04
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100
#define MAXLINES 1000

struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(void);
struct tnode* addtree(struct tnode* , char*);
int getword(char*, int);
int getch(void);
void ungetch(int);
void collect_words(struct tnode* p, struct tnode** words);
int compare_freq(const void* a, const void* b);
int count_nodes(struct tnode* p);

static int word_count = 0;


int main() {
    struct tnode* root = NULL;
    char word[MAXWORD];

    // Build the binary search tree from the input:
    while (getword(word, MAXWORD) != EOF) {
        if (word[0] == '\0') {  // empty word indicates EOF
            break;
        }
        if (word[0] == '\n') {
            continue;
        }
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    int total_nodes = count_nodes(root);
    struct tnode** words = malloc(total_nodes * sizeof(struct tnode*));
    collect_words(root, words);

    // Sort by decreasing frequency and print:
    qsort(words, word_count, sizeof(struct tnode*), compare_freq);
    for (int i = 0; i < word_count; i++) {
        printf("%4d %s\n", words[i]->count, words[i]->word);
    }
    
    free(words);
    return 0;
}


/* count_nodes: count total nodes in tree */
int count_nodes(struct tnode* p) {
    if (p == NULL)
        return 0;
    return 1 + count_nodes(p->left) + count_nodes(p->right);
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* addtree: add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w)
{
    int cond;
    
    if (p == NULL) {        // create new node for word w
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {  // already in the tree
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}


/* collect_words: collect the words in the binary search tree into an array. */
void collect_words(struct tnode* p, struct tnode** words) {
    if (p != NULL) {
        collect_words(p->left, words);
        words[word_count++] = p;
        collect_words(p->right, words);
    }
}


/* compare_freq: compare frequencies of two words/nodes. */
int compare_freq(const void* a, const void* b) {
    // a and b are pointers to struct node*
    struct tnode* node_a = *(struct tnode**) a; 
    struct tnode* node_b = *(struct tnode**) b;
    return node_b->count - node_a->count;  // Decreasing order
}


/* getword: get next word or character from input. Simplified version that
   deals with general text documents (not necessarily C source code).  */
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    
    // Skip whitespace, but not newlines:
    while (isspace(c = getch()) && c != '\n') { ; }
    
    if (c != EOF)
        *w++ = c;
    
    // Get word characters (letters, digits, underscore):
    if (isalpha(c) || c == '_') {
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    }
    
    *w = '\0';
    return word[0];
}


char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buffer */

/* getch: Get a (possibly pushed back) character */
int getch(void)     
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ERROR in ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}