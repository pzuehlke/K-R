/* Following S. 2.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

int my_strlen(char s[]);
enum boolean {NO, YES};
enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t',
              NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main(void) {
    printf("%f\n", 1.0e-2);
    printf("%f\n", 1.234e2);
    printf("%d\n", '\377');
    printf("%c\n", '\x77');
    printf("%hd\n", 037);
    printf("%hd\n", 0x1F);
    printf("%ld\n", 0xFul);
    printf("%d\n", '0');
    printf("%d\n", '\0');
    printf("%s\n", "I am a string");
    printf("%s\n", "");
    printf("%s\n", "hello, " "world");
    printf("Length of \" test\": %d\n", my_strlen(" test"));
    printf("%d\n", NOV);
}

/* strlen: return length of a string. */
int my_strlen(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}
