/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 4.1
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <string.h>

/* strrindex: return the position of the rightmost occurrence of t in s,
 * or -1 if t doesn't occur within s. */
int strrindex(char s[], char t[])    // s: source; t: target
{
    int i, j;
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    if (len_t == 0)  // t is empty
        return -1;

    // Start searching from the end of s, minus the length of t:
    for (i = len_s - len_t; i >= 0; --i) {
        for (j = 0; t[j] != '\0' && s[i + j] == t[j]; ++j)
            ;
        if (t[j] == '\0')
            return i;  // Found a match
    }
    return -1;
}

int main(void) {
    // Test 1: Basic test with multiple occurrences
    char s1[] = "hello world hello";
    char t1[] = "hello";
    int result1 = strrindex(s1, t1);
    printf("Test 1: strrindex(\"%s\", \"%s\") = %d (expected: 12)\n", 
           s1, t1, result1);
    
    // Test 2: No occurrence
    char s2[] = "hello world";
    char t2[] = "goodbye";
    int result2 = strrindex(s2, t2);
    printf("Test 2: strrindex(\"%s\", \"%s\") = %d (expected: -1)\n", 
           s2, t2, result2);
    
    // Test 3: Target is single character with multiple occurrences
    char s3[] = "abcdeabc";
    char t3[] = "c";
    int result3 = strrindex(s3, t3);
    printf("Test 3: strrindex(\"%s\", \"%s\") = %d (expected: 7)\n", 
           s3, t3, result3);
    
    // Test 4: Target is the same as source
    char s4[] = "test";
    char t4[] = "test";
    int result4 = strrindex(s4, t4);
    printf("Test 4: strrindex(\"%s\", \"%s\") = %d (expected: 0)\n", 
           s4, t4, result4);
    
    // Test 5: Overlapping patterns
    char s5[] = "abababa";
    char t5[] = "aba";
    int result5 = strrindex(s5, t5);
    printf("Test 5: strrindex(\"%s\", \"%s\") = %d (expected: 4)\n", 
           s5, t5, result5);
    
    return 0;
}