#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"

// Initialisation of 'main' function
int main() {

    // Definition of all needed variables
    int year;
    int month;
    int mday;

    // To enter the wished year
    printf("Veuillez entrer l'année que vous voulez : ");
    scanf("%d", &year);

    // To enter the wished month
    printf("Veuillez entrer le mois que vous voulez [de 0 à 11] : ");
    scanf("%d", &month);

    //
    if(month < 0 || month > 11)
    {
        //
        printf("\n%sErreur : le mois de l'année que vous avez renseigné n'est pas valide !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }

    //
    printf("Veuillez entrer le jour du mois que vous voulez : ");
    scanf("%d", &mday);

    //
    /*if(wday < 0 || wday > 6)
    {
        //
        printf("\n%sErreur : le jour de la semaine que vous avez renseigné n'est pas valide !%s\n\n", BOLDRED, RESET);

        //
        return -1;
    }*/

    // Breaking line instruction
    printf("\n");

    //
    int n = wished_number_in_year_is_day_in_choosen_year(mday, month, year);

    //
    printf("%d\n\n", n);

    //
    return 0;

};