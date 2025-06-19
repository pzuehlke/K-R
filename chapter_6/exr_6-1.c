/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 6-01
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100

int getword(char *, int);

int main(void)
{
    char word[MAXWORD];
    int c;
    int count = 0;
    
    printf("Enter some text:\n");
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (word[0] == '\0') {  // empty word indicates EOF
            break;
        }
        printf("Word %d: %s (first char: '%c')\n", ++count, word, c);
    }
    return 0;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    char *w = word;
    void ungetch(int);

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