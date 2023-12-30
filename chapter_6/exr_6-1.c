/* Solution to Exercise 6-1 of K&R */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100

struct key {
    char *word;
    int count;
};

int getword(char *, int);
int binsearch(char *, struct key*, int);

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"inline", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"restrict", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

#define NKEYS (sizeof keytab / sizeof keytab[0])
char *keyword[NKEYS];
int keycount[NKEYS];

/* count C keywords */
int main(void)
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n",
                    keytab[n].count, keytab[n].word);
    return 0;
}


/* binsearch: find word in tab[0]..tab[n - 1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else return mid;
    }
    return -1;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    char *w = word;
    void ungetch(int);

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {   // a proper word (incl. '_')
        for ( ; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\"') {   // treat a string as a single word, incl. quotes
        for ( ; --lim > 0 && (*w = getch()) != '\"'
                          && (c != '\\'); w++)
            if (*w == '\\')     // beware the sequence \" inside the string
                c = '\\';       // use c to store previous character
            else
                c = *w;
        w++;
    }
    else if (c == '\'') {   // treat a char as a single word, incl. quotes
        *w++ = getch();     // get the char
        *w++ = getch();     // get the right single quote
    }
    else if (c == '/') {    // skip comments, assuming they are well-formed
        c = getch();        // get next character
        if (c == '/') {     // inline comment
            while ((c = getch()) != '\n' && c != EOF)
                ;
        }
        else if (c == '*') {        // multiline comment
            while (getch() != '*')  // consume chars until end of the comment
                getch();            // consume an additional character (/)
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
