/* Following S. 3.5 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>
#include <string.h>


/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++)     /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')     /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}


/* shellsort: sort xs[0], ..., xs[n - 1] into increasing order */
void shellsort(int xs[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && xs[j] > xs[j + gap]; j -= gap) {
                temp = xs[j];
                xs[j] = xs[j + gap];
                xs[j + gap] = temp;
            }
}


/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}


int main() {
    printf("%d\n", atoi("123"));        // prints: 123
    printf("%d\n", atoi("-123"));       // prints: -123
    printf("%d\n", atoi("   123"));     // prints: 123
    printf("%d\n", atoi("   -123"));    // prints: -123
    printf("%d\n", atoi("+123"));       // prints: 123
    printf("%d\n", atoi("123abc"));     // prints: 123
    printf("%d\n", atoi("abc123"));     // prints: 0
     
    // Test the shellsort function
    int xs[] = {9, 5, 2, 7, 3, 8, 1, 6, 4};
    int n = sizeof(xs) / sizeof(xs[0]);

    printf("\nBefore Shell sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n");

    shellsort(xs, n);

    printf("After Shell sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", xs[i]);
    }
    printf("\n\n");

    // Test the reverse function
    char s[] = "Hello, World!";

    printf("Before reverse: %s\n", s);

    reverse(s);

    printf("After reverse: %s\n", s);

    return 0;
}
