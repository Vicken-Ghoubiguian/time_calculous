#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

//
int main() {

    //
    int weeks_count;
    int year = 2000;
    time_t timestamp = time(NULL);

    //
    printf("\n___________________________\n");
    printf("| year  | number of weeks |\n");
    printf("|_______|_________________|\n");

    //
    while(year < 2100)
    {
        //
        printf("| %d  |    %d           |\n", year, number_of_weeks_in_a_year_according_to_the_iso_norm(gmtime(&timestamp), year));

        //
        year++;
    }

    //
    printf("|_______|_________________|\n\n");

    //
    return 0;
}