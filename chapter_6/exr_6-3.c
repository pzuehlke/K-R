/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 6-03
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100
#define MAXLINES 1000

struct line_list {
    int line;
    struct line_list* next;
};

struct tnode {
    char* word;
    struct line_list* lines;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(void);
struct line_list* append(struct line_list* list, int line);
struct tnode* addtree(struct tnode* , char*, int line_number);
void treeprint(struct tnode*);
int getword(char*, int);
int getch(void);
void ungetch(int);


int main() {
    struct tnode* root = NULL;
    unsigned line_number = 1;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (word[0] == '\0') {  // empty word indicates EOF
            break;
        }
        if (word[0] == '\n') {
            ++line_number;
            continue;
        }
        if (isalpha(word[0])) {  // valid variable name start
            root = addtree(root, word, line_number);
        }
    }
    treeprint(root);
    return 0;
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* append: append a new node to the end of list of line numbers */
struct line_list* append(struct line_list* list, int line_number) {
    struct line_list* previous = NULL;
    for (struct line_list* current = list; current; current = current->next) {
        if (current->line == line_number) {
            return list;  // line already in the list, don't add
        }
        previous = current;
    }
    
    // We've reached the end, previous is the last element (if any):
    struct line_list* new_element = malloc(sizeof(struct line_list));
    new_element->line = line_number;
    new_element->next = NULL;
    if (previous == NULL) { // list was empty
        return new_element;
    } else {
        previous->next = new_element;
        return list;
    }
}


/* addtree: add a node with w, at or below p */
struct tnode* addtree(struct tnode* p, char* w, int line_number)
{
    if (p == NULL) {        // create new node for word w
        p = talloc();
        p->word = strdup(w);
        p->lines = append(NULL, line_number);
        p->left = p->right = NULL;
    } else if (strcmp(w, p->word) > 0) {
        p->right = addtree(p->right, w, line_number);
    } else if (strcmp(w, p->word) < 0) {
        p->left = addtree(p->left, w, line_number);
    } else {
        p->lines = append(p->lines, line_number);
    }
    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);

        printf("* Word \"%s\" occurs in line(s):\n", p->word);
        struct line_list* current = p->lines;
        do {
            printf("  ");
            printf((current->next != NULL) ? "%d, " : "%d", current->line);
            current = current->next;
        } while (current != NULL);
        printf("\n");

        treeprint(p->right);
    }
}


/* getword: get next word or character from input. Simplified version that
   deals with general text documents (not necessarily C source code).  */
int getword(char *word, int lim)
{
    int c;
    char *w = word;
    
    // Skip whitespace, but not newlines:
    while (isspace(c = getch())) {
        if (c == '\n') {
            word[0] = '\n';  // Signal newline to main
            word[1] = '\0';
            return '\n';
        }
    }
    
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