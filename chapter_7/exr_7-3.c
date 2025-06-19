/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-03
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

int minprintf(char* fmt, ...);  // `minprintf` will also return the char count

/* minprintf: minimal printf with variable argument list */
int minprintf(char* fmt, ...) {
    va_list ap;     /* points to each unnamed arg in turn */
    char* p;
    char* sval;
    int ival;
    double dval;
    unsigned uval;
    unsigned count = 0;

    va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            ++count;
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                count += printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                count += printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char*); *sval; sval++) {
                    putchar(*sval);
                    ++count;
                }
                break;
            case 'o':
                uval = va_arg(ap, unsigned);
                count += printf("%o", uval);
                break;
            case 'x':
                uval = va_arg(ap, unsigned);
                count += printf("%x", uval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                count += printf("%u", uval);
                break;
            default:
                putchar(*p);
                ++count;
                break;
        }
    }
    va_end(ap);

    return count;
}

int main(void) {
    minprintf("Integer: %d\n", -42);
    minprintf("Unsigned integer: %u\n", 42);
    minprintf("Floating-point: %f\n", 3.14159);
    minprintf("String: %s\n", "Hello, world!");
    minprintf("Octal: %o\n", 255);
    minprintf("Hexadecimal: %x\n", 255);
    return 0;
}