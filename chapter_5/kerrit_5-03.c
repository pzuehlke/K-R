/* Following S. 5.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <string.h>

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int *pa, x, y;

int strlength(char *s);

int main(void)
{
    char s[] = "Hello, world!";
    char t[] = "This is a simple test.";

    pa = &a[0];
    x = *pa;
    y = *(pa + 1);
    printf("x = %i\ty = %i\n", x, y);
    printf("%i\t%li\n", strlength(s), strlen(s));
    printf("%i\t%li\n", strlength(t), strlen(t));

    return 0;
}

int strlength(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
