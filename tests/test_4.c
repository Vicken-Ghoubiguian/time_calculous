#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Definition of colors constants
#define RESET "\033[0m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDMAGENTA "\033[1m\033[35m"

// Initialisation of 'main' function
int main() {

	// Definition of all needed variables
    int year;
    int wday;
	int wished_number;
	time_t nth_weekday_in_the_year;

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

	//
    printf("Veuillez entrer le jour de la semaine que vous voulez [de 0 à 6] : ");
    scanf("%d", &wday);

    //
    if(wday < 0 || wday > 6)
    {
        //
        printf("\n%sErreur : le jour de la semaine que vous avez renseigné n'est pas valide !%s\n\n", BOLDRED, RESET);

        //...and return -1 error code
        return -1;
    }

	//
	printf("Veuillez entrer le numéro que vous voulez dans l'année : ");
    scanf("%d", &wished_number);

	// Breaking line instruction
    printf("\n");

	//
    nth_weekday_in_the_year = wished_wday_in_choosen_year(year, wday, wished_number);

	//
	if(nth_weekday_in_the_year == -1)
	{
		//
		printf("%sError : the resulting date is greater than the last date of the chosen year%s\n\n", BOLDRED, RESET);

		//...and return -1 error code
        return -1;
	}
	//
	else if(nth_weekday_in_the_year == 1)
	{
		//
		printf("%sError : you cannot demand a number of the wished weekday in the wished year less than 1%s\n\n", BOLDRED, RESET);

		//...and return -1 error code
        return -1;
	}
	//
	else
	{
		//
		printf("%s%dth %s of the year %d : %s%s\n", BOLDMAGENTA, wished_number, weekDays[wday], year, asctime(gmtime(&nth_weekday_in_the_year)), RESET);

		//...and return -1 error code
        return -1;
	}

	return 0;
}