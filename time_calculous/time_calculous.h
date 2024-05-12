#include <time.h>

// Definition of the 'DIV_FOR_TIME_CALCULATIONS' function as a macro to be directly call in the 'calculations_on_times' types functions
#define DIV_FOR_TIME_CALCULATIONS(x,y) { x/y }

// Defining the enumeration named "numeral" to specify which iteration of a week day in a month is requested
enum numeral {
    FIRST, // First iteration of a week day in a month
    SECOND, // Second iteration of a week day in a month
    THIRD, // Third iteration of a week day in a month
    BEFORE_LAST, // Penultimate iteration of a week day in a month
    LAST // Last iteration of a week day in a month
};

// Definition of the 'time_unit' enum to to list the number of seconds in each of the time units used
enum time_unit {
    second = 1, // definition of a second
    minute = 60, // definition of a minute as 60 seconds
    hour = 3600, // definition of an hour as 3600 seconds
    day = 86400, // definition of a day as 86400 seconds
    week = 604800, // definition of a week as 604800 seconds
    month = 2629800, // definition of a month as 2629800 seconds
    year = 31536000, // definition of a year as 31536000 seconds
    decade = 315360000, // definition of a decade as 315360000 seconds
    century = 3153600000, // definition of a century as 3153600000 seconds
    millennium = 31536000000 // definition of a millennium as 31536000000 seconds
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
static char* weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Definition of the array "months" to contain all months' names
static char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Definition of 'diffs_on_date_and_time' which returns, as timestamp, the difference between 2 datetimes as timestamps
time_t diffs_on_date_and_time(struct tm *first_dt, struct tm *second_dt);

// Definition of the 'calculations_on_date_and_time_from_today' to make calculations on datetimes
time_t calculations_on_date_and_time_from_today(int millenniums, int centuries, int decades, int years, int months, int weeks, int days, int hours, int minutes, int seconds);

// Definition of the 'wished_wday_in_choosen_month' function to get the date of the wished week day in the wished month and the wished year
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num);

// Definition of the 'number_of_weeks_in_a_year_according_to_the_iso_norm' function to determine how many weeks there are in the year according iso norm
int number_of_weeks_in_a_year_according_to_the_iso_norm(int year);

// Definition of the 'wished_wday_in_choosen_year' function to get the nth choosen weekday in a choosen year
time_t wished_wday_in_choosen_year(int year, int wday, int number_of_weekday_in_the_year);

// Definition of the 'wished_number_in_year_is_day_in_choosen_year' function to get the corresponding day number in the year
int wished_number_in_year_is_day_in_choosen_year(int mday, int month, int year);

// Definition of the 'number_of_days_in_choosen_month_in_choosen_year' function to get the number of days in a choosen month in a choosen year
int number_of_days_in_choosen_month_in_choosen_year(int month, int year);