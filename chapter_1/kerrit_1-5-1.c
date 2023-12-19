/* Following S. 1.5.1 of Kernighan and Ritchie, "The C Programming Language" */
# include <stdio.h>

/* Copy input to output */
int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}
