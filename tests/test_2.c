#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
#include "../time_calculous/time_calculous.h"

//
int main() {

    //
    time_t today = time(NULL);
    time_t calculations_results = calculations_on_date_and_time(gmtime(&today), week);

    //
    printf("%s", asctime(gmtime(&calculations_results)));

    //
    return 0;
}