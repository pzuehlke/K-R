/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 3.3
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>  // for strcpy

void expand(char s1[], char s2[]);

/* expand: expand shorthand notation like a-z into equivalent complete list */
void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    char c;

    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i + 1] >= c) {
            ++i;
            while (c < s1[i])
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main(void) {
    char s1[100], s2[100];
    
    printf("Test 1: a-z\n");
    strcpy(s1, "a-z");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "abcdefghijklmnopqrstuvwxyz"
    
    printf("Test 2: a-z0-9\n");
    strcpy(s1, "a-z0-9");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "abcdefghijklmnopqrstuvwxyz0123456789"
    
    printf("Test 3: -a-z-\n");
    strcpy(s1, "-a-z-");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "-abcdefghijklmnopqrstuvwxyz-"
    
    printf("Test 4: a-c-f\n");
    strcpy(s1, "a-c-f");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "abcdef"
    
    printf("Test 5: a-a\n");
    strcpy(s1, "a-a");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "a"
    
    printf("Test 6: z-a\n");
    strcpy(s1, "z-a");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "z-a" (no expansion as z > a)
    
    printf("Test 7: A-Z\n");
    strcpy(s1, "A-Z");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    printf("Test 8: 0-9\n");
    strcpy(s1, "0-9");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "0123456789"
    
    printf("Test 9: a-c,e-g\n");
    strcpy(s1, "a-c,e-g");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "abc,efg"
    
    printf("Test 10: a-b-c\n");
    strcpy(s1, "a-b-c");
    expand(s1, s2);
    printf("Result: %s\n\n", s2);  // Should print "abc"

    return 0;
}