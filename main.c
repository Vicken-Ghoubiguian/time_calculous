#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
#include "time_calculous/time_calculous.h"

//
int main() {

    //
    int year;

    //
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    //
    printf("Date of first sunday of April %d : ", year);
    time_t datetime_for_winter_in_australia = wished_wday_in_choosen_month(year, 3, 0, 3, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of first sunday of October %d : ", year);
    time_t datetime_for_summer_in_australia = wished_wday_in_choosen_month(year, 9, 0, 2, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("Date of last sunday of September %d : ", year);
    time_t datetime_for_summer_in_new_zealand = wished_wday_in_choosen_month(year, 8, 0, 2, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_new_zealand)));

    //
    printf("\n");

    //
    return 0;
}