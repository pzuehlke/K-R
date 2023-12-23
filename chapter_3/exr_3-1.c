/* Solution to Exercise 3-1 of K&R */

/* binsearch: find x in list[0] <= list[1] <= ... <= list[n - 1] */
int binsearch(int x, int list[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x <= list[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == list[low])
        return mid;
    else
        return -1;
}
