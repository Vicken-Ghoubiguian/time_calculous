#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    int decades;
    int years;
    int months;
    int weeks;
    int days;
    int hours;
    int minutes;
    int seconds;

    //
    printf("\n");

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
    long long int datetime_calculation = decade * decades + year * years + month * months + week * weeks + day * days + hour * hours + minute * minutes + second * seconds;

    //
    time_t today = time(NULL);
    time_t calculations_results = calculations_on_date_and_time(gmtime(&today), datetime_calculation);

    //
    printf("%s", asctime(gmtime(&calculations_results)));

    //
    return 0;
}