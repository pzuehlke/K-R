/* Solution to Exercise 1-10 of K&R */
# include <stdio.h>

int main(void)
{
    int c;

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar('\\');
            putchar('\n');
        }
        else if (c == '\t') {
            putchar('\\');
            putchar('\t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('\b');
        }
        else
            putchar(c);
    }

    return 0;
}
