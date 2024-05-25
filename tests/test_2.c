#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDMAGENTA "\033[1m\033[35m"

// Initialisation of 'main' function
int main() {

    // Definition of the used variable
    int millennials;
    int centuries;
    int decades;
    int years;
    int months;
    int weeks;
    int days;
    int hours;
    int minutes;
    int seconds;
    time_t today = time(NULL);

    //
    printf("%s\nInitial date and time (UTC) : %s%s\n", BOLDMAGENTA, asctime(gmtime(&today)), RESET);

    // To enter the wished number of millennials
    printf("Please enter the number of millennials you want : ");
    scanf("%d", &millennials);

    // To enter the wished number of centuries
    printf("Please enter the number of centuries you want : ");
    scanf("%d", &centuries);

    // To enter the wished number of decades
    printf("Please enter the number of decades you want : ");
    scanf("%d", &decades);

    // To enter the wished number of years
    printf("Please enter the number of years you want : ");
    scanf("%d", &years);

    // To enter the wished number of months
    printf("Please enter the number of months you want : ");
    scanf("%d", &months);

    // To enter the wished number of weeks
    printf("Please enter the number of weeks you want : ");
    scanf("%d", &weeks);

    // To enter the wished number of days
    printf("Please enter the number of days you want : ");
    scanf("%d", &days);

    // To enter the wished number of hours
    printf("Please enter the number of hours you want : ");
    scanf("%d", &hours);

    // To enter the wished number of minutes
    printf("Please enter the number of minutes you want : ");
    scanf("%d", &minutes);

    // To enter the wished number of seconds
    printf("Please enter the number of seconds you want : ");
    scanf("%d", &seconds);

    //
    time_t calculations_results = calculations_on_date_and_time(today, millennials, centuries, decades, years, months, weeks, days, hours, minutes, seconds);

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
        printf("%sResulting date and time (UTC) : %s%s", BOLDGREEN, asctime(gmtime(&calculations_results)), RESET);
    }

    // Breaking line instruction
    printf("\n");

    //
    return 0;
}
