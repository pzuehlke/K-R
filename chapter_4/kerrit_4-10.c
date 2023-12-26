/* Following S. 4.10 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>

void printd(int);
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
int main(void);

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }   
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

int main(void) {
    int number = -12345;
    printf("Printing the number: ");
    printd(number);
    putchar('\n');
    return 0;
}


/* qsort: sort v[left]...v[right] into increasing order using quicksort */
void qsort(int v[], int left, int right)
{
    int i, last;

    if (right <= left)
        return;
    else {
        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++) {
            if (v[i] < v[left])
                swap(v, ++last, i);
        }
        swap(v, left, last);
        qsort(v, left, last - 1);
        qsort(v, last + 1, right);
    }
}
    

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i], v[i] = v[j], v[j] = temp;
    return;
}
