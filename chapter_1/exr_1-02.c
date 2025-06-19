/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 1.1
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int main() {
    printf("Hello, world!\a\n");
    printf("Hello,\bworld!\n");
    printf("Hello,\tworld!\n");
    printf("Hello, 'world!'\n");
    printf("Hello, \vworld!\n");
    printf("Hello, \\world!\\\n");
    printf("Hello, \"world!\"\n");
    printf("Hello, world!\123\n");
}