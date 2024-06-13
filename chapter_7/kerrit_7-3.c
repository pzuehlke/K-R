/* Following S. 7.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

/* minprintf: minimial printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;     /* points to each unnamed arg in turn */
    char * p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char*); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
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
