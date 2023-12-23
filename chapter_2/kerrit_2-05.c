/* Following S. 2.5 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int is_leap(int);

int main(void)
{
    int year = 1000;

    if (is_leap(year))
        printf("The year %i is a leap year!\n", year);
    else
        printf("The year %i is not a leap year!\n", year);
}

int is_leap(int n)
{
    return ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0);
}
