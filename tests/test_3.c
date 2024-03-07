#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    time_t timestamp = time(NULL);

    //
    int weeks_count = number_of_weeks_in_a_year_according_iso_norm(gmtime(&timestamp), 2021);

    //
    printf("Number of weeks in the year %d : %d.\n", 2021, weeks_count);

    //
    return 0;
}