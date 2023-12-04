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
    printf("\n================== Australia ==================\n");

    //
    printf("Date of change to winter time for Australia at the year %d : ", year);
    time_t datetime_for_winter_in_australia = wished_wday_in_choosen_month(year, 3, 0, 3, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of change to summer time for Australia at the year %d : ", year);
    time_t datetime_for_summer_in_australia = wished_wday_in_choosen_month(year, 9, 0, 2, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("=================================================");

    //
    printf("\n================== New Zealand ==================\n");

    //
    printf("Date of change to winter time for New Zealand at the year %d : ", year);
    time_t datetime_for_winter_in_new_zealand = wished_wday_in_choosen_month(year, 3, 0, 3, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_new_zealand)));

    //
    printf("Date of change to summer time for New Zealand at the year %d : ", year);
    time_t datetime_for_summer_in_new_zealand = wished_wday_in_choosen_month(year, 8, 0, 2, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_new_zealand)));

    //
    printf("=================================================");

    //
    printf("\n");

    //
    return 0;
}