/* Solution to Exercise 1-6 of K&R */
# include <stdio.h>

int main(void)
{
    int c, d;

    c = 'a';
    d = EOF;
    printf("%d\n", c != EOF);
    printf("%d\n", d != EOF);

    return 0;
}
