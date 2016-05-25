#include <stdio.h>
#include <string.h>

#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED -- %s", failureMessage);
        }
}

//UNIT TEST handCard

int main(int argc, char** argv) {
        struct gameState state;
        int result;
        int testHand[2] = { adventurer, baron };
        state.numPlayers = 3;
        state.whoseTurn = 1;
        state.handCount[1] = 2;
        memcpy(state.hand[1], testHand, 2);

        result = handCard(0, &state);
        test(result == adventurer, "handCard returned incorrect value \n");
}

