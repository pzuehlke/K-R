/* Following S. 5.11 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000   /* max # of lines to be sorted */
#define ALLOCSIZE 1000  /* size of variable space */
#define MAXLEN 1000     /* maximum length of any input line */

char* line_pointer[MAXLINES];   /* pointers to text lines */

int read_lines(char* line_pointer[], int nlines);
void write_lines(char* line_pointer[], int nlines);
int numcmp(const char*, const char*);
void quicksort(void* line_pointer[], int left, int right,
               int (*comp)(void*, void*));

/* sort input lines */
int main(int argc, char* argv[])
{
    int nlines;     /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = read_lines(line_pointer, MAXLINES)) >= 0) {
        quicksort((void**) line_pointer, 0, nlines - 1,
              (int (*)(void*, void*)) (numeric ? numcmp : strcmp));
        write_lines(line_pointer, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

/* quicksort: sort v[left]...v[right] into increasing order  */
void quicksort(void* v[], int left, int right, int (*comp)(void*, void*))
{
    int i, last;
    void swap(void* v[], int, int);
    if (left >= right) { return; }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; ++i) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quicksort(v, left, last - 1, comp);
    quicksort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char* s1, const char* s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)        { return - 1; }
    else if (v1 > v2)   { return 1; }
    else                { return 0; }
}

void swap(void* v[], int i, int j)
{
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

/* read_lines: read input lines */
int read_lines(char *lineptr[], int maxlines)
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

/* write_lines: write output lines */
void write_lines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
