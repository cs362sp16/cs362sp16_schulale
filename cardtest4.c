#include <stdio.h>
#include <string.h>
#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("Test failed: %s", failureMessage);
        }
}

//GREAT HALL UNIT TEST

int main(int argc, char** argv) {
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall, 
               sea_hag, tribute, steward};
        struct gameState state;
        struct gameState result;


        initializeGame(3, k, 1, &state);
        state.hand[0][0] = great_hall;
        memcpy(&result, &state, sizeof(struct gameState));
        playCard(0, 0, 0, 0, &result);

        test(result.numActions == state.numActions, 
                "Great Hall: Number of actions be equal after one incremented, and the one was used \n");
        test(result.handCount[0] == state.handCount[0],
                "Great Hall: Hand count should be the same after this card itself is out of the hand \n");
}
