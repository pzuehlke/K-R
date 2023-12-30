/* Following S. 6.1 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#include <math.h>

double sqrt(double);

int main(void)
{
    double dist;

    struct point {
        int x;
        int y;
    };

    struct point pt = {3, 4};
    struct point maxpt = {320, 200};
    printf("(%d,%d)\n", maxpt.x, maxpt.y);

    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("Distance from the origin: %f\n", dist);

    struct rect {
        struct point pt1;
        struct point pt2;
    };

    struct rect screen = {pt, maxpt};
    printf("%d\n", screen.pt1.x);

    return 0;
}


