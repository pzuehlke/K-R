/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 6-05
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist* next;
    char* name;
    char* defn;
};

static struct nlist* hashtab[HASHSIZE];


/* hash: form hash value for string s */
unsigned hash(char* s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; ++s) {
        hashval = *s + hashval * 31;
    }
    return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */
struct nlist* lookup(char* s)
{
    struct nlist* np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}


/* install: put (name, defn) in hashtab */
struct nlist* install(char* name, char* defn)
{
    struct nlist* np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  // not found
        np = (struct nlist* ) malloc(sizeof(*np));
        if (np == NULL || (np-> name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {    // already there
        free((void*) np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL) { return NULL; }
    return np;
}


/* undef: remove a name and definition from the hash table.
   Return 0 if some entry was removed, 1 if no such entry was found. */
int undef(char* name)
{
    struct nlist* np;
    struct nlist* previous = NULL;
    unsigned hashval = hash(name);
    // If we tried to use `lookup`, then we wouldn't have a pointer to
    // the previous element in the linked list, so we need to essentially
    // repeat the work in the code for `lookup`:
    for (np = hashtab[hashval]; np != NULL; previous = np, np = np->next) {
        if (strcmp(name, np->name) == 0) {
            if (previous == NULL) {     // np is the first element
                hashtab[hashval] = np->next;
            } else {    // np is not the first element in its list
                previous->next = np->next;
            }
            free(np->name);
            free(np->defn);
            free(np);
            return 0;
        }
    }
    return 1;
}

int main()
{
    struct nlist* result;
    
    // Test installation:
    printf("Installing entries...\n");
    install("PI", "3.14159");
    install("E", "2.71828");
    install("GOLDEN", "1.61803");
    
    // Test lookup:
    printf("Looking up entries...\n");
    result = lookup("PI");
    if (result) printf("PI = %s\n", result->defn);
    
    result = lookup("E");
    if (result) printf("E = %s\n", result->defn);
    
    // Test updating existing entry:
    printf("Updating PI...\n");
    install("PI", "3.141592653589793");
    result = lookup("PI");
    if (result) printf("PI = %s\n", result->defn);
    
    // Test undef:
    printf("Removing E...\n");
    if (undef("E") == 0) {
        printf("E removed successfully\n");
    }
    
    result = lookup("E");
    if (!result) printf("E not found (correct)\n");
    
    // Test removing non-existent entry:
    if (undef("NOTFOUND") == 1) {
        printf("NOTFOUND not found (correct)\n");
    }
    
    return 0;
}