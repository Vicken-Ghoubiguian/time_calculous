#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
#include "../time_calculous/time_calculous.h"

int main() {

	//
    time_t test = wished_wday_in_choosen_year(2024, 0, 52);

	//
	printf("%ld\n", test);

	return 0;
}