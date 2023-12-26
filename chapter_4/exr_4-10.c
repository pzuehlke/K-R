/* Solution to Exercise 4-10 of K&R */

#include <stdio.h>
#include <stdlib.h> // for atof

#define MAXLINE 1000 // Maximum input line length

int getline(char line[], int max);
double atof(char s[]);
void push(double);
double pop(void);

int main() {
    int len;            // Current line length
    char line[MAXLINE]; // Current input line
    char type;
    double op2;
    char s[MAXLINE];

    int i = 0;          // Index for the current character in line

    while ((len = getline(line, MAXLINE)) > 0) {
        while (i < len) {
            type = line[i++];
            if (type == ' ' || type == '\t') continue;
            if (type == '+' || type == '-' || type == '*' || type == '/'){
                switch (type) {
                    case '+':
                        push(pop() + pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case '*':
                        push(pop() * pop());
                        break;
                    case '/':
                        op2 = pop();
                        if (op2 != 0.0)
                            push(pop() / op2);
                        else
                            printf("ERROR: zero divisor!\n");
                        break;
                }
            }
            else if (isdigit(type)) {
                // Assuming a single-digit operand for simplicity
                s[0] = type;
                s[1] = '\0';
                push(atof(s));
            } else {
                printf("error: unknown command %s\n", s);
            }
        }
        printf("\t%.8g\n", pop()); // Print result
        i = 0; // Reset index for the next line
    }
    return 0;
}

// ... Other functions like push, pop, atof, getline remain the same ...
