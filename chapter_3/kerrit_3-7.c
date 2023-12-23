/* Following S. 3.7 of Kernighan and Ritchie, "The C Programming Language" */
/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\n' && s[n] != '\t')
            break;
    s[n + 1] = '\0';
    return n;
}
