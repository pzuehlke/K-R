#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...) {
    va_list ap;     /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;

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
            case 'o':
                uval = va_arg(ap, unsigned);
                printf("%o", uval);
                break;
            case 'x':
                uval = va_arg(ap, unsigned);
                printf("%x", uval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
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
