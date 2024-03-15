#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    int weeks_count;
    int year = 2000;
    int number_of_weeks_in_the_year;
    time_t timestamp = time(NULL);

    //
    printf("\n___________________________\n");
    printf("| \033[1m\033[34m year \033[0m |\033[1m\033[34m number of weeks \033[0m|\n");
    printf("|________|_________________|\n");

    //
    while(year < 2100)
    {
        //
        number_of_weeks_in_the_year = number_of_weeks_in_a_year_according_to_the_iso_norm(gmtime(&timestamp), year);

        //
        if(number_of_weeks_in_the_year == 53)
        {
            //
            printf("| \033[1m\033[31m %d \033[0m | \033[1m\033[31m   %d    \033[0m       |\n", year, number_of_weeks_in_the_year);
        }
        //
        else
        {
            //
            printf("| \033[1m\033[32m %d \033[0m | \033[1m\033[32m   %d    \033[0m       |\n", year, number_of_weeks_in_the_year);
        }

        //
        year++;
    }

    //
    printf("|________|_________________|\n\n");

    //
    return 0;
}