#include <stdio.h>
#include <string.h>

#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", failureMessage);
        }
}

//UNIT TEST supplyCount

int main(int argc, char** argv) {
        struct gameState state;
        int result;
        state.supplyCount[baron] = 3;

        result = supplyCount(baron, &state);
        test(result == 3, "supplyCount returned incorrect value \n");
}

