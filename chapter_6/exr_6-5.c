/* Solution to Exercise 6-5 of K&R */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

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
    // Example usage:
    install("MAX", "100");
    install("MIN", "0");
    install("AVG", "50");

    printf("MAX: %s\n", lookup("MAX")->defn);
    printf("MIN: %s\n", lookup("MIN")->defn);

    undef("MAX");
    printf("MAX after undef: %s\n",
            lookup("MAX") ? lookup("MAX")->defn : "NULL");

    // Free remaining memory:
    for (int i = 0; i < HASHSIZE; i++) {
        struct nlist *np = hashtab[i];
        while (np != NULL) {
            struct nlist *next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            np = next;
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

/* strdup: duplicate string s */
char *strdup(const char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}
