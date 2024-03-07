#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    int year;

    //
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    //
    time_t timestamp = time(NULL);

    //
    int weeks_count = number_of_weeks_in_a_year_according_iso_norm(gmtime(&timestamp), year);

    //
    printf("Number of weeks in the year %d : %d.\n", year, weeks_count);

    //
    return 0;
}