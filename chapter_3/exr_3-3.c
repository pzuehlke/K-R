/* Solution to Exercise 3-3 of K&R */
#include <stdio.h>

void expand(char s1[], char s2[]);

/* expand: expand shorthand notation like a-z into equivalent complete list */
void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    char c;

    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i + 1] >= c) {
            i++;
            while (c <= s1[i])
                s2[j++] = c++;
        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
}

int main(void) {
    char s1[] = "a-z";
    char s2[27];  // Allocate space for all possible characters
    expand(s1, s2);
    printf("%s\n", s2);  // Should print "abcdefghijklmnopqrstuvwxyz"
    return 0;
}
