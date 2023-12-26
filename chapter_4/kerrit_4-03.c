/* Following S. 4.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <stdlib.h>      // for atof()
#include <ctype.h>
#include <math.h>

#define MAXVAL 100       // maximum depth of val stack
#define MAXOP 100        // max size of operand or operator
#define BUFSIZE 100
#define NUMBER '0'       // signal that a number was found

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);

/* Calculator using reverse Polish notation */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("ERROR: Zero divisor!\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("ERROR: Unknown command!%s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0;             // next free stack position
double stack[MAXVAL];   // value stack

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        stack[sp++] = f;
    else
        printf("ERROR: Stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("ERROR: Stack empty!\n");
        return 0.0;
    }   
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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
