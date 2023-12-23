/* Following S. 2.8 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

void squeeze(char s[], int c);
void str_cat(char s[], char t[]);


int main(void)
{
    char s[] = "the standard library returns a pointer to the string.";
    int c = 'r';

    printf("%s\n", s);
    squeeze(s, c);
    printf("%s\n", s);

    return 0;
}


/* squeeze: delete all c characters from string s */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}


void str_cat(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
