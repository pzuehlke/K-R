/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-11 (entab)
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAB_LENGTH 8
#define MAX_TABS 100

int default_entab(void);
int entab(int tabs[], int number_of_tabs);

/* entab: replace strings of consecutive blanks by the minimum number of tabs and
 * blanks to achieve the same spacing. */
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
        
        entab(tabs, number_of_tabs);
    } else {
        default_entab();
    }

    return 0;
}

int entab(int tabs[], int number_of_tabs)
{
    int c;
    int space_count = 0;    // pending spaces
    int position = 0;       // position of the cursor (incl. pending spaces)
    int next_tab_index = 0;

    while ((c = getchar()) != EOF) {
        ++position;
        while (next_tab_index < number_of_tabs
               && tabs[next_tab_index] < position) {
            ++next_tab_index;
        }
        if (c == ' ') {
            ++space_count;
            if (next_tab_index < number_of_tabs &&
                    position == tabs[next_tab_index]) {
                putchar('\t');      // Output tab to avoid using spaces
                space_count = 0;
                ++next_tab_index;
            }
        } else {
            while (space_count > 0) {  // Output pending spaces
                putchar(' ');
                --space_count;
            }
            putchar(c);
            if (c == '\n') {
                position = 0;
                next_tab_index = 0;
            } else if (c == '\t' && next_tab_index < number_of_tabs) {
                position = tabs[next_tab_index++];
            }
        }
    }
    return 0;
}

int default_entab(void)
{
    int c;
    int space_count = 0;    // pending spaces
    int position = 0;       // position of the cursor (incl. pending spaces)

    while ((c = getchar()) != EOF) {
        ++position;
        if (c == ' ') {
            ++space_count;
            if (position % TAB_LENGTH == 0) {
                putchar('\t');      // Output tab to avoid using spaces
                space_count = 0;
            }
        } else {
            while (space_count > 0) {  // Output pending spaces (< TAB_LENGTH)
                putchar(' ');
                --space_count;
            }
            putchar(c);
            if (c == '\n') {
                position = 0;
            } else if (c == '\t') {
                position += (TAB_LENGTH - position % TAB_LENGTH); 
            }
        }
    }
    return 0;
}
