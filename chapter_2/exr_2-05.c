/* Solution to Exercise 2-5 of K&R */
#include <stdio.h>

int locate_char(char s[], char c);
int any(char t[], char s[]);


int main(void)
{
    char t[] = "the standard library returns a pointer to the string.";
    char s[] = "abcde";

    printf("%i\n", locate_char(t, 'a'));    // should return 6
    printf("%i\n", any(t, s));              // should return 2

    return 0;
}


/* locate_char: find the index of the first occurrence of c in s */
int locate_char(char s[], char c)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return i;
    return -1;
}


/* any: return the first location in t where any character of s occurs */
int any(char t[], char s[])
{
    int i, first, current;

    first = -1;
    for (i = 0; s[i] != '\0'; i++) {
        current = locate_char(t, s[i]);
        if ((-1 < current) && (-1 == first || current < first))
            first = current;
    }

    return first;
}
