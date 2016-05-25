#include <stdio.h>
#include <string.h>
#include "dominion.h"

void test(int cond, char* messageFailure) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", messageFailure);
        }
}

//OUTPOST UNIT TEST

int main(int argc, char** argv) {
        int k[10] = {adventurer, gardens, outpost, village, minion, mine, cutpurse, 
               sea_hag, tribute, steward};
        struct gameState previous;
        struct gameState result;

        initializeGame(3, k, 1, &previous);
        previous.hand[0][0] = outpost;
        memcpy(&result, &previous, sizeof(struct gameState));
        playCard(0, 0, 0, 0, &result);
        test(result.outpostPlayed == 1, "Outpost, Turn changed to another player erronousely\n");
        test(result.handCount[0] == 3, "Outpost, Did not draw correct number of cards after outpost played\n");

}
