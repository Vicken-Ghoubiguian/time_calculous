#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    int year;
    int wday;

    //
    printf("\n");

    //
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    printf("Veuillez entrer le jour de la semaine que vous voulez : ");
    scanf("%d", &wday);

    //
    printf("Date of first tuesday of April %d : ", year);
    time_t datetime_for_winter_in_australia = wished_wday_in_choosen_month(year, 3, wday, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_winter_in_australia)));

    //
    printf("Date of first tuesday of October %d : ", year);
    time_t datetime_for_summer_in_australia = wished_wday_in_choosen_month(year, 9, wday, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));

    //
    printf("Date of last tuesday of September %d : ", year);
    time_t datetime_for_summer_in_new_zealand = wished_wday_in_choosen_month(year, 8, wday, 0, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_new_zealand)));

    //
    printf("\n");

    //
    return 0;
}