/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-03
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

/* my_strcat: copy t to the end of s (pointer version). */
void my_strcat(char* s, char* t)
{
    while (*s++) { ; }
    --s;
    while ((*s++ = *t++)) { ; } // extra parentheses to prevent gcc warning
}


int main() {
    char buffer[100] = "Hello ";
    char append[] = "World!";
    
    printf("Before: \"%s\"\n", buffer);
    my_strcat(buffer, append);
    printf("After:  \"%s\"\n", buffer);
    
    // Test with empty string:
    char buffer2[50] = "";
    my_strcat(buffer2, "First string");
    printf("Empty test: \"%s\"\n", buffer2);
    
    // Test multiple concatenations:
    char buffer3[100] = "A";
    my_strcat(buffer3, "B");
    my_strcat(buffer3, "C");
    printf("Multiple: \"%s\"\n", buffer3);
    
    return 0;
}
