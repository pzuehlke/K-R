/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-05
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* my_strncpy: copy at most n characters of t to s (pointer version) */
char* my_strncpy(char* s, char* t, size_t n)
{
    char* start = s;
    while (n > 0 && (*s++ = *t++)) { --n; }
    // According to the description, we must pad with n - len(t) copies of '\0'
    for (; n > 0; --n) { *s++ = '\0'; }
    return start;
}

/* my_strncat: concatenate at most n chars of t to s, terminate with '\0' */
char* my_strncat(char* s, char* t, size_t n)
{
    char* start = s;
    s += strlen(s);
    while (n > 0 && (*s = *t)) {
        ++s; ++t; --n;
    }
    *s = '\0';
    return start;
}

/* my_strncmp: compare at most n characters of string s to string t;
   return < 0 if s < t, 0 if s == t, or > 0 if s > t */
int my_strncmp(char* s, char* t, size_t n)
{
    while (n > 0 && *s == *t) {
        if (*s == '\0') { return 0; }
        ++s; ++t; --n;
    }
    if (n == 0) { return 0; }
    return (*s < *t) ? -1 : 1;
}
