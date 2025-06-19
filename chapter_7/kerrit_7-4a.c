/* Following S. 7.4 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>

int main()
{
    double sum, v;
    
    sum = 0;
    while (scanf("%lf", &v) == 1) {
        printf("\t%.2f\n", sum += v);
    }
    return 0;
}