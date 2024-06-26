#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDRED "\033[0;31m"

// Initialisation of 'main' function
int main() {

    //
    int year;
    int wday;
    int month = 0;

    //
    time_t pre_first;
    time_t pre_second;
    time_t pre_third;
    time_t pre_before_last;
    time_t pre_last;

    //
    struct tm* first;
    struct tm* second;
    struct tm* third;
    struct tm* before_last;
    struct tm* last;

    //
    int mday_first;
    int mday_second;
    int mday_third;
    int mday_before_last;
    int mday_last;

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &year);

    // In the case where the wished year is less than 1900...
    if(year < 1900)
    {
        //...so display error in red...
        printf("\n%sErreur : l'année que vous avez renseigné n'est pas valide, celle-ci doit être supérieure ou égale à 1900 !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    //
    printf("Please enter the weekday you want (0 : Sunday, 1 : Monday, 2 : Tuesday, 3 : Wednesday, 4 : Thursday, 5 : Friday, 6 : Saturday): ");
    scanf("%d", &wday);

    //
    printf("\n");

    //
    if(wday < 0 || wday > 6)
    {
	//
	printf("%s", BOLDRED);

	//
        printf("Error : the weekday number you entered is not valid %s\n", RESET);

	//
	printf("\n");

	//
	return 1;
    }

    //
    printf("%s Year : %d %s\n", BOLDBLUE, year, RESET);
    printf("%s Weekday : %s %s", BOLDBLUE, weekDays[wday], RESET);

    //
    printf("\n\n");

    //
    while(month < 12)
    {
        //
        printf("%s Month : %s %s", BOLDMAGENTA, months[month], RESET);

	//
        pre_first = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, FIRST);
	first = gmtime(&pre_first);
        mday_first = first->tm_mday;
    	
	//
        pre_second = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, SECOND);
	second = gmtime(&pre_second);
        mday_second = second->tm_mday;
    	
	//
        pre_third = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, THIRD);
        third = gmtime(&pre_third);
        mday_third = third->tm_mday;

	//
        pre_before_last = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, BEFORE_LAST);
	before_last = gmtime(&pre_before_last);
	mday_before_last = before_last->tm_mday;

	//
	pre_last = wished_wday_in_choosen_month(year, month, wday, 0, 0, 0, LAST);
        last = gmtime(&pre_last);
        mday_last = last->tm_mday;

        // To display top of the array
        printf("\n________________________________________________\n");
        printf("|%s first %s |%s second %s|%s third %s|%s before last %s|%s last %s|\n", BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET);
        printf("|________|________|_______|_____________|______|\n");

	//
	printf("|     %d  |     %d  |     %d  |          %d  |    %d  |\n", mday_first, mday_second, mday_third, mday_before_last, mday_last);

	//
	printf("|________|________|_______|_____________|______|");

        //
        printf("\n\n");

        //
        month++;
    }

    //
    printf("\n");

    //
    return 0;
}
