/* Solution to exercise 1-22 of K&R */
# include <stdio.h>

# define LINE_LEN 40
# define TABSTOP 8


int fold(void);


int main(void)
{
    return 0;
}


int fold(void)
{
    char buf[];
    char c;
    int position = 0;
    int blank_count = 0;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            position = 0;
            putchar('\n');
            for (i = 0; i < strlen(buf); i++)
                putchar(buf[i]);
            blank_count = 0;
            i = 0;
        }
        if (c == ' ') {
            if (blank_count == 0) {
                buf[i] = '\0';
                position += i;
                for (i = 0; i < strlen(buf); i++)
                    putchar(buf[i]);
            }
            else

            blank_count++;
        }
        if (blank_count > 0) {
            if (c == ' ') {
                blank_count++;
                position++;
            }
            if (c == '\t') {
                position += TABSTOP - (position % TABSTOP);

            }
    }

}

