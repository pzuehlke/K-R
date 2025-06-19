/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 2.4
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

void squeeze_char(char s[], int c);
void squeeze(char t[], char s[]);


int main(void)
{
    char t[] = "the standard library returns a pointer to the string.";
    char s[] = "a random string";

    printf("String to be squeezed: \"%s\"\n", t);
    printf("String from which characters to squeeze out are taken: \"%s\"\n", s);
    squeeze(t, s);
    printf("Squeezed string: \"%s\"\n", t);

    return 0;
}


/* squeeze_char: delete all c characters from string t */
void squeeze_char(char t[], int c)
{
    int i, j;

    for (i = 0, j = 0; t[i] != '\0'; ++i) {
        if (t[i] != c) {
            t[j++] = t[i];
        }
    }

    t[j] = '\0';
}


/* squeeze: delete all characters in t that are present in s */
void squeeze(char t[], char s[])
{
    int i;

    for (i = 0; s[i] != 0; ++i)
        squeeze_char(t, s[i]);
}