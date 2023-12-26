/* Solution to exercise 1-21 of K&R */
# include <stdio.h>

# define TABSTOP 8


int entab(void);


int main(void)
{
    entab();
    return 0;
}


int entab(void)
{
    int c;
    int space_count = 0;    // pending spaces
    int position = 0;       // position of the cursor (incl. pending spaces)

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if (position % TABSTOP == TABSTOP - 1) {
                putchar('\t');      // Output tab to avoid using spaces
                space_count = 0;
            }
        }
        else {
            while (space_count > 0) {  // Output pending spaces (< TABSTOP)
                putchar(' ');
                space_count--;
            }
            putchar(c);
            if (c == '\n') {
                position = -1;      // The -1 will be removed below
            }
            else if (c == '\t') {
                position += (TABSTOP - position % TABSTOP) - 1; 
                // The -1 will be removed below
            }
        }
        position++; // In all cases, increment position by 1
    }
    return 0;
}
