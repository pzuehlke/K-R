/* Following S. 6.2 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>
#define min(a, b)  ((a) < (b) ? (a) : (b))
#define max(a, b)  ((a) < (b) ? (b) : (a))
#define XMAX 320
#define YMAX 200

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};


/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}


/* addpoint: add two points */
struct point addpoint(struct point pt1, struct point pt2)
{
    pt1.x += pt2.x;
    pt1.y += pt2.y;
    return pt1;
}


/* ptinrect: return 1 if point in rectangle, 0 otherwise */
int ptinrect(struct point p, struct rect r)
{
    return (r.pt1.x <= p.x && p.x < r.pt2.x &&
            r.pt1.y <= p.y && p.y < r.pt2.y);
}


/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}


int main(void) {

    struct rect screen;
    struct point p1 = makepoint(3, 4);
    struct point p2 = makepoint(5, 6);
    struct point middle;
    struct point *pp, origin = {0, 0};

    // Sample points
    screen.pt1 = origin;
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    pp = &origin;
    printf("Origin is (%d, %d)\n", (*pp).x, (*pp).y);

    // Testing `addpoint`
    struct point sum = addpoint(p1, p2);
    printf("Sum of points: (%d, %d)\n", sum.x, sum.y);

    // Testing `ptinrect`
    struct rect r;
    r.pt1 = makepoint(2, 2);
    r.pt2 = makepoint(6, 6);
    printf("Point p1 %s in the rectangle\n", ptinrect(p1, r) ? "is" : "is not");
    printf("Point p2 %s in the rectangle\n", ptinrect(p2, r) ? "is" : "is not");

    // Testing `canonrect`
    struct rect cr = canonrect(r);
    printf("Canonical rectangle: ((%d, %d), (%d, %d))\n", cr.pt1.x, cr.pt1.y, cr.pt2.x, cr.pt2.y);

    return 0;
}
