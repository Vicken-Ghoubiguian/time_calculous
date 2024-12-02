#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Initialisation of 'main' function
int main() {

    // Definition of the used variable
    int year_0;
    int month_0;
    int mday_0;
    int hour_0;
    int minute_0;
    int second_0;
    struct tm *dt_0;
    time_t timestamp_0;
    time_t timestamp_1;
    struct tm *dt_1;
    int year_1;
    int month_1;
    int mday_1;
    int hour_1;
    int minute_1;
    int second_1;

    //
    printf("\n");
    printf("First datetime you want : \n");

    //
    printf("Please enter the year you want : ");
    scanf("%d", &year_0);
    printf("Please enter the month you want : ");
    scanf("%d", &month_0);
    printf("Please enter the month's day you want : ");
    scanf("%d", &mday_0);
    printf("Please enter the hour you want : ");
    scanf("%d", &hour_0);
    printf("Please enter the minute you want : ");
    scanf("%d", &minute_0);
    printf("Please enter the second you want : ");
    scanf("%d", &second_0);

    //
    printf("\n");
    printf("Second datetime you want : \n");

    //
    printf("Please enter the year you want : ");
    scanf("%d", &year_1);
    printf("Please enter the month you want : ");
    scanf("%d", &month_1);
    printf("Please enter the month's day you want : ");
    scanf("%d", &mday_1);
    printf("Please enter the hour you want : ");
    scanf("%d", &hour_1);
    printf("Please enter the minute you want : ");
    scanf("%d", &minute_1);
    printf("Please enter the second you want : ");
    scanf("%d", &second_1);
    printf("\n");

    //
    timestamp_0 = time(NULL);
    timestamp_1 = time(NULL);
    dt_0 = gmtime(&timestamp_0);
    dt_1 = gmtime(&timestamp_1);

    //
    dt_0->tm_year = year_0 - 1900;
    dt_0->tm_mon = month_0;
    dt_0->tm_mday = mday_0;
    dt_0->tm_hour = hour_0;
    dt_0->tm_min = minute_0;
    dt_0->tm_sec = second_0;

    //
    dt_1->tm_year = year_1 - 1900;
    dt_1->tm_mon = month_1;
    dt_1->tm_mday = mday_1;
    dt_1->tm_hour = hour_1;
    dt_1->tm_min = minute_1;
    dt_1->tm_sec = second_1;

    //
    timestamp_0 = timegm(dt_0);
    timestamp_1 = timegm(dt_1);

    //
    struct time_diff td = diffs_on_date_and_time(timestamp_0, timestamp_1);

    //
    printf("\n");

    //
    print_time_diff(td);

    //
    printf("\n\n");

    //
    return 0;
}