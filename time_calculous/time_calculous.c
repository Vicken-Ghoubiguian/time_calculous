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
    long long int datetime_calculation;

    //
    if(decades > 0 || years >  0 || months > 0 || weeks > 0 || days > 0)
    {
        //
        cdatetime->tm_year = cdatetime->tm_year + ((decades * 10) + years);

        //
        cdatetime->tm_mon = (cdatetime->tm_mon + months) % 12;
    }

    //
    cdatetime_timestamp = timegm(cdatetime);

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

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished weekday in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num)
{
    // Definition of all needed variables
    int i = 0;
    int condition = 0;
    struct tm *date_tm;
    time_t date_timestamp;
    time_t today = time(NULL);

    // Initialization of the 'date_tm' variable to now date and time
    date_tm = gmtime(&today);

    // Initialization of the 'date_tm' variable to make all the necessary calculations
    date_tm->tm_year = year - 1900;
    date_tm->tm_mday = 1;
    date_tm->tm_hour = hour;
    date_tm->tm_min = minute;
    date_tm->tm_sec = second;

    //
    if(num == LAST || num == BEFORE_LAST){ date_tm->tm_mon = month + 1; }
    else{ date_tm->tm_mon = month; }

    // Initialization of the 'date_timestamp' and 'date_tm' variables 
    date_timestamp = timegm(date_tm);
    date_tm = gmtime(&date_timestamp);

    // If the wished weekday is the first or the last ones in month...
    if((num == LAST) || (num == FIRST))
    {
        // Definition of the condition : weekday is different from the wished one and month is different from the wished one
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
    }
    // In another case, if the wished weekday is the before last one in month...
    else if(num == BEFORE_LAST)
    {
        // Definition of the condition : weekday is different from the wished one and month is different from the wished one and incrementor is different from 1
        condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
    }
    // In another case, if the wished weekday is the second one in month...
    else if(num == SECOND)
    {
        // Definition of the condition : weekday is different from the wished one and incrementor is different from 1
        condition = date_tm->tm_wday != wday || i != 1;
    }
    // In another case, if the wished weekday is the third one in month...
    else if(num == THIRD)
    {
        // Definition of the condition : weekday is different from the wished one and incrementor is different from 2
        condition = date_tm->tm_wday != wday || i != 2;
    }

    //
    if((num == LAST) && (date_tm->tm_wday == wday))
    {
        //
        date_timestamp = date_timestamp - day;

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
            date_timestamp = date_timestamp - day;
        }
        //
        else
        {
            //
            date_timestamp = date_timestamp + day;
        }

        //
        date_tm = gmtime(&date_timestamp);

        // If the wished weekday is the first or the last ones in month...
        if((num == LAST) || (num == FIRST))
        {
            // Definition of the condition : weekday is different from the wished one and month is different from the wished one
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month;
        }
        // In another case, if the wished weekday is the before last one in month...
        else if(num == BEFORE_LAST)
        {
            // Definition of the condition : weekday is different from the wished one and month is different from the wished one and incrementor is different from 1
            condition = date_tm->tm_wday != wday || date_tm->tm_mon != month || i != 1;
        }
        // In another case, if the wished weekday is the second one in month...
        else if(num == SECOND)
        {
            // Definition of the condition : weekday is different from the wished one and incrementor is different from 1
            condition = date_tm->tm_wday != wday || i != 1;
        }
        // In another case, if the wished weekday is the third one in month...
        else if(num == THIRD)
        {
            // Definition of the condition : weekday is different from the wished one and incrementor is different from 2
            condition = date_tm->tm_wday != wday || i != 2;
        }
    }

    // Returning the 'date_timestamp' variable with the 
    return date_timestamp;
}

// Definition of the 'number_of_weeks_in_a_year_according_to_the_iso_norm' function to determine how many weeks there are in the year according iso norm
int number_of_weeks_in_a_year_according_to_the_iso_norm(int year)
{
    // Definition of all needed variables
    int condition;
    int is_leap_year_condition;
    struct tm *datetime;
    time_t timestamp;
    time_t current_time = time(NULL);

    //
    datetime = gmtime(&current_time);

    // Initialization of the 'date_tm' to make all the necessary calculations
    datetime->tm_year = year - 1900;
    datetime->tm_mday = 1;
    datetime->tm_mon = 0;

    //
    timestamp = mktime(datetime);
    datetime = gmtime(&timestamp);

    // 
    /* Explanation of the condition : the wished year has 53 years if...
     * -
     OR
     * - 
        * - 
        * - 
        * -
     */
    condition = (datetime->tm_wday == 4) || ((datetime->tm_wday == 3) && (((datetime->tm_year % 4 == 0) && (datetime->tm_year % 100 != 0)) || (datetime->tm_year % 400 == 0)));

    // If the condition is satisfied...
    if(condition)
    {
        // ...returning 53 (because the wished year contains 53 weeks)
        return 53;
    }
    // In the other case...
    else
    {
        // ...returning 52 (because the wished year contains 52 weeks)
        return 52;
    }
}

