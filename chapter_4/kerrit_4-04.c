/* Following S. 4.4 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int ms[];   // Declaration
int n;      // Declaration

void f(void) {
    ms[0] = 5;  // Legal because ns has been declared
    printf("Value of n inside f: %i\n", n);
    printf("Value of ms[1]: %i\n", ms[1]);
}

int main() {
    f();        // Prints "Value of n inside f: 10"
    return 0;
}

int n = 10;     // Definition after main
int ms[10];     // Definition with size
