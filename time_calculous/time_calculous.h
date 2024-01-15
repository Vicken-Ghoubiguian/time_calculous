#ifndef TIME_CALCULOUS
#define TIME_CALCULOUS

#include <time.h>

//
#define NB_SECONDS_IN_DAY 86400

// Defining the enumeration named "numeral" to specify which iteration of a week day in a month is requested
enum numeral {
    FIRST, //
    SECOND, //
    THIRD, //
    BEFORE_LAST, //
    LAST //
};

// Definition of the 'time_unit' enum to to list the number of seconds in each of the time units used
enum time_unit {
    second = 1,
    minute = 60,
    hour = 3600
};

//
struct time_diff {

    int years;
    int months;
    int days;
    int hours;
    int minutes;
    int seconds;
    
} time_diff;

// Definition of the array "weekDays" to contain all week days' names
static char* weekDays[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

// Definition of the array "months" to contain all months' names
static char* months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

//
time_t diffs_on_date_and_time(struct tm *first_dt, struct tm *second_dt);

// Definition of the 'calculations_on_date_and_time' to make calculations on datetimes
time_t calculations_on_date_and_time(struct tm *cdatetime, int decades, int years, int months, int weeks, int days, int hours, int minutes, int seconds);

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num);

#endif