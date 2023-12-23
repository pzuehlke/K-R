/* Solution to Exercise 2-3 of K&R */
#include <stdio.h>

int htoi(char s[]);


int main(void)
{
    char number[] = "0x1eb";    // in base ten: 491

    printf("The hexadecimal number '%s' represents %i\n",
            number, htoi(number));
    return 0;
}


/* htoi: convert a hexadecimal string representing a positive integer
 * to base 10. */
int htoi(char s[])
{
    int i, digit, d, n = 0;
    enum digits {A = 10, B, C, D, E, F};

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        for (i = 2; (d = s[i]) != '\0'; ++i) {
            if ('0' <= d && d <= '9')
                digit = d - '0';
            else if ('a' <= d && d <= 'f')
                digit = d - 'a' + 10;
            else if ('A' <= d && d <= 'F')
                digit = d - 'A' + 10;
            else {
                printf("ERROR: Invalid hexadecimal number!");
                return -1;
                }
            n = 16 * n + digit;
        }
    }

        return n;
}
