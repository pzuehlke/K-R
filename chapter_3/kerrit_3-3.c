/* Following S. 3.3 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>


/* binsearch: find x in list[0] <= list[1] <= ... <= list[n - 1] */
int binsearch(int x, int list[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == list[mid])     /* found match */
            return mid;
        else if (x < list[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;          /* no match */
}


int main() {
    int list[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(list) / sizeof(list[0]);
    int target = 16;

    int index = binsearch(target, list, n);

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found\n");

    return 0;
}
