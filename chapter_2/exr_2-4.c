/* Solution to Exercise 2-4 of K&R */
#include <stdio.h>

void squeeze_char(char s[], int c);
void squeeze(char t[], char s[]);


int main(void)
{
    char t[] = "the standard library returns a pointer to the string.";
    char s[] = "a random string";

    printf("%s\n", t);
    squeeze(t, s);
    printf("%s\n", t);

    return 0;
}


/* squeeze_char: delete all c characters from string s */
void squeeze_char(char s[], int c)
{
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}


/* squeeze: delete all characters in t that are present in s */
void squeeze(char t[], char s[])
{
    int i;

    for (i = 0; s[i] != 0; i++)
        squeeze_char(t, s[i]);
}
