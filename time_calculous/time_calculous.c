#include <time.h>
#include "time_calculous.h"

//
struct time_diff diffs_on_date_and_time(struct tm *first_dt, struct tm *second_dt)
{
    // Definition of all needed variables
    time_t first_dt_timestamp;
    time_t second_dt_timestamp;
    time_t calculation_result;
    struct time_diff td;
    int diff_calc;

    // Conversion of the 'first_dt' and the 'second_dt' struct tm values to the 'first_dt_timestamp' and the 'second_dt_timestamp' timestamp value
    first_dt_timestamp = timegm(first_dt);
    second_dt_timestamp = timegm(second_dt);

    // 
    calculation_result = first_dt_timestamp - second_dt_timestamp;

    // In the case where the 'calculation_result' value is less than 0
    if(calculation_result < 0)
    {
        //
        td.millenniums = -1;
        td.centuries = -1;
        td.decades = -1;
        td.years = -1;
        td.months = -1;
        td.weeks = -1;
        td.days = -1;
        td.hours = -1;
        td.minutes = -1;
        td.seconds = -1;

        // Returning the error code (which is -1) as a 'td' struct time_diff
        return td;
    }

    //
    diff_calc = calculation_result / millennium;
    if(diff_calc > 0)
    {
        td.millenniums = diff_calc;
        calculation_result = calculation_result % millennium;
    }

    //
    diff_calc = calculation_result / century;
    if(diff_calc > 0)
    {
        td.centuries = diff_calc;
        calculation_result = calculation_result % century;
    }

    //
    diff_calc = calculation_result / decade;
    if(diff_calc > 0)
    {
        td.decades = diff_calc;
        calculation_result = calculation_result % decade;
    }

    //
    diff_calc = calculation_result / year;
    if(diff_calc > 0)
    {
        td.years = diff_calc;
        calculation_result = calculation_result % year;
    }

    //
    diff_calc = calculation_result / month;
    if(diff_calc > 0)
    {
        td.months = diff_calc;
        calculation_result = calculation_result % month;
    }

    //
    diff_calc = calculation_result / week;
    if(diff_calc > 0)
    {
        td.weeks = diff_calc;
        calculation_result = calculation_result % week;
    }

    //
    diff_calc = calculation_result / day;
    if(diff_calc > 0)
    {
        td.days = diff_calc;
        calculation_result = calculation_result % day;
    }

    //
    diff_calc = calculation_result / hour;
    if(diff_calc > 0)
    {
        td.hours = diff_calc;
        calculation_result = calculation_result % hour;
    }

    //
    diff_calc = calculation_result / minute;
    if(diff_calc > 0)
    {
        td.minutes = diff_calc;
        calculation_result = calculation_result % minute;
    }

    // Adding the resulting seconds in the 'seconds' field of the 'td' struct time_diff
    td.seconds = calculation_result;

    // Returning the result of calculation as a 'td' struct time_diff
    return td;
}

