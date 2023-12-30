/* Following S. 5.5 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

void strcopy0(char *s, char *t);
void strcopy1(char *s, char *t);
void strcopy2(char *s, char *t);
void strcopy3(char *s, char *t);
int strcmp(char *s, char *t);
int strcmp2(char *s, char *t);

int main(void)
{
    char s1[100], s2[100], s3[100], s4[100];
    char *t = "Hello, world!";
    
    // Testing strcopy0
    strcopy0(s1, t);
    printf("Result of strcopy0: %s\n", s1);

    // Testing strcopy1
    strcopy1(s2, t);
    printf("Result of strcopy1: %s\n", s2);

    // Testing strcopy2
    strcopy2(s3, t);
    printf("Result of strcopy2: %s\n", s3);

    // Testing strcopy3
    strcopy3(s4, t);
    printf("Result of strcopy3: %s\n", s4);

    // Testing strcmp
    char *u = "Hello, world!";
    char *v = "Hello, moon!";
    printf("Result of strcmp (should be 0): %d\n", strcmp(u, u));
    printf("Result of strcmp (should not be 0): %d\n", strcmp(u, v));

    // Testing strcmp2
    printf("Result of strcmp2 (should be 0): %d\n", strcmp2(u, u));
    printf("Result of strcmp2 (should not be 0): %d\n", strcmp2(u, v));

    return 0;
}

/* strcopy0: copy t to to s; array subscript version */
void strcopy0(char *s, char *t)
{
    int i = 0;

    while ((s[i] = t[i]) != '\0')
        i++;
}


/* strcopy1: copy t to to s; pointer version */
void strcopy1(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}


/* strcopy2: copy t to to s; pointer version 2 */
void strcopy2(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}


/* strcopy3: copy t to to s; pointer version 3 */
void strcopy3(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

/* strcmp: return < 0 if s < t; 0 if s == t; > 0 if s > t */
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}


/* strcmp2: return < 0 if s < t; 0 if s == t; > 0 if s > t */
int strcmp2(char *s, char *t)
{
    while (*s == *t) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }
    return *s - *t;
}
