#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importation of the 'time_calculous' library
#include "../time_calculous/time_calculous.h"

// Initialisation of 'main' function
int main() {

    //
    struct time_diff td = diffs_on_date_and_time(1718034676, 1717948266);

    //
    printf("\n");

    //
    print_time_diff(td);

    //
    printf("\n");

    //
    return 0;
}