/* Solution to Exercise 6-6 of K&R */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {               // Table entry:
    struct nlist *next;      // next entry in chain
    char *name;              // defined name
    char *defn;              // replacement text
};

static struct nlist *hashtab[HASHSIZE]; // pointer table

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
void process_define(char *);
void process_undef(char *);
void replace_macros(char *);


/* process_define: process #define directive */
void process_define(char *line) {
    char name[MAXWORD], defn[MAXWORD];

    if (sscanf(line, "#define %s %s", name, defn) == 2) {
        install(name, defn);
    }
}

/* process_undef: process #undef directive */
void process_undef(char *line) {
    char name[MAXWORD];

    if (sscanf(line, "#undef %s", name) == 1) {
        undef(name);
    }
}

/* replace_macros: replace macros in the line */
void replace_macros(char *line) {
    char word[MAXWORD];
    char *p = line, *q, *start;
    struct nlist *np;

    while (*p != '\0') {
        if (isalnum(*p) || *p == '_') {
            start = p;
            while (isalnum(*p) || *p == '_') {
                p++;
            }
            strncpy(word, start, p - start);
            word[p - start] = '\0';
            if ((np = lookup(word)) != NULL) {
                q = np->defn;
                printf("%s", q);
            } else {
                printf("%.*s", p - start, start);
            }
        } else {
            putchar(*p);
            p++;
        }
    }
}

/* undef: remove name from hashtab */
void undef(char *name) {
    struct nlist *np, *prev;
    unsigned hashval = hash(name);

    np = hashtab[hashval];
    if (np == NULL) {
        return;  // name not found
    }

    if (strcmp(name, np->name) == 0) {  // first in the list
        hashtab[hashval] = np->next;
    } else {
        for (prev = np, np = np->next; np != NULL;
             prev = np, np = np->next) {
            if (strcmp(name, np->name) == 0) {
                prev->next = np->next;
                break;
            }
        }
    }

    if (np != NULL) {
        free(np->name);
        free(np->defn);
        free(np);
    }
}

int main() {
    char line[MAXWORD];

    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "#define", 7) == 0) {
            process_define(line);
        } else if (strncmp(line, "#undef", 6) == 0) {
            process_undef(line);
        } else {
            replace_macros(line);
            printf("%s", line);
        }
    }

    return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;  // found
        }
    }
    return NULL;  // not found
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  // not found
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {  // already there
        free(np->defn);  // free previous defn
    }
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}