// Definition of the 'calculations_on_date_and_time' to make calculations on datetimes
time_t calculations_on_date_and_time(time_t datetime_as_timestamp, int millennials, int centuries, int decades, int years, int months, int weeks, int days, int hours, int minutes, int seconds)
{
    // Definition of all needed variables
    time_t cdatetime_timestamp;
    struct tm *cdatetime = gmtime(&datetime_as_timestamp);
    long long int datetime_calculation;
    time_t min_time = -2208988800;

    // If the number of centuries is positive (to want to add centuries)...
    if(centuries >= 0)
    {
        // As long as the wished number of centuries is greater than or equal to 10, so...
        while(centuries >= 10)
        {
            //
            if(centuries >= 10){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(centuries,10); centuries = centuries % 10; }
        }
    }
    // In the other case (to want to remove centuries)...
    else
    {
        // As long as the wished number of centuries is less than or equal to -10, so...
        while(centuries <= -10)
        {
            //
            if(centuries <= -10){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(centuries,10); centuries = (-1 * centuries) % 10; centuries = -1 * centuries; }
        }
    }

    // If the number of decades is positive (to want to add decades)...
    if(decades >= 0)
    {
        // As long as the wished number of decades is greater than or equal to 10, so...
        while(decades >= 10)
        {
            //
            if(decades >= 100){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(decades,100); decades = decades % 100; }
            if(decades >= 10 && decades <= 99){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(decades,10); decades = decades % 10; }
        }
    }
    // In the other case (to want to remove decades)...
    else
    {
        // As long as the wished number of decades is less than or equal to -10, so...
        while(decades <= -10)
        {
            //
            if(decades <= -100){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(decades,100); decades = (-1 * decades) % 100; decades = -1 * decades; }
            if(decades <= -10 && decades >= -99){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(decades,10); decades = (-1 * decades) % 10; decades = -1 * decades; }
        }
    }

    // If the number of years is positive (to want to add years)...
    if(years >= 0)
    {
        // As long as the wished number of years is greater than or equal to 10, so...
        while(years >= 10)
        {
            //
            if(years >= 1000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(years,1000); years = years % 1000; }
            if(years >= 100 && years <= 999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(years,100); years = years % 100; }
            if(years >= 10 && years <= 99){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(years,10); years = years % 10; }
        }
    }
    // In the other case (to want to remove years)...
    else
    {
        // As long as the wished number of years is less than or equal to -10, so...
        while(years <= -10)
        {
            //
            if(years <= -1000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(years,1000); years = (-1 * years) % 1000; years = -1 * years; }
            if(years <= -100 && years >= -999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(years,100); years = (-1 * years) % 100; years = -1 * years; }
            if(years <= -10 && years >= -99){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(years,10); years = (-1 * years) % 10; years = -1 * years; }
        }
    }

    // If the number of months is positive (to want to add months)...
    if(months >= 0)
    {
        // As long as the wished number of months is greater than or equal to 12, so...
        while(months >= 12)
        {
            //
            if(months >= 12000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(months,12000); months = months % 12000; }
            if(months >= 1200 && months <= 11999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(months,1200); months = months % 1200; }
            if(months >= 120 && months <= 1199){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(months,120); months = months % 120; }
            if(months >= 12 && months <= 119){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(months,12); months = months % 12; }
        }
    }
    // In the other case (to want to remove months)...
    else
    {
        // As long as the desired number of months is less than or equal to -12, then...
        while(months <= -12)
        {
            //
            if(months <= -12000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(months,12000); months = (-1 * months) % 12000; months = -1 * months; }
            if(months <= -1200 && months >= -11999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(months,1200); months = (-1 * months) % 1200; months = -1 * months; }
            if(months <= -120 && months >= -1199){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(months,120); months = (-1 * months) % 120; months = -1 * months; }
            if(months <= -12 && months >= -119){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(months,12); months = (-1 * months) % 12; months = -1 * months; }
        }
    }

    // weeks
    /*if(weeks >= 0)
    {
        //
        while(weeks <= 4)
        {
            //
            if(){}
            if(){}
            if(){}
            if(){}
            if(){}
        }
    }
    //
    else
    {
        
    }*/

    // days
    // ==================
    // example : 366 days % 365 + leap year = 1 year OR 366 % 365 + not leap year = 1 year (366 / 365 = 1.00273972603) + 1 day (366 % 365 = 1)
    // ==================
    
    // days
    /*
    if(days >= 0)
    {

    }
    //
    else
    {

    }
    */

    // If the number of hours is positive (to want to add hours)...
    if(hours >= 0)
    {
        // As long as the wished number of hours is greater than or equal to 24, so...
        while(hours >= 24)
        {
            //
            if(hours >= 8760000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(hours,8760000); hours = hours % 8760000; }
            if(hours >= 8756000 && hours <= 8759999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(hours,8756000); hours = hours % 8756000; }
            if(hours >= 875600 && hours <= 8755999){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(hours,875600); hours = hours % 875600; }
            if(hours >= 8760 && hours <= 875599){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(hours,8760); hours = hours % 8760; }
            if(hours >= 730 && hours <= 8759){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(hours,730); hours = hours % 730; }
            if(hours >= 168 && hours <= 729){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(hours,168); hours = hours % 168; }
            if(hours >= 24 && hours <= 167){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(hours,24); hours = hours % 24; }
        }
    }
    // In the other case (to want to remove hours)...
    else
    {
        // As long as the wished number of hours is less than or equal to -24, so...
        while(hours <= -24)
        {
            //
            if(hours <= -8760000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(hours,8760000); hours = (-1 * hours) % 8760000; hours = -1 * hours; }
            if(hours <= -8756000 && hours >= -8759999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(hours,8756000); hours = (-1 * hours) % 8756000; hours = -1 * hours; }
            if(hours <= -875600 && hours >= -8755999){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(hours,875600); hours = (-1 * hours) % 875600; hours = -1 * hours; }
            if(hours <= -8760 && hours >= -875599){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(hours,8760); hours = (-1 * hours) % 8760; hours = -1 * hours; }
            if(hours <= -730 && hours >= -8759){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(hours,730); hours = (-1 * hours) % 730; hours = -1 * hours; }
            if(hours <= -168 && hours >= -729){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(hours,168); hours = (-1 * hours) % 168; hours = -1 * hours; }
            if(hours <= -24 && hours >= -167){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(hours,24); hours = (-1 * hours) % 24; hours = -1 * hours; }
        }
    }

    // If the number of minutes is positive (to want to add minutes)...
    if(minutes >= 0)
    {
        // As long as the wished number of minutes is greater than or equal to 60, so...
        while(minutes >= 60)
        {
            //
            if(minutes >= 525600000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(minutes,525600000); minutes = minutes % 525600000; }
            if(minutes >= 52560000 && minutes <= 525599999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(minutes,52560000); minutes = minutes % 52560000; }
            if(minutes >= 5256000 && minutes <= 52559999){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(minutes,5256000); minutes = minutes % 5256000; }
            if(minutes >= 525600 && minutes <= 5255999){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(minutes,525600); minutes = minutes % 525600; }
            if(minutes >= 43800 && minutes <= 525599){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(minutes,43800); minutes = minutes % 43800; }
            if(minutes >= 10080 && minutes <= 43799){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(minutes,10080); minutes = minutes % 10080; }
            if(minutes >= 1440 && minutes <= 10079){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(minutes,1440); minutes = minutes % 1440; }
            if(minutes >= 60 && minutes <= 1439){ hours = hours + (int)DIV_FOR_TIME_CALCULATIONS(minutes,60); minutes = minutes % 60; }
        }
    }
    // In the other case (to want to remove minutes)...
    else
    {
        // As long as the wished number of minutes is less than or equal to -60, so...
        while(minutes <= -60)
        {
            //
            if(minutes <= -525600000){ millennials = millennials + (int)DIV_FOR_TIME_CALCULATIONS(minutes,525600000); minutes = (-1 * minutes) % 525600000; minutes = -1 * minutes; }
            if(minutes <= -52560000 && minutes >= -525599999){ centuries = centuries + (int)DIV_FOR_TIME_CALCULATIONS(minutes,52560000); minutes = (-1 * minutes) % 52560000; minutes = -1 * minutes; }
            if(minutes <= -5256000 && minutes >= -52559999){ decades = decades + (int)DIV_FOR_TIME_CALCULATIONS(minutes,5256000); minutes = (-1 * minutes) % 5256000; minutes = -1 * minutes; }
            if(minutes <= -525600 && minutes >= -5255999){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(minutes,525600); minutes = (-1 * minutes) % 525600; minutes = -1 * minutes; }
            if(minutes <= -43800 && minutes >= -525599){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(minutes,43800); minutes = (-1 * minutes) % 43800; minutes = -1 * minutes; }
            if(minutes <= -10080 && minutes >= -43799){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(minutes,10080); minutes = (-1 * minutes) % 10080; minutes = -1 * minutes; }
            if(minutes <= -1440 && minutes >= -10079){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(minutes,1440); minutes = (-1 * minutes) % 1440; minutes = -1 * minutes; }
            if(minutes <= -60 && minutes >= -1439){ hours = hours + (int)DIV_FOR_TIME_CALCULATIONS(minutes,60); minutes = (-1 * minutes) % 60; minutes = -1 * minutes; }
        }
    }

    // If the number of seconds is positive (to want to add seconds)...
    if(seconds >= 0)
    {
        // As long as the wished number of seconds is greater than or equal to 60, so...
        while(seconds >= 60)
        {
            //
            if((long long int)seconds >= 31536000000){ millennials = millennials + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,31536000000); seconds = seconds % 31536000000; }
            if((long long int)seconds >= 3153600000 && (long long int)seconds <= 31535999999){ centuries = centuries + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,3153600000); seconds = seconds % 3153600000; }
            if((long long int)seconds >= 315360000 && (long long int)seconds <= 3153599999){ decades = decades + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,315360000); seconds = seconds % 315360000; }
            if(seconds >= 31536000 && seconds <= 315359999){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(seconds,31536000); seconds = seconds % 31536000; }
            if(seconds >= 2629800 && seconds <= 31535999){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(seconds,2629800); seconds = seconds % 2629800; }
            if(seconds >= 604800 && seconds <= 2629799){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(seconds,604800); seconds = seconds % 604800; }
            if(seconds >= 86400 && seconds <= 604799){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(seconds,86400); seconds = seconds % 86400; }
            if(seconds >= 3600 && seconds <= 86399){ hours = hours + (int)DIV_FOR_TIME_CALCULATIONS(seconds,3600); seconds = seconds % 3600; }
            if(seconds >= 60 && seconds <= 3599){ minutes = minutes + (int)DIV_FOR_TIME_CALCULATIONS(seconds,60); seconds = seconds % 60; }
        }
    }
    // In the other case (to want to remove seconds)...
    else
    {
        // As long as the wished number of seconds is less than or equal to -60, so...
        while(seconds <= -60)
        {
            //
            if((long long int)seconds <= -31536000000){ millennials = millennials + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,31536000000); seconds = (-1 * seconds) % 31536000000; seconds = -1 * seconds; }
            if((long long int)seconds <= -3153600000 && (long long int)seconds >= -31535999999){ centuries = centuries + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,3153600000); seconds = (-1 * seconds) % 3153600000; seconds = -1 * seconds; }
            if((long long int)seconds <= -315360000 && (long long int)seconds >= -3153599999){ decades = decades + (long long int)DIV_FOR_TIME_CALCULATIONS(seconds,315360000); seconds = (-1 * seconds) % 315360000; seconds = -1 * seconds; }
            if(seconds <= -31536000 && seconds >= -315359999){ years = years + (int)DIV_FOR_TIME_CALCULATIONS(seconds,31536000); seconds = (-1 * seconds) % 31536000; seconds = -1 * seconds; }
            if(seconds <= -2629800 && seconds >= -31535999){ months = months + (int)DIV_FOR_TIME_CALCULATIONS(seconds,2629800); seconds = (-1 * seconds) % 2629800; seconds = -1 * seconds; }
            if(seconds <= -604800 && seconds >= -2629799){ weeks = weeks + (int)DIV_FOR_TIME_CALCULATIONS(seconds,604800); seconds = (-1 * seconds) % 604800; seconds = -1 * seconds; }
            if(seconds <= -86400 && seconds >= -604799){ days = days + (int)DIV_FOR_TIME_CALCULATIONS(seconds,86400); seconds = (-1 * seconds) % 86400; seconds = -1 * seconds; }
            if(seconds <= -3600 && seconds >= -86399){ hours = hours + (int)DIV_FOR_TIME_CALCULATIONS(seconds,3600); seconds = (-1 * seconds) % 3600; seconds = -1 * seconds; }
            if(seconds <= -60 && seconds >= -3599){ minutes = minutes + (int)DIV_FOR_TIME_CALCULATIONS(seconds,60); seconds = (-1 * seconds) % 60; seconds = -1 * seconds; }
        }
    }

    // Calculation and definition of the year
    cdatetime->tm_year = cdatetime->tm_year + ((millennials * 1000) + (centuries * 100) + (decades * 10) + years);

    // Calculation and definition of the month
    cdatetime->tm_mon = (cdatetime->tm_mon + months) % 12;

    // Conversion of the 'cdatetime' struct tm value to the 'cdatetime_timestamp' timestamp value
    cdatetime_timestamp = timegm(cdatetime);

    // Calculation of all weeks, days, hours, minutes, and seconds and affectation of the result to the 'datetime_calculation' variable
    datetime_calculation = week * weeks + day * days + hour * hours + minute * minutes + second * seconds;

    // Adding the 'datetime_calculation' value to the 'cdatetime_timestamp' one and affectation to the 'cdatetime_timestamp' variable
    cdatetime_timestamp = cdatetime_timestamp + datetime_calculation;

    // If the calculation result, in the 'cdatetime_timestamp' variable, is less than the date and time of January 1 1900 00:00:00 as a timestamp...
    if(cdatetime_timestamp < min_time)
    {
        // ...so returning the error code -1...
        return -1;
    }
    // ...or otherwise...
    else
    {
        // ...returning the calculation result
        return cdatetime_timestamp;
    }
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
    // Definition of all needed variables
    int i = 1;
    int condition;
    struct tm *date_tm;
    time_t date_timestamp;
    time_t today = time(NULL);

    // Initialization of the 'date_tm' variable to now date and time
    date_tm = gmtime(&today);

    // Initialization of the 'date_tm' variable as the first day in the wished year
    date_tm->tm_year = year;
    date_tm->tm_mon = 0;
    date_tm->tm_mday = 1;
    date_tm->tm_hour = 0;
    date_tm->tm_min = 0;
    date_tm->tm_sec = 0;

    //
    if(date_tm->tm_mday == mday && date_tm->tm_mon == month && date_tm->tm_year == year)
    {
        //...so returning 1
        return 1;
    }

    //
    while(date_tm->tm_mday != mday || date_tm->tm_mon != month || date_tm->tm_year != year)
    {
        //
        i = i + 1;

        //
        date_timestamp = timegm(date_tm);

        //
        date_timestamp = date_timestamp + day;

        //
        date_tm = gmtime(&date_timestamp);
    }

    //...so returning 'i' as the result
    return i;
}

// Definition of the 'number_of_days_in_choosen_month_in_choosen_year' function to get the number of days in a choosen month in a choosen year
int number_of_days_in_choosen_month_in_choosen_year(int month, int year)
{
    // Determine if the wished year is a leap year or not
    int is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0);

    // Allow the value of the choosen month so...
    switch(month)
    {
        case 0 : return 31; //...31 days in January
        case 1 : if(is_leap_year){ return 29; }else{ return 28; } //...29 if the wished year is leap or 28 if not 
        case 2 : return 31; //...31 days in march
        case 3 : return 30; //...30 days in april
        case 4 : return 31; //...31 days in may
        case 5 : return 30; //...30 days in june
        case 6 : return 31; //...31 days in july
        case 7 : return 31; //...31 days in august
        case 8 : return 30; //...30 days in september
        case 9 : return 31; //...31 days in october
        case 10 : return 30; //...30 days in november
        case 11 : return 31; //...30 days in december
        default : return -1; //...the error code -1 in all other cases
    }
}