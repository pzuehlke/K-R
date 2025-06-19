/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-04
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdarg.h>

void minscanf(char* fmt, ...);

void minscanf(char* fmt, ...) {
    va_list ap;
    char* p;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd': {
                int* ival = va_arg(ap, int *);  // va_arg returns an address
                scanf("%d", ival);
                break;
            }
            case 'f': {
                float* fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            }
            case 's': {
                char* sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            }
            default:
                break;
        }
    }
    va_end(ap);
}

int main(void) {
    int num;
    float f;
    char str[100];
    
    printf("Enter an integer: ");
    minscanf("%d", &num);
    printf("You entered: %d\n", num);
    
    printf("Enter a float: ");
    minscanf("%f", &f);
    printf("You entered: %f\n", f);
    
    printf("Enter a string: ");
    minscanf("%s", str);
    printf("You entered: %s\n", str);
    
    return 0;
}