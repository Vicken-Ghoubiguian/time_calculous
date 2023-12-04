#include <time.h>
#include "time_calculous.h"

//
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, enum numeral num)
{
    //
    struct tm *date_tm;
    time_t date_timestamp;

    //
    time_t today = time(NULL);

    //
    date_tm = gmtime(&today);

    //
    date_tm->tm_year = year - 1900;
    date_tm->tm_mday = 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

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