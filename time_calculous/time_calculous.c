#include <time.h>
#include "time_calculous.h"

//
time_t diffs_on_date_and_time(struct tm *first_dt, struct tm *second_dt)
{
    //
    time_t first_dt_timestamp;
    time_t second_dt_timestamp;
    time_t calculation_result;

    //
    first_dt_timestamp = timegm(first_dt);
    second_dt_timestamp = timegm(second_dt);

    //
    calculation_result = first_dt_timestamp - second_dt_timestamp;

    //
    return calculation_result;
}

// Definition of the 'calculations_on_date_and_time' to make calculations on datetimes
time_t calculations_on_date_and_time(struct tm *cdatetime, int decades, int years, int months, int weeks, int days, int hours, int minutes, int seconds)
{
    //
    time_t cdatetime_timestamp;
    //time_t calculation_result_dt;
    long long int datetime_calculation;

    //
    /*if(decades > 0 || years >  0 || months > 0 || weeks > 0 || days > 0)
    {
        //
        //cdatetime->tm_year = cdatetime->tm_year + years;
    }*/

    // *************
    //long long int datetime_calculation = decade * decades + year * years + month * months + week * weeks + day * days + hour * hours + minute * minutes + second * seconds;
    cdatetime_timestamp = timegm(cdatetime);
    // *************

    //
    if(hours >  0 || minutes > 0 || seconds > 0)
    {
        //
        datetime_calculation = hour * hours + minute * minutes + second * seconds;

        //
        cdatetime_timestamp = cdatetime_timestamp + datetime_calculation;
    }

    //
    return cdatetime_timestamp;
}

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num)
{
    //
    int i = 0;
    int condition = 0;

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
    if(num == LAST || num == BEFORE_LAST){ date_tm->tm_mon = month + 1; }
    else{ date_tm->tm_mon = month; }

    //
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    //
    if((num == LAST) || (num == FIRST))
    {
        //
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
    }
    //
    else if(num == BEFORE_LAST)
    {
        //
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
    }
    //
    else if(num == SECOND)
    {
        //
        condition = date_tm->tm_wday != wday || i != 1;
    }
    //
    else if(num == THIRD)
    {
        //
        condition = date_tm->tm_wday != wday || i != 2;
    }

    //
    if((num == LAST) && (date_tm->tm_wday == 0))
    {
        //
        date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;

        //
        date_tm = gmtime(&date_timestamp);
    }

    //
    while(condition)
    {
        //
        if(num == BEFORE_LAST)
        {
            //
            if(date_tm->tm_wday == wday && date_tm->tm_mon == month)
            {
                //
                i = i + 1;
            }
        }
        //
        else if(num == SECOND || num == THIRD)
        {
            //
            if(date_tm->tm_wday == wday)
            {
                //
                i = i + 1;
            }
        }

        //
        if(num == LAST || num == BEFORE_LAST)
        {
            //
            date_timestamp = date_timestamp - NB_SECONDS_IN_DAY;
        }
        //
        else
        {
            //
            date_timestamp = date_timestamp + NB_SECONDS_IN_DAY;
        }

        //
        date_tm = gmtime(&date_timestamp);

        //
        if((num == LAST) || (num == FIRST))
        {
            //
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
        }
        //
        else if(num == BEFORE_LAST)
        {
            //
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
        }
        //
        else if(num == SECOND)
        {
            //
            condition = date_tm->tm_wday != wday || i != 1;
        }
        //
        else if(num == THIRD)
        {
            //
            condition = date_tm->tm_wday != wday || i != 2;
        }
    }

    //
    return date_timestamp;
}