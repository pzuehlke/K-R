/* Following S. 6.8 of Kernighan and Ritchie, "The C Programming Language" */
#include <stdio.h>


union u_tag {
    int ival;
    float fval;
    char *sval;
};
enum UnionType {INT, FLOAT, STRING};

int print_union(union u_tag u, int utype);


int main(void)
{
    union u_tag u;
    int utype;

    u.ival = 3;
    utype = INT;
    print_union(u, utype);

    u.fval = 3.0;
    utype = FLOAT;
    print_union(u, utype);

    u.sval = "This is a test";
    utype = STRING;
    print_union(u, utype);

    return 0;
}


int print_union(union u_tag u, int utype)
{

    if (utype == INT)
        printf("%d\n", u.ival);
    else if (utype == FLOAT)
        printf("%f\n", u.fval);
    else if (utype == STRING)
        printf("%s\n", u.sval);
    else
        printf("bad type %d in utype\n", utype);

    return 0;
}
