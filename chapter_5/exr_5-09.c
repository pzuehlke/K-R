/*****************************************************************************
 * The C Programming Language (2nd., ANSI C ed.) by Kernighan and Ritchie
 * Exercise 5-09
 * Author: pzuehlke
 ****************************************************************************/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

static char daytab_nonleap[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char daytab_leap[] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[] = {daytab_nonleap, daytab_leap};


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    for (i = 1; i < month; i++) {
        day += *(*(daytab + leap) + i);
    }
    return day;
}


/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= *(*(daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yearday;
}


int main(void)
{
    int year, month, day, yearday;
    int test_month, test_day;

    // Test cases for day_of_year:
    printf("Testing `day_of_year`:\n");
    year = 2020; month = 2; day = 29; // Leap year
    printf("Day of year for %d/%02d/%02d: %d\n",
            year, month, day, day_of_year(year, month, day));

    year = 2021; month = 12; day = 31; // End of a regular year
    printf("Day of year for %d/%02d/%02d: %d\n",
            year, month, day, day_of_year(year, month, day));

    // Test cases for month_day:
    printf("\nTesting `month_day`:\n");
    year = 2020; yearday = 60; // Leap year, Feb 29
    month_day(year, yearday, &test_month, &test_day);
    printf("Month and day for day %d of %d: %02d/%02d\n",
            yearday, year, test_month, test_day);

    year = 2021; yearday = 365; // End of a regular year
    month_day(year, yearday, &test_month, &test_day);
    printf("Month and day for day %d of %d: %02d/%02d\n",
            yearday, year, test_month, test_day);

    return 0;
}
