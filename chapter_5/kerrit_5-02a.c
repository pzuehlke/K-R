/* Following S. 5.2 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

void false_swap(int x, int y);
void swap(int *x, int *y);

/* false_swap: interchange the values copies of its two arguments */
void false_swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

/* swap: interchange *px and *py */
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int main(void)
{
    int a = 1, b = 2;

    printf("Before the 'false swap': a = %i, b = %i\n", a, b);
    false_swap(a, b);
    printf("After the 'false swap': a = %i, b = %i\n\n", a, b);

    printf("Before the swap: a = %i, b = %i\n", a, b);
    swap(&a, &b);
    printf("After the swap: a = %i, b = %i\n", a, b);
}


