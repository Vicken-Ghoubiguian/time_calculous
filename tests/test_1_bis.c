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
    int year = 2000;

    //
    printf("\n");

    //
    while(year <= 2100)
    {
        //
        printf("%s %d %s", BLUE, year, RESET);
        // ==========> display 'wished_wday_in_choosen_month' function's execution

        //
        printf("\n\n");

        //
        year++;
    }

    //
    printf("\n");

    //
    return 0;
}