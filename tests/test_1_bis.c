#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"

//
int main() {

    //
    int year = 2024;
    int month = 0;
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //
    printf("\n");

    //
    printf("%s %d %s", BLUE, year, RESET);

    //
     printf("\n\n");

    //
    while(month < 12)
    {
        //
        printf("%s %s %s", MAGENTA, months[month], RESET);
        // ==========> display 'wished_wday_in_choosen_month' function's execution

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