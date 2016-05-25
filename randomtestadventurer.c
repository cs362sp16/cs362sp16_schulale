#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {

<<<<<<< HEAD
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
=======
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Adventurer Test\n");

	  /*
										--- Author's Note ---
<<<<<<< HEAD
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
=======
	  I had problems running out of memory when I used the same gameState variable more than 12 times, and
>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	  */

	  for (i = 0; i < MAX_TESTS; i++) {

	   players = rand() % 4;

	   seed = rand();		//pick random seed
<<<<<<< HEAD
		
	   initializeGame(players, k, seed, &state);	//initialize Gamestate 
=======

	   initializeGame(players, k, seed, &state);	//initialize Gamestate
>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e

	   //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &state);		//Run adventurer card
	  }
<<<<<<< HEAD
	  
=======

>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
<<<<<<< HEAD
		
=======

>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
		  initializeGame(players, k, seed, &stat);	//initialize Gamestate

		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			stat.deckCount[player] = 0;
		  }

		  cardEffect(adventurer, 1, 1, 1, &stat);		//Run adventurer card
	  }

	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
<<<<<<< HEAD
		
=======

>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
		  initializeGame(players, k, seed, &sta);	//initialize Gamestate

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			sta.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &sta);		//Run adventurer card

	   }

	  printf("Tests Complete\n");

	  return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 396f9d41a433172c34b16ad00e392780d271054e
