#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"


void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", failureMessage);
        }
}

//STEWARD UNIT TEST

int main(int argc, char** argv) {
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
               sea_hag, tribute, steward};
        struct gameState state;
        struct gameState result;

        initializeGame(3, k, 1, &state);
        state.hand[0][0] = steward;
        memcpy(&result, &state, sizeof(struct gameState));
        playCard(0, 3, 1, 2, &result);

        test(result.handCount[0] == state.handCount[0] - 3, "Steward: Steward did not remove itself, and the two chosen cards \n");
}
