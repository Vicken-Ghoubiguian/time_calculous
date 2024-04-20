#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

//
int main() {

    // Definition of the used variable
    int decades;
    int years;
    int months;
    int weeks;
    int days;
    int hours;
    int minutes;
    int seconds;

    //
    printf("Veuillez entrer le nombre de décennies que vous voulez : ");
    scanf("%d", &decades);

    //
    printf("Veuillez entrer le nombre d'années que vous voulez : ");
    scanf("%d", &years);

    //
    printf("Veuillez entrer le nombre de mois que vous voulez : ");
    scanf("%d", &months);

    //
    printf("Veuillez entrer le nombre de semaines que vous voulez : ");
    scanf("%d", &weeks);

    //
    printf("Veuillez entrer le nombre de jours que vous voulez : ");
    scanf("%d", &days);

    //
    printf("Veuillez entrer le nombre de heures que vous voulez : ");
    scanf("%d", &hours);

    //
    printf("Veuillez entrer le nombre de minutes que vous voulez : ");
    scanf("%d", &minutes);

    //
    printf("Veuillez entrer le nombre de secondes que vous voulez : ");
    scanf("%d", &seconds);

    //
    time_t today = time(NULL);
    time_t calculations_results = calculations_on_date_and_time(gmtime(&today), decades, years, months, weeks, days, hours, minutes, seconds);

    // Breaking line instruction
    printf("\n");

    //
    printf("%s", asctime(gmtime(&calculations_results)));

    // Breaking line instruction
    printf("\n");

    //
    return 0;
}
