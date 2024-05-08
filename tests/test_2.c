#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

// Initialisation of 'main' function
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

    // To enter the wished number of decades
    printf("Veuillez entrer le nombre de décennies que vous voulez : ");
    scanf("%d", &decades);

    // To enter the wished number of years
    printf("Veuillez entrer le nombre d'années que vous voulez : ");
    scanf("%d", &years);

    // To enter the wished number of months
    printf("Veuillez entrer le nombre de mois que vous voulez : ");
    scanf("%d", &months);

    // To enter the wished number of weeks
    printf("Veuillez entrer le nombre de semaines que vous voulez : ");
    scanf("%d", &weeks);

    // To enter the wished number of days
    printf("Veuillez entrer le nombre de jours que vous voulez : ");
    scanf("%d", &days);

    // To enter the wished number of hours
    printf("Veuillez entrer le nombre de heures que vous voulez : ");
    scanf("%d", &hours);

    // To enter the wished number of minutes
    printf("Veuillez entrer le nombre de minutes que vous voulez : ");
    scanf("%d", &minutes);

    // To enter the wished number of seconds
    printf("Veuillez entrer le nombre de secondes que vous voulez : ");
    scanf("%d", &seconds);

    //
    time_t calculations_results = calculations_on_date_and_time_from_today(decades, years, months, weeks, days, hours, minutes, seconds);

    // Breaking line instruction
    printf("\n");

    // In the case where the 'calculations_results' variable is equal to -1 (an error occured)...
    if(calculations_results == -1)
    {
        //
        printf("%sThe resulting date and time are not corrects (The resulting date and time cannot be lower than January 1 1900 00:00:00)%s\n", BOLDRED, RESET);
    }
    // ...and in the other case...
    else
    {
        //
        printf("%sResulting date and time : %s%s", BOLDGREEN, asctime(gmtime(&calculations_results)), RESET);
    }

    // Breaking line instruction
    printf("\n");

    //
    return 0;
}
