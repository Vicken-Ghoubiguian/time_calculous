#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDMAGENTA "\033[1m\033[35m"

// Initialisation of 'main' function
int main() {

    //
    int year;
    int month;
    int number_of_days_in_month;

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

        //
        return -1;
    }

    // Breaking line instruction
    printf("\n");

    //
    number_of_days_in_month = number_of_days_in_choosen_month_in_choosen_year(month, year);

    //
    printf("%sNumber of days in %s in %d: %d%s\n\n", BOLDMAGENTA, months[month], year, number_of_days_in_month, RESET);

    //
    return 0;
}
