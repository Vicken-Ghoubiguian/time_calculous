#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDRED "\033[0;31m"

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Initialisation of 'main' function
int main() {

    // Definition of 'year' variable
    int year;

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

    // To get the number of weeks in the wished year
    int weeks_count = number_of_weeks_in_a_year_according_to_the_iso_norm(year);

    //
    printf("\n");

    // To display the number of weeks in the wished year
    printf("Number of weeks in the year %d : %d\n", year, weeks_count);

    //
    printf("\n");

    //
    return 0;
}
