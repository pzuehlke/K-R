/* Solution to Exercise 3-6 of K&R */
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);


int main(void) {
    char buffer[20];
    itoa(1234, buffer, 8);
    printf("%s\n", buffer);  // Outputs: "    1234"

    itoa(-42, buffer, 6);
    printf("%s\n", buffer);  // Outputs: "   -42"

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i <= w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
    return;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
