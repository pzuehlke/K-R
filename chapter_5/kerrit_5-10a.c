/* Following S. 5.10 of Kernighan and Ritchie, "The C Programming Language" */

#include <stdio.h>

/* echo command-line arguments; 1st version */
int echo_1(int argc, char* argv[])
{
    int i;

    for (i = 1; i < argc; ++i) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "\n");
    }
    return 0;
}

/* echo command-line arguments; 2nd version */
int echo_2(int argc, char* argv[])
{
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "\n");
    }
    return 0;
}

int main(int argc, char* argv[])
{
    echo_1(argc, argv);
    // echo_2(argc, argv);
}
