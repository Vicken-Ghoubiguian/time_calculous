#ifndef TIME_CALCULOUS
#define TIME_CALCULOUS

#include <time.h>

//
#define NB_SECONDS_IN_DAY 86400

//
enum numeral {
    FIRST, //
    /*SECOND, //
    THIRD, //
    BEFORE_LAST,*/ //
    LAST //
};

//
enum time_unit {
    minute = 60,
    hour = 3600,
    day = 86400,
    week = 604800
};

//
time_t calculations_on_date_and_time(struct tm *cdatetime, int tmst);

//
time_t wished_wday_in_choosen_month(int year, int month, int wday, int hour, int minute, int second, enum numeral num);

#endif