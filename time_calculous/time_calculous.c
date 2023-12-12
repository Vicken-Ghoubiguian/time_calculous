#include <time.h>
#include "time_calculous.h"

//
time_t diffs__on_date_and_time(struct tm *first_dt, struct tm *second_dt)
{
    //
    return 0;
}

//
time_t calculations_on_date_and_time(struct tm *cdatetime, long long int tmst)
{
    //
    time_t cdatetime_timestamp;
    time_t calculation_result_dt;

    //
    cdatetime_timestamp = timegm(cdatetime);

    //
    calculation_result_dt = cdatetime_timestamp + tmst;

    //
    return calculation_result_dt;
}

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num)
{
    // Definition of the 'date_tm' and the 'date_timestamp' variables
    struct tm *date_tm;
    time_t date_timestamp;

    // Definition of the 'today' variable and its initialization
    time_t today = time(NULL);

    //
    date_tm = gmtime(&today);

    // Initialization of the 'date_tm' to make all the necessary calculations
    date_tm->tm_year = year - 1900;
    date_tm->tm_mday = 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = minute;
    date_tm->tm_sec = second;

    //
    if(num == LAST){ date_tm->tm_mon = month + 1; }
    else{ date_tm->tm_mon = month; }

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    if((num == LAST) && (date_tm->tm_wday == 0))
    {
        //
        date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;

        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    while(date_tm->tm_wday != wday)
    {
        //
        if(num == LAST){ date_timestamp = date_timestamp - NB_SECONDS_IN_DAY; }
        else{ date_timestamp = date_timestamp + NB_SECONDS_IN_DAY; }
                
        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    return date_timestamp;
}