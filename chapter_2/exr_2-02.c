/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.2
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

#define LIM 1000

int main(void)
{
    int i;
    char c, s[LIM];

    for (i = 0; i < LIM - 1; ++i) {
        c = getchar();
        if (c != '\n') {
            if (c != EOF) {
                s[i] = c;
            }
        }
    }   
    return 0;
}
