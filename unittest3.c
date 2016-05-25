#include <stdio.h>
#include <string.h>
#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", failureMessage);
        }
}

//UNIT TEST buyCard

int main(int argc, char** argv) {
        struct gameState state;
        int result;
        state.numPlayers = 5;
        state.whoseTurn = 4;
        state.coins = 50;
        state.supplyCount[adventurer] = 1;
        state.numBuys = 1;

        buyCard(adventurer, &state);

        result = numHandCards(&state);

        test(state.coins == 44, "buyCard did not decrement coins correctly \n");
        test(state.supplyCount[adventurer] == 0, "buyCard did not decrement supply count correctly \n");
        test(state.discard[4][0] == adventurer, "buyCard did not place card in discard correctly \n");
        test(state.numBuys == 0, "buyCard did not decrement numBuys \n");
}
