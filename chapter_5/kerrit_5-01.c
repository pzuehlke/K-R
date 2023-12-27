/* Following S. 5.1 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int main(void) {
    int x = 1, y = 2, z[10] = {5, 6, 7};
    int *ip;            /* ip is a pointer to int */

    ip = &x;            /* ip now points to x */
    y = *ip;            /* y is now 1 */
    *ip = 0;            /* x is now 0 */
    ip = &z[0];         /* ip now points to z[0] */
    printf("%d\t%d\t%d\n", x, y, *ip);
    printf("%p\n", ip);
    printf("%p\n", &ip);
}


