/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-09
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define isupper_1(c) ('A' <= (c) && (c) <= 'Z')

int isupper_2(int c) {
    return 'A' <= c && c <= 'Z';
}

int main()
{
    printf("Type in some characters and I will tell you whether they are in"
           "uppercase:\n");
    int c;
    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            printf("macro: %s, function: %s\n", 
                   (isupper_1(c) ? "yes" : "no"), 
                   (isupper_2(c) ? "yes" : "no"));
            printf("\nType the next character:\n");
        }
    }
    return 0;
}
