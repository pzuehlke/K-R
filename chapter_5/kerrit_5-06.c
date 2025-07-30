/* Following S. 5.6 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000        /* maximum number of lines to be sorted */
#define MAXLEN 1000     /* maximum length of any input line */
#define ALLOCSIZE 1000  /* size of variable space */

char *lineptr[MAXLINES];    /* pointers to text lines */

int get_line(char s[], int lim);
char *alloc(int n)  ;
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void swap(char *v[], int i, int j);
void qsort(char *lineptr[], int left, int right);

/* main: sort input lines */
int main(void)
{
    int nlines;     /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("ERROR: Input too big to sort!\n");
            return 1;
    }
}

/* get_line: read a line into s, return length. */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n)  
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else {    /* not enough room */
        return NULL;
    }
}


/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';   // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        } 
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)      /* do nothing if array contains fewer than 2 el. */
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
