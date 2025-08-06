/* Following S. 5.12 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };


void dcl();
void dir_dcl();

int getch();
void ungetch(int);
int get_token();
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

/* main: convert declaration to words */
int main()
{
    while (get_token() != EOF) {    /* 1st token on line */
        strcpy(datatype, token);    /* is the datatype */
        out[0] = '\0';
        dcl();  /* parse rest of line */
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* get_token: return next token */
int get_token()
{
    int c, getch();
    void untgetch();
    char* p = token;

    while ((c = getch()) == ' ' || c == '\t') { ; }
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; ) { ; }
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); ) { *p++ = c; }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

/* dcl: parse a declarator */
void dcl()
{
    int number_of_stars;

    for (number_of_stars = 0; get_token() == '*'; ) { /* count *'s */
        number_of_stars++;
    }
    dir_dcl();
    while (number_of_stars-- > 0) {
        strcat(out, " pointer to");
    }

}

/* dir_dcl: parse a direct declarator */
void dir_dcl()
{
    int type;

    if (tokentype == '(') {     /* ( dcl ) */
        dcl();
        if (tokentype != ')') { printf("error: missing ')'\n"); }
    } else if (tokentype == NAME) { /* variable name */
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\n");
    }
    while ((type = get_token()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
        strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int buf = EOF;      /* buffer for ungetch */

/* getch: Get a (possibly pushed back) character */
int getch()     
{
    if (buf == EOF) {
        getchar();
    } else {
        int c = buf;
        buf = EOF;
        return c;
    }
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (buf != EOF)
        printf("ERROR in ungetch: Too many characters!\n");
    else
        buf = c;
    return;
}
