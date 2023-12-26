/* Solution to Exercise 4-13 of K&R */
#include <stdio.h>
#include <string.h>

void recursive_reverse(char s[], int left, int right);
void reverse(char s[]);
void swap(char s[], int i, int j);

int main() {
    char s[] = "Hello, World!";
    reverse(s);
    printf("%s\n", s); // Output: "!dlroW ,olleH"
    return 0;
}

void recursive_reverse(char s[], int left, int right)
{
    if (left < right) {
        swap(s, left++, right--);
        recursive_reverse(s, left, right);
    }
}

void reverse(char s[]) {
    recursive_reverse(s, 0, strlen(s) - 1);
}

void swap(char s[], int i, int j)
{
    int temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

