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
    time_t timestamp = time(NULL);

    //
    printf("\n\n year | number of weeks \n");

    //
    while(year < 2100)
    {
        //
        printf(" %d  |    %d    \n", year, number_of_weeks_in_a_year_according_to_the_iso_norm(gmtime(&timestamp), year));

        //
        year++;
    }

    //
    printf("________________________\n\n");

    //
    return 0;
}