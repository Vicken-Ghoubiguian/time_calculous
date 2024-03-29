#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    // Definition of all needed variables
    int year;
    int month;
    int wday;

    // Breaking line instruction
    printf("\n");

    // To enter the wished year
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    // To enter the wished month
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

    // Breaking line instruction
    printf("\n");

    //
    printf("Date of first %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_first = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, FIRST);
    printf("%s", asctime(gmtime(&datetime_for_first)));

    //
    printf("Date of second %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_second = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, SECOND);
    printf("%s", asctime(gmtime(&datetime_for_second)));

    //
    printf("Date of third %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_third = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, THIRD);
    printf("%s", asctime(gmtime(&datetime_for_third)));

    //
    printf("Date of before last %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_before_last = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, BEFORE_LAST);
    printf("%s", asctime(gmtime(&datetime_for_before_last)));

    //
    printf("Date of last %s of %s %d : ", weekDays[wday], months[month], year);
    time_t datetime_for_last = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, LAST);
    printf("%s", asctime(gmtime(&datetime_for_last)));

    // Breaking line instruction
    printf("\n");

    //
    return 0;
}