/* Solution to Exercise 2-2 of K&R */
#include <stdio.h>
#define LIM 1000

int main(void)
{
    int i;
    char c, s[LIM];

    for (i = 0; i < LIM - 1; ++i) {
        c = getchar();
        if c != '\n'
            if c != EOF
                s[i] = c;
    }   
    return 0;
}
