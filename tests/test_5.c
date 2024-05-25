#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

// Initialisation of 'main' function
int main() {

    // Definition of all needed variables
    int year;
    int month;
    int mday;
    int number_of_day_in_year;
    int number_of_days_in_choosen_month;

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &year);

    // In the case where the wished year is less than 1900...
    if(year < 1900)
    {
        //...so display error in red...
        printf("\n%sError : the year you entered is not valid, it must be greater than or equal to 1900 !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // To enter the wished month
    printf("Please enter the month you want [0 to 11] : ");
    scanf("%d", &month);

    //
    if(month < 0 || month > 11)
    {
        //
        printf("\n%sError : the month of the year you entered is not valid !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    //
    printf("Please enter the day of the month you want :");
    scanf("%d", &mday);

    //
    if(mday < 0 || mday > number_of_days_in_choosen_month_in_choosen_year(month, year))
    {
        //
        printf("\n%sError : the day number in the month entered is not valid !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // Breaking line instruction
    printf("\n");

    //
    number_of_day_in_year = wished_number_in_year_is_day_in_choosen_year(mday, month, year);

    //
    printf("%sThe number of the requested day in the requested year :%d%s\n\n", BOLDGREEN, number_of_day_in_year, RESET);

    //
    return 0;
};