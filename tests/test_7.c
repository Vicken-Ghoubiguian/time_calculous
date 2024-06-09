#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Initialisation of 'main' function
int main() {

    // 
    int year_0;
    int month_0;
    int mday_0;
    int hour_0;
    int minute_0;
    int second_0;
    struct tm dt_0;
    time_t timestamp_0;
    time_t timestamp_1;
    struct tm dt_1;
    int year_1;
    int month_1;
    int mday_1;
    int hour_1;
    int minute_1;
    int second_1;

    //
    struct time_diff td = diffs_on_date_and_time(1720549084, 1435207316);

    //
    printf("\n");

    //
    print_time_diff(td);

    //
    printf("\n");

    //
    return 0;
}