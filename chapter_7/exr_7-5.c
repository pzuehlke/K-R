/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-05
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP   100    /* max size of operand or operator */
#define MAXVAL  100    /* maximum depth of val stack */

int sp = 0;            /* next free stack position */
double val[MAXVAL];    /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* main: reverse Polish calculator */
int main()
{
    char s[MAXOP];
    double op1, op2, number;
    
    while (scanf("%s", s) == 1) {
        if (sscanf(s, "%lf", &number) == 1) { // it's a number
            push(number);
        } else if (strlen(s) == 1) { // single character
            switch (s[0]) {
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
                    printf("Error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("Error: zero divisor\n");
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case 'p':    // print top element
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'd':    // duplicate top element
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':    /* swap top two elements */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':    /* clear stack */
                sp = 0;
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        } else {
            /* multi-character string - check for math functions */
            if (strcmp(s, "sin") == 0) {
                push(sin(pop()));
            } else if (strcmp(s, "cos") == 0) {
                push(cos(pop()));
            } else if (strcmp(s, "exp") == 0) {
                push(exp(pop()));
            } else if (strcmp(s, "log10") == 0) {
                op2 = pop();
                if (op2 > 0.0)
                    push(log10(op2));
                else
                    printf("error: log of non-positive number\n");
            } else if (strcmp(s, "sqrt") == 0) {
                op2 = pop();
                if (op2 >= 0.0)
                    push(sqrt(op2));
                else
                    printf("error: sqrt of negative number\n");
            } else {
                printf("error: unknown command %s\n", s);
            }
        }
    }
    
    return 0;
}