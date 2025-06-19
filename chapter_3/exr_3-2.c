/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 3.2
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

/* escape: copy t into s, but converting whitespace characters into their
 * visible representations, such as '\t' or '\n'. */
void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n': // newline
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t': // tab
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\v':  // vertical tab
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\r':  // carriage return
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\f':  // formfeed
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            default: // all other characters
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = '\0'; // don't forget to terminate s
}


/* escape: convert visible representations such as of whitespace '\t' or '\n'
 * into their literal forms. */
void unescape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') {
        if (s[i] == '\\') {
            switch (s[i + 1]) {
                case 'n':
                    t[j] = '\n';
                    i++;
                    break;
                case 't':
                    t[j] = '\t';
                    i++;
                    break;
                case 'v':
                    t[j] = '\v';
                    i++;
                    break;
                case 'r':
                    t[j] = '\r';
                    i++;
                    break;
                case 'f':
                    t[j] = '\f';
                    i++;
                    break;
                default:
                    t[j] = '\\';
                    break;
            }
        }
        else
            t[j] = s[i];
        i++;
        j++;
    }
    t[j] = '\0';
}   
    

int main() {
    char t[] = "Hello,\n\t\vWorld\f! This\t is a\r\rtest.";
    char s[100];

    printf("* Original string:\n%s\n\n", t);

    escape(s, t);
    printf("* Escaped string:\n%s\n\n", s);

    char u[100];
    unescape(s, u);
    printf("* Unescaped string:\n%s\n", u);

    return 0;
}