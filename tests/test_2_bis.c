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
    int datetime_year;
    int datetime_month;
    int datetime_month_day;
    int number_of_days_in_month_in_year;
    time_t choosen_datetime_as_timestamp = time(NULL);
    struct tm *choosen_datetime_as_struct_tm;

    // Breaking line instruction
    printf("\n");

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &datetime_year);

    // In the case where the wished year is less than 1900...
    if(datetime_year < 1900)
    {
        //...so display error in red...
        printf("\n%sError : the year you entered is not valid, it must be greater than or equal to 1900!%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // To enter the wished month
    printf("Please enter the month you want [0 to 11] : ");
    scanf("%d", &datetime_month);

    //
    if(datetime_month < 0 || datetime_month > 11)
    {
        //
        printf("\n%sError : the month of the year you entered is not valid !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }

    //
    number_of_days_in_month_in_year = number_of_days_in_choosen_month_in_choosen_year(datetime_month, datetime_year);

    // To enter the wished month's day
    printf("Please enter the month day you want [1 to %d] : ", number_of_days_in_month_in_year);
    scanf("%d", &datetime_month_day);

    //
    if(datetime_month_day < 1 || datetime_month_day > number_of_days_in_month_in_year)
    {
        //
        printf("\n%sError : the month's day you entered is not valid !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }

    //
    choosen_datetime_as_struct_tm = gmtime(&choosen_datetime_as_timestamp);

    //
    choosen_datetime_as_struct_tm->tm_year = datetime_year - 1900;
    choosen_datetime_as_struct_tm->tm_mon = datetime_month;
    choosen_datetime_as_struct_tm->tm_mday = datetime_month_day;
    choosen_datetime_as_struct_tm->tm_hour = 0;
    choosen_datetime_as_struct_tm->tm_min = 0;
    choosen_datetime_as_struct_tm->tm_sec = 0;

    //
    choosen_datetime_as_timestamp = timegm(choosen_datetime_as_struct_tm);

    //
    printf("%s\nInitial date and time (UTC) : %s%s\n", BOLDMAGENTA, asctime(gmtime(&choosen_datetime_as_timestamp)), RESET);

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
    time_t calculations_results = calculations_on_date_and_time(choosen_datetime_as_timestamp, millennials, centuries, decades, years, months, weeks, days, hours, minutes, seconds);

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