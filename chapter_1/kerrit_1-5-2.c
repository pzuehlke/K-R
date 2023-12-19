/* Following S. 1.5.2 of Kernighan and Ritchie, "The C Programming Language" */
# include <stdio.h>

/* Count characters in input; 1st version */
int main(void)
{
    int c;
    long nc = 0;

    while ((c = getchar()) != EOF)
        ++nc;
    printf("The total number of characters is: %ld\n", nc);

    return 0;
}

/* Count characters in input; 2nd version */
int count_characters(void)
{
    double nc = 0;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("The total number of characters is: %.0f\n", nc);

    return 0;
}


