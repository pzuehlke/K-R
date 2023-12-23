/* Solution to Exercise 3-2 of K&R */
#include <stdio.h>

/* escape: converts whitespace characters into visible representations. */
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
            default: // all other characters
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = '\0'; // don't forget to terminate s
}

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
    char t[] = "Hello,\n\tWorld!";
    char s[100];

    printf("Original string: %s\n", t);

    escape(s, t);
    printf("Escaped string: %s\n", s);

    char u[100];
    unescape(s, u);
    printf("Unescaped string: %s\n", u);

    return 0;
}
