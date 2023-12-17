/* Solution to Exercise 1-9 of K&R */
# include <stdio.h>

int main(void)
{
    int blank_count = 0;
    int c;

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++blank_count;
            if (blank_count == 1)
                putchar(' ');
        }
        else 
        {
            putchar(c);
            blank_count = 0;
        }
    }

    return 0;
}
