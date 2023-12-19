/* Following S. 1.6 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

/* Counts digits, whitespace, other characters. */
int main(void) {
    int c, i, nwhite = 0, nother = 0;
    int ndigit[10] = {0};

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits = ");
    for (i = 0; i <= 9; ++i)
        printf(" %d", ndigit[i]);
    printf(", whitespace = %d, other = %d\n", nwhite, nother);
    return 0;
}
