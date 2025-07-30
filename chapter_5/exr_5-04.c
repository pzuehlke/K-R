/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-04
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

size_t my_strlen(char* s);
int my_strcmp(char* s, char* t);

/* strend: returns 1 if string t occurs at the end of string s, 0 otherwise. */
char strend(char* s, char* t)
{
    size_t len_s = my_strlen(s);
    size_t len_t = my_strlen(t);

    if (len_t > len_s) { return 0; }

    return (my_strcmp(s + len_s - len_t, t) == 0) ? 1 : 0;
}


/* strlen: return length of string s */
size_t my_strlen(char* s)
{
    char* p = s;
    while (*p)
        p++;
    return p - s;
}


/* strcmp: return -1 if s < t, 0 if s == t and 1 if s > t. */
int my_strcmp(char* s, char* t)
{
    for (; *s == *t; ++s, ++t) {
        if (*s == '\0') { return 0; }
    }
    return (*s < *t) ? -1 : 1;
}

int main() {
   printf("strend(\"hello world\", \"world\") = %d\n", strend("hello world", "world"));
   printf("strend(\"hello world\", \"hello\") = %d\n", strend("hello world", "hello"));
   printf("strend(\"\", \"\") = %d\n", strend("", ""));
   
   return 0;
}
