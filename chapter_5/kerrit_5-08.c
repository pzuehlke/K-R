/* Following S. 5.8 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

char *month_name(int n);


int main(void) {
    // Testing month_name function
    printf("Testing month_name function:\n");
    for (int i = -1; i <= 13; i++) {
        printf("Month %2i: %s\n", i, month_name(i));
    }
    return 0;
}


/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"};

    return (n < 1 || n > 12) ? name[0] : name[n];
}
