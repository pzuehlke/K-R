/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 7-04
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdarg.h>

void minscanf(char* format, ...);

void minscanf(char* format, ...) {
    va_list arg_ptr;
    char* p;

    va_start(arg_ptr, format);
    for (p = format; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd': {
                int* ival = va_arg(arg_ptr, int*);  // returns an address
                scanf("%d", ival);
                break;
            }
            case 'f': {
                float* fval = va_arg(arg_ptr, float*);
                scanf("%f", fval);
                break;
            }
            case 's': {
                char* sval = va_arg(arg_ptr, char*);
                scanf("%s", sval);
                break;
            }
            default:
                break;
        }
    }
    va_end(arg_ptr);
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
