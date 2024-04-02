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

//
int main() {

    //
    int year;
    int month = 0;
    char* months[] = {"January", "February", "March", "April", "May", 
"June", "July", "August", "September", "October", "November", "December"};

    //
    printf("\n");

    // To enter the wished year
    printf("Please enter the year you want : ");
    scanf("%d", &year);

    //
    printf("\n");

    //
    printf("%s Year : %d %s", BOLDBLUE, year, RESET);

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
