/* Solution to Exercise 1-8 of K&R */
# include <stdio.h>

int main(void)
{
    int n_blanks = 0;
    int n_tabs = 0;
    int n_newlines = 0;
    int c;

    printf("Enter text (press Ctrl+D on a new line to finish):\n");
    while((c = getchar()) != EOF)
    {
        if (c == '\t')
            ++n_tabs;
        if (c == '\n')
            ++n_newlines;
        if (c == ' ')
            ++n_blanks;
    }
    printf("\n# Tabs \t # Newlines \t # Blanks\n");
    printf("   %d \t      %d \t      %d\n", n_tabs, n_newlines, n_blanks);

    return 0;
}

