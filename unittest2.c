#include <stdio.h>
#include <string.h>

#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", failureMessage);
        }
}

//UNIT TEST numHandCards

int main(int argc, char** argv) {
        struct gameState state;
        int result;
        state.numPlayers = 3;
        state.whoseTurn = 2;
        state.handCount[2] = 5;

        result = numHandCards(&state);
        test(result == 5, "numHandCards returned incorrect value \n");
}


