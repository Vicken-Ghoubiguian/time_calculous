#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDBLUE "\033[1m\033[34m"

// Initialisation of 'main' function
int main() {

    // Definition of all needed variables
    int year;
    int month;
    int wday;

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &year);

    // In the case where the wished year is less than 1900...
    if(year < 1900)
    {
        //...so display error in red...
        printf("\n%sError: the year you entered is not valid, it must be greater than or equal to 1900!%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // To enter the wished month
    printf("Please enter the month you want [0 to 11] : ");
    scanf("%d", &month);

    //
    if(month < 0 || month > 11)
    {
        //
        printf("\n%sError : the month of the year you entered is not valid !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }

    //
    printf("Please enter the day of the week you want [0 to 6] : ");
    scanf("%d", &wday);

    //
    if(wday < 0 || wday > 6)
    {
        //
        printf("\n%sError: the day of the week you entered is not valid !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }

    // Breaking line instruction
    printf("\n");

    //
    printf("%sDate of first %s of %s %d : ", BOLDBLUE, weekDays[wday], months[month], year);
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
    printf("%s%s", asctime(gmtime(&datetime_for_last)), RESET);

    // Breaking line instruction
    printf("\n");

    //
    return 0;
}
