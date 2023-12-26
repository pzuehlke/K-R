/* Solution to Exercise 4-6 of K&R */
#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <ctype.h>
#include <math.h>

#define MAXVAL 100      // maximum depth of val stack
#define MAXOP 100       // max size of operand or operator
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
    int type, var = 0;
    double op1, op2;
    char s[MAXOP];

    for (int i = 0; i < 26; i++)
        variables[i] = 0.0;

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
            case 'p':   // print top element without popping
                last = peek();
                printf("Top of stack: %.8g\n", last);
                break;
            case 'd':   // duplicate top element
                duplicate();
                break;
            case 'w':   // swap top two elements
                swap();
                break;
            case 'l':   // clear stack
                clear();
                break;
            case 's':   // sine
                push(sin(pop()));
                break;
            case 'c':   // cosine
                push(cos(pop()));
                break;
            case 'e':   // exp
                push(exp(pop()));
                break;
            case '^':
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


int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c!= '-' && !isupper(c))
        return c;       /* not a number */
    if (isupper(c))
        return VAR;
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()))
            s[++i] = c;
        else {
            ungetch(c);
            return '-';
        }
    }
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


int sp = 0;             // next free stack position
double stack[MAXVAL];   // value stack

/* push: Push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        stack[sp++] = f;
    else
        printf("ERROR: Stack full, can't push %g\n", f);
}

/* pop: Pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("ERROR: Stack empty!\n");
        return 0.0;
    }   
}


/* peek: Return top element of stack without popping it */
double peek(void)
{
    if (sp > 0)
        return stack[sp - 1];
    else {
        printf("ERROR: Can't peek, stack empty!\n");
        return 0.0;
    }
}

/* duplicate: Duplicate the top element of the stack */
void duplicate(void)
{
    if (sp > 0)
        push(peek());
    else
        printf("ERROR: Stack empty, no element to duplicate!");
    return;
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
