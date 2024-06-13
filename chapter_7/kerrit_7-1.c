/* Following S. 7.1 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>

/* main: implements `lower`, which converts input to lowercase */
int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));
    return 0;
}
