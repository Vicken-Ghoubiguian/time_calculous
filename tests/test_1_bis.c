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
#define BOLDRED "\[\033[0;31m\]"

//
int main() {

    //
    int year;
    int wday;
    int month = 0;
    char* months[] = {"January", "February", "March", "April", "May", 
"June", "July", "August", "September", "October", "November", "December"};
    char* weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    //
    printf("\n");

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &year);

    //
    printf("Please enter the weekday you want (0 : Sunday, 1 : Monday, 2 : Tuesday, 3 : Wednesday, 4 : Thursday, 5 : Friday, 6 : Saturday): ");
    scanf("%d", &wday);

    //
    printf("\n");

    //
    if(wday < 0 || wday > 6)
    {
	// ==========> Error : the weekday number you entered is not valid

	//
	return 1;
    }

    //
    printf("%s Year : %d %s\n", BOLDBLUE, year, RESET);
    printf("%s Weekday : %s %s", BOLDBLUE, weekdays[wday], RESET);

    //
    printf("\n\n");

    //
    while(month < 12)
    {
        //
        printf("%s Month : %s %s", BOLDMAGENTA, months[month], RESET);
        // ==========> display 'wished_wday_in_choosen_month' function's execution

        // To display top of the array
        printf("\n______________________________________________________________\n");
        printf("|             |%s first %s |%s second %s|%s third %s|%s before last %s|%s last %s|\n", BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET, BOLDYELLOW, RESET);
        printf("|_____________|________|________|_______|_____________|______|\n");

        //
        printf("\n");

        //
        month++;
    }

    //
    printf("\n");

    //
    return 0;
}