// Definition of the 'wished_wday_in_choosen_year' function to get the datetime of the nth choosen weekday in a choosen year
time_t wished_wday_in_choosen_year(int year, int wday, int number_of_weekday_in_the_year)
{
    // Definition of all needed variables
    time_t current_time = time(NULL);
    struct tm *fdy_dt;
    struct tm *ldy_dt;
    time_t fdy_time;
    time_t ldy_time;
    time_t calculous_result;

    // Initialization of the 'fdy_dt' variable which is the first day in the wished year
    fdy_dt = gmtime(&current_time);
    fdy_dt->tm_year = year - 1900;
    fdy_dt->tm_mon = 0;
    fdy_dt->tm_mday = 1;
    fdy_dt->tm_hour = 0;
    fdy_dt->tm_min = 0;
    fdy_dt->tm_sec = 0;

    //
    fdy_time = timegm(fdy_dt);
    fdy_dt = gmtime(&fdy_time);

    // In the case where the 'number_of_weekday_in_the_year' number is less than 1...
    if(number_of_weekday_in_the_year < 1)
    {
        //...so returning the error code 1
        return 1;
    }

    // In the case where the weekday of the first day in the wished year is not the 'wday' weekday...
    if(fdy_dt->tm_wday != wday)
    {
        //
        while(fdy_dt->tm_wday != wday)
        {
            //
            fdy_time = timegm(fdy_dt);
            fdy_time = fdy_time + day;
            fdy_dt = gmtime(&fdy_time);
        }
    }

    // In the case where the 'number_of_weekday_in_the_year' is equal to 1...
    if(number_of_weekday_in_the_year == 1)
    {
        //...so returning the first day in the year as a timestamp
        return fdy_time;
    }

    // Initialization of the 'ldy_dt' variable which is the last day in the wished year
    ldy_dt = gmtime(&current_time);
    ldy_dt->tm_year = year - 1900;
    ldy_dt->tm_mon = 11;
    ldy_dt->tm_mday = 31;
    ldy_dt->tm_hour = 0;
    ldy_dt->tm_min = 0;
    ldy_dt->tm_sec = 0;

    // Conversion of the 'ldy_dt' struct tm* value and put it in the 'ldy_time' time_t variable
    ldy_time = timegm(ldy_dt);

    // Definition of the weekday of the last day in the year
    ldy_dt = gmtime(&ldy_time);

    // Calculous of the wished datetime and put it in the 'calculous_result' variable
    calculous_result = fdy_time + (week * (number_of_weekday_in_the_year - 1));

    // In the case where the timestamp of the last day of the year is less than the 'calculous_result' value...
    if(ldy_time < calculous_result)
    {
        //...so returning the error code -1
        return -1;
    }

    // Returning the value of the 'calculous_result' which contains the wished value
    return calculous_result;
}

// Definition of the 'wished_number_in_year_is_day_in_choosen_year' function to get the corresponding day number in the year
int wished_number_in_year_is_day_in_choosen_year(int mday, int month, int year)
{
    //
    int i = 0;
    int condition;
    struct tm *date_tm;
    time_t date_timestamp;
    time_t today = time(NULL);

    //
    date_tm = gmtime(&today);

    //
    date_tm->tm_year = year;
    date_tm->tm_mon = 0;
    date_tm->mday = 1;
    date_tm->tm_hour = 0;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

    //
    while(condition)
    {
        //
        i = i + 1;

        //
        date_timestamp = timegm(date_tm);

        //
        date_timestamp = date_timestamp + day;

        //
        date_tm = gmtime(&date_timestamp);

        //
        condition = date_tm->tm_mday != mday && date_tm->tm_mon != month && date_tm->tm_year != year;
    }

    //
    return i;
}