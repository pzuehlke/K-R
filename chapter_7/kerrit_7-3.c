/* Following S. 7.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

/* minprintf: minimial printf with variable argument list */
void minprintf(char* format, ...)
{
    va_list arg_ptr;    /* points to each unnamed argument in turn */
    char* p;
    char* sval;
    int ival;
    double dval;

    va_start(arg_ptr, format);   /* make arg_ptr point to 1st unnamed arg */
    for (p = format; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) { // encountered a '%', move to next character
            case 'd':
                ival = va_arg(arg_ptr, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(arg_ptr, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(arg_ptr, char*); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(arg_ptr);
}

/* main: testing function */
int main(void) {
    // Test with a simple string:
    printf("Test 1: ");
    minprintf("Hello, world!\n");

    // Test with integer formatting:
    printf("Test 2: ");
    minprintf("Integer: %d\n", 42);

    // Test with floating-point formatting:
    printf("Test 3: ");
    minprintf("Floating-point: %f\n", 3.14159);

    // Test with string formatting:
    printf("Test 4: ");
    minprintf("String: %s\n", "Test string");

    // Test with mixed types:
    printf("Test 5: ");
    minprintf("Mix: %d, %f, %s\n", 123, 9.876, "abcdef");

    return 0;
}
