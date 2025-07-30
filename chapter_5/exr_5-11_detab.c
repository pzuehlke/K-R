/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-11 (detab)
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAB_LENGTH 8
#define MAX_TABS 100

int default_detab(void);
int detab(int tabs[], int number_of_tabs);

/* detab: replace tabs in the input with the proper number of blanks to space
   until the next tab stop. */
int main(int argc, char* argv[])
{
    int number_of_tabs = argc - 1;
    
    if (number_of_tabs > 0) {
        if (number_of_tabs > MAX_TABS) {
            printf("ERROR: Too many tab stops (max %d)\n", MAX_TABS);
            return 1;
        }
        
        int tabs[MAX_TABS];
        int i = 0;

        while (--argc > 0) {
            int tab_pos = atoi(*++argv);
            if (tab_pos <= 0) {
                printf("ERROR: Tab stops must be positive integers\n");
                return 1;
            }
            if (0 < i && tab_pos <= tabs[i-1]) {
                printf("ERROR: Tab stops must be in increasing order\n");
                return 1;
            }
            tabs[i++] = tab_pos;
        }
        
        detab(tabs, number_of_tabs);
    } else {
        default_detab();
    }

    return 0;
}

int detab(int tabs[], int number_of_tabs)
{
    int i = 0, position = 0, next;
    int c;
    int next_tab_index = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (next_tab_index < number_of_tabs) {
                // Use custom tabstop
                while (position < tabs[next_tab_index]) {
                    putchar(' ');
                    ++position;
                }
                ++next_tab_index;
            } else { // Beyond defined tabstops, assume default TAB_LENGTH
                int spaces_to_next = TAB_LENGTH - (position % TAB_LENGTH);
                for (int i = 0; i < spaces_to_next; ++i) {
                    putchar(' ');
                    ++position;
                }
            }
        } else if (c == '\n') {
            putchar('\n');
            position = 0;
            next_tab_index = 0;
        } else {
            putchar(c);
            ++position;
            if (next_tab_index < number_of_tabs
                && tabs[next_tab_index] <= position) {
                ++ next_tab_index;
            }
        }
    }

    return 0;
}

int default_detab(void)
{
    int i = 0, position = 0, next;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            next = TAB_LENGTH - (position % TAB_LENGTH);
            for (i = 0; i < next; ++i) {
                putchar(' ');
                ++position;
            }
        } else if (c == '\n') {
            putchar('\n');
            position = 0;
        } else {
            putchar(c);
            ++position;
        }
    }

    return 0;
}
