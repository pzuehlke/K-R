/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-10
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

int pop();
void push(int x);
int stack[STACK_SIZE];
int stack_index = 0;

int main(int argc, char* argv[])
{
    while (--argc > 0) {
        char* word = *++argv;
        if (strlen(word) == 1 && !isdigit(word[0])) {  // it's an operator
            int y = pop();
            int x = pop();
            switch (word[0]) {
                case '+':
                    push(x + y);
                    break;
                case '-':
                    push(x - y);
                    break;
                case '*':
                    push(x * y);
                    break;
                case '/':
                    if (y == 0) {
                        printf("ERROR: division by zero!");
                        return 1;
                    }
                    push(x / y);
                    break;
                default:
                    printf("ERROR: invalid operation %c", word[0]);
                    return 1;

            }
        } else {    // it's a number
            push(atoi(word));
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}

int pop()
{
    if (stack_index <= 0) {
        printf("ERROR: stack underflow!");
        exit(1);
    }
    return stack[--stack_index];
}

void push(int x)
{
    if (STACK_SIZE <= stack_index) {
        printf("ERROR: stack overflow!");
    }
    stack[stack_index++] = x;
}
