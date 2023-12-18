#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    int year;
    int month;
    int wday;

    //
    printf("\n");

    //
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    //
    printf("Veuillez entrer le mois que vous voulez [de 0 à 11] : ");
    scanf("%d", &month);

    //
    if(month < 0 || month > 11)
    {
        //
        printf("Erreur : le mois de l'année que vous avez renseigné n'est pas valide !\n");

        //
        return -1;
    }

    //
    printf("Veuillez entrer le jour de la semaine que vous voulez [de 0 à 6] : ");
    scanf("%d", &wday);

    //
    if(wday < 0 || wday > 6)
    {
        //
        printf("Erreur : le jour de la semaine que vous avez renseigné n'est pas valide !\n");

        //
        return -1;
    }

    //
    printf("Date of first %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_first = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_first)));

    //
    /*printf("Date of first %s of October %d : ", weekDays[wday], year);
    time_t datetime_for_summer_in_australia = wished_wday_in_choosen_month(year, 9, wday, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_summer_in_australia)));*/

    //
    printf("Date of last %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_last = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_last)));

    //
    printf("\n");

    //
    return 0;
}