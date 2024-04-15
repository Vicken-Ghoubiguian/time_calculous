#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDBLUE "\033[1m\033[34m"

// Initialisation of 'main' function
int main() {

    // Definition of all useful variables and their implementation for some of them
    int weeks_count;
    int year = 2000;
    int number_of_weeks_in_the_year;
    time_t timestamp = time(NULL);

    // To display top of the array
    printf("\n____________________________\n");
    printf("| %s year %s |%s number of weeks %s|\n", BOLDBLUE, RESET, BOLDBLUE, RESET);
    printf("|________|_________________|\n");

    // Definition of a loop to stop calculous at the year 2100 : calculous on current century
    while(year <= 2100)
    {
        // Calculous on the number of weeks in the year 'year' using the 'number_of_weeks_in_a_year_according_to_the_iso_norm' function
        number_of_weeks_in_the_year = number_of_weeks_in_a_year_according_to_the_iso_norm(gmtime(&timestamp), year);

        // In the case where there are 53 weeks in the year...
        if(number_of_weeks_in_the_year == 53)
        {
            // ...display in red...
            printf("| %s %d %s | %s %d %s            |\n", BOLDRED, year, RESET, BOLDRED, number_of_weeks_in_the_year, RESET);
        }
        // ...and in the other case...
        else
        {
            // ...display in green
            printf("| %s %d %s | %s %d %s            |\n", BOLDGREEN, year, RESET, BOLDGREEN, number_of_weeks_in_the_year, RESET);
        }

        // Incrementation of the year 'year' to the following year
        year++;
    }

    // To display foot of the array
    printf("|________|_________________|\n\n");

    // Return the success code of the 'main' function
    return 0;
}
