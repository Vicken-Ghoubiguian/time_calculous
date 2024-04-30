#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

// Initialisation of 'main' function
int main() {

    // Definition of all needed variables
    int year;
    int month;
    int mday;
    int number_of_day_in_year;
    int number_of_days_in_choosen_month;

    // To enter the wished year
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    // In the case where the wished year is less than 1900...
    if(year < 1900)
    {
        //...so display error in red...
        printf("\n%sErreur : l'année que vous avez renseigné n'est pas valide, celle-ci doit être supérieure ou égale à 1900 !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // To enter the wished month
    printf("Veuillez entrer le mois que vous voulez [de 0 à 11] : ");
    scanf("%d", &month);

    //
    if(month < 0 || month > 11)
    {
        //
        printf("\n%sErreur : le mois de l'année que vous avez renseigné n'est pas valide !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    //
    printf("Veuillez entrer le jour du mois que vous voulez : ");
    scanf("%d", &mday);

    //
    if(mday < 0 || mday > number_of_days_in_choosen_month_in_choosen_year(month, year))
    {
        //
        printf("\n%sErreur : le numéro de jour dans le mois renseigné n'est pas valide !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

    // Breaking line instruction
    printf("\n");

    //
    number_of_day_in_year = wished_number_in_year_is_day_in_choosen_year(mday, month, year);

    //
    printf("%sLe numéro du jour demandé dans l'année demandée : %d%s\n\n", BOLDGREEN, number_of_day_in_year, RESET);

    //
    return 0;
};