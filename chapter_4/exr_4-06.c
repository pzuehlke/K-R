/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4.6
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>      /* for isdigit() */
#include <math.h>       /* for fmod(), sin(), cos(), exp(), log(), pow()  */

#define MAXOP 100       // max size of operand or operator
#define MAXVAL 100      // maximum depth of val stack
#define BUFSIZE 100     // size of buffer
#define NUMBER '0'      // signal that a number was found
#define VAR '1'         // signal that a variable was found
#define LAST '2'        // signal that the 'last seen' variable was found

int getop(char []);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

double variables[26];   // array to store the values of each variable A-Z
double last = 0.0;      // value of the variable LAST

/* Calculator using reverse Polish notation */
int main(void)
{
    int type;
    int var = 0;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:   // access a variable (for storage or retrieval)
                var = s[0] - 'A';
                break;
            case '=':   // store top value in a variable
                variables[var] = peek();
                break;
            case '?':   // retrieve the value of a variable, push it to stack
                push(variables[var]);
                break;
            case LAST:  // push the variable stored in LAST
                push(last);
                break;
            case 'p':   // Print top element without popping
                last = peek();
                printf("Top of stack: %.8g\n", last);
                break;
            case 'd':   // Duplicate top element
                duplicate();
                break;
            case 's':   // Swap top two elements
                swap();
                break;
            case 'c':   // Clear stack
                clear();
                break;
            case 'i':   // cosine
                push(sin(pop()));
                break;
            case 'o':   // cosine
                push(cos(pop()));
                break;
            case 'e':   // exponential function
                push(exp(pop()));
                break;
            case 'l':   // natural logarithm (ln)
                push(log(pop()));
                break;
            case '^':   // power
                op2 = pop();
                push(pow(pop(),op2));
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("ERROR: Zero divisor in modulus!\n");
                break;
            case '\n':
                last = pop();
                printf("\t%.8g\n", last);
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

/* push: push x onto value stack */
void push(double x)
{
    if (sp < MAXVAL) {
        stack[sp++] = x;
    } else {
        printf("ERROR: Stack full, can't push %g\n", x);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        return stack[--sp];
    } else {
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
    if (!isdigit(c) && c != '.' && c != '-' && c != '_') {
        return c;       /* not a number */
    }
    if (c == '_')
        return LAST;
    if (isupper(c))
        return VAR;
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch())) {  // negative number
            s[++i] = c;
        } else {    // not a negative number
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) {   /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {     /* collect fractional part */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


/* peek: Return top element of stack without popping it */
double peek(void)
{
    if (sp > 0) {
        return stack[sp - 1];
    } else {
        printf("ERROR: Can't peek, stack empty!\n");
        return 0.0;
    }
}

/* duplicate: Duplicate the top element of the stack */
void duplicate(void)
{
    if (sp > 0) {
        push(peek());
    } else {
        printf("ERROR: Stack empty, no element to duplicate!");
    }
}

/* swap: Swap the top two elements of the stack */
void swap(void)
{
    double e1, e2;

    if (sp > 1) {
        e1 = pop();
        e2 = pop();
        push(e1);
        push(e2);
    }
    else
        printf("ERROR: Fewer than two elements in stack!\n");
}

/* clear: Clear the stack */
void clear(void)
{
    sp = 0;
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