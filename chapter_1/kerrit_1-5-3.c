/* Following S. 1.5.3 of Kernighan and Ritchie, "The C Programming Language" */
# include <stdio.h>

/* Coint lines in input */

int main(void)
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);

    return 0;
}
