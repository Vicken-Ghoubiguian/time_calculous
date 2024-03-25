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
    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //
    printf("\n");

    // To enter the wished year
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    //
    printf("\n");

    //
    printf("%s %d %s", BOLDBLUE, year, RESET);

    //
    printf("\n\n");

    //
    while(month < 12)
    {
        //
        printf("%s %s %s", BOLDMAGENTA, months[month], RESET);
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