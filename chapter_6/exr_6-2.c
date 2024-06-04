/* Solution to Exercise 6-2 of K&R */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100    // Maximum length of a word
#define MAXVARS 1000   // Maximum number of variable names
#define PREFIXLEN 6    // Number of characters to compare

struct var {           // Structure to hold variable names (a linked list):
    char *name;
    struct var *next;
};

int getword(char *, int);
struct var *addvar(struct var *, char *);
void sortvars(struct var *);
void printgroups(struct var *);


int main() {
    char word[MAXWORD];
    struct var *variables = NULL;

    // Read variable names from input until EOF:
    while (getword(word, MAXWORD) != EOF) {
        variables = addvar(variables, word);
    }

    // Sort variable names and print them in groups:
    sortvars(variables);
    printgroups(variables);

    return 0;
}

/* getword: read next word from input */
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
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

/* addvar: add a new variable to the linked list */
struct var *addvar(struct var *p, char *name) {
    struct var *newvar = (struct var *)malloc(sizeof(struct var));
    newvar->name = strdup(name);
    newvar->next = p;
    return newvar;
}

/* compare: comparison function for quicksort, comparing first 6 characters */
int compare(const void *a, const void *b) {
    struct var *var1 = *(struct var **)a;
    struct var *var2 = *(struct var **)b;
    return strncmp(var1->name, var2->name, PREFIXLEN);
}

/* sortvars: sort the linked list of variable names using quicksort */
void sortvars(struct var *p) {
    int n = 0;
    struct var *arr[MAXVARS];

    // Convert linked list to array:
    while (p) {
        arr[n++] = p;
        p = p->next;
    }

    // Sort array using quicksort:
    qsort(arr, n, sizeof(struct var *), compare);

    // Convert array back to linked list:
    for (int i = 0; i < n - 1; i++) {
        arr[i]->next = arr[i + 1];
    }
    arr[n - 1]->next = NULL;
}

/* printgroups: print variable names in groups with identical first 6 chars */
void printgroups(struct var *p) {
    struct var *start = p;

    // Iterate through sorted list and print groups:
    while (p) {
        // If next variable has a different prefix or end of list is reached:
        if (!p->next || strncmp(p->name, p->next->name, PREFIXLEN) != 0) {
            struct var *q = start;

            // Print all variables in the current group:
            while (q != p->next) {
                printf("%s ", q->name);
                q = q->next;
            }
            printf("\n");

            // Move to the next group:
            start = p->next;
        }
        p = p->next;
    }
}
