/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 6-02
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100
#define SIMILAR_CHARS 6  // Compare first 6 characters for similarity

struct varlist{
    char* varname;
    struct varlist* next;
};

struct tnode {
    char* word;             // representative word for this group
    struct varlist* vars;   // list of similar variables
    int count;              // number of variables in this group
    struct tnode* left;     // left child
    struct tnode* right;    // right child
};

struct varlist* append(struct varlist* list, char* new_variable);
int check_similarity(struct varlist* vars, char* w);
struct tnode* addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode* talloc(void);
int getword(char *, int);
int getch(void);
void ungetch(int);


/* print variable names grouped by similarity */
int main(void)
{
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (word[0] == '\0') {  // empty word indicates EOF
            break;
        }
        if (isalpha(word[0]) || word[0] == '_') {  // valid variable name start
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}


/* append: add new variable to varlist */
struct varlist* append(struct varlist* list, char* new_variable) {
    struct varlist* new_element = malloc(sizeof(struct varlist));
    new_element->varname = strdup(new_variable);
    new_element->next = NULL;
    
    if (list == NULL) {
        return new_element;
    }
    
    struct varlist* current = list;
    while (current->next) { 
        current = current->next; 
    }
    current->next = new_element;
    return list;  // return head of list
}


/* check_similarity: check if w is similar to any variable in the group */
int check_similarity(struct varlist* vars, char* w) {
    struct varlist* current = vars;
    
    // First check for exact matches in the entire list:
    while (current != NULL) {
        if (strcmp(w, current->varname) == 0) {
            return 2;  // exact match, don't add duplicate
        }
        current = current->next;
    }
    
    // If no exact match, check similarity against just the first element
    // (since all elements in the list are similar to each other):
    if (strncmp(w, vars->varname, SIMILAR_CHARS) == 0) {
        return 1;  // similar, should be added to group
    }
    
    return 0;  // not similar to any in this group
}


/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond, similarity;

    if (p == NULL) {        // create new group
        p = talloc();
        p->word = strdup(w);
        p->vars = append(NULL, w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((similarity = check_similarity(p->vars, w)) > 0) {
        if (similarity == 1) {  // similar but not exact, add to group
            p->vars = append(p->vars, w);
            p->count++;
        }
        // if similarity == 2 (exact match), don't add duplicate
    } else if ((cond = strcmp(w, p->word)) < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        if (p->count > 1) {  // only print groups with multiple variables
            printf("* Group (first %d chars: \"", SIMILAR_CHARS);
            for (int i = 0; i < SIMILAR_CHARS && p->word[i] != '\0'; i++) {
                printf("%c", p->word[i]);
            }
            printf("\"): %d variables\n", p->count);
            
            struct varlist* current = p->vars;
            while (current != NULL) {
                printf("    -%s\n", current->varname);
                current = current->next;
            }
            printf("\n");
        }
        treeprint(p->right);
    }
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))    // skip whitespace
        ;

    // Skip inline or multi-line comments:
    if (c == '/') {    // skip comments, assuming they are well-formed
        c = getch();        // get next character
        if (c == '/') {     // inline comment
            while ((c = getch()) != '\n' && c != EOF)
                ;
        } else if (c == '*') {        // multiline comment
            int prev = getch();
            while ((c = getch()) != EOF) {
                if (prev == '*' && c == '/') 
                    break;
                prev = c;
            }
        }
        return getword(word, lim);
    }

    if (c != EOF)   // if not EOF, store the initial character in w
        *w++ = c;

    // Case 1: a proper word (incl. '_'), possibly a preprocessor directive (#):
    if (isalpha(c) || c == '_' || c == '#') {
        for ( ; --lim > 0; w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    }
    
    // Case 2: a string literal:
    else if (c == '\"') {   // treat a string as a single word, incl. quotes
        // We will use c to store previous the character
        for ( ; --lim > 0 && ((*w = getch()) != '\"' || (c == '\\')); w++) {
            if (*w == '\\')     // beware the sequence \" inside the string
                c = '\\';       // use c to store previous character
            else
                c = *w;
        }
        w++;
    }
    
    // Case 3: a single character:
    else if (c == '\'') {   // treat a char as a single word, incl. quotes
        c = *w++ = getch();     // get the char
        if (c == '\\') { *w++ = getch(); }  // it's an escape character
        *w++ = getch();     // get the right single quote
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