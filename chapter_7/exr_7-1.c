/* Solution to Exercise 7-1 of K&R */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    // Pointer to the conversion function; default: `tolower`:
    int (*convert)(int) = tolower; 

    if (strstr(argv[0], "upper")) {
        convert = toupper;
    }

    while (c = getchar() != EOF) {
        putchar(convert(c));
    }

    return 0;
}
