/* Following S. 4.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

#define MAXVAL 100      // maximum depth of val stack

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
