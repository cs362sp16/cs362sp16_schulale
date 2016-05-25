#include <stdio.h>
#include <string.h>
#include "dominion.h"

void test(int cond, char* failureMessage) {
        if (!cond) {
                printf("TESTING: FAILED --  %s", failureMessage);
        }
}

//SEA HAG UNIT TEST

int main(int argc, char** argv) {
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, great_hall, 
               sea_hag, tribute, steward};
        struct gameState state;
        struct gameState result;
        int allPlayersAffected = 1;
        int i;
        int j;

        initializeGame(3, k, 1, &state);
        state.hand[0][0] = sea_hag;
        memcpy(&result, &state, sizeof(struct gameState));
        playCard(0, 0, 0, 0, &result);

        for (i = 1; i < result.numPlayers; i++)
        {
                if (DEBUG) {
                        printf("Player %d before count %d \n", i, state.deckCount[i]);
                        printf("Player %d deck count %d \n", i, result.deckCount[i]);
                        printf("Player %d top card %d \n", i, result.deck[i][result.deckCount[i] - 1]);
                

                for(j = 0; j < result.deckCount[i]; j++) {
                        printf("%d ", result.deck[i][j]);
                }

                printf("\n");
                }

                if (result.deckCount[i] != state.deckCount[i] ||
                        result.deck[i][result.deckCount[i] - 1] != curse) {
                        allPlayersAffected = 0;
                }
        }

        test(allPlayersAffected, "Sea Hag: Not every player had a curse placed on top of their deck \n");


}
