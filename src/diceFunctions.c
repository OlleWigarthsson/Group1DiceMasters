#include "headers.h"

//Function to print all dice values
void printDicePool(DicePool *pool){
	for(int i = 0;i<pool->numberOfDice;i++){
		printf("%d ", pool->dice[i].nrOnFace);
	}
	printf("\n");
}
void addDice(DicePool *pool) {
    pool->dice = realloc(pool->dice, (pool->numberOfDice + 1) * sizeof(Dice));
    Dice dice;
    dice.toRoll = 1;
    pool->dice[pool->numberOfDice++] = dice;
}

// Function to merge two dice pools
void mergePools(DicePool *pool1, DicePool pool2) {
	pool1->dice = realloc(pool1->dice, (pool1->numberOfDice + pool2.numberOfDice) * sizeof(Dice));
	for (int i = 0; i < pool2.numberOfDice; i++) {
		pool1->dice[pool1->numberOfDice + i] = pool2.dice[i];
	}
	pool1->numberOfDice += pool2.numberOfDice;
}

// Function to roll a single die
int rollDice() {
	return rand() % 6 + 1;
}

// Function to roll a dice pool
void rollPool(DicePool *pool) {
    for (int i = 0; i < pool->numberOfDice; i++) {
    	if(pool->dice[i].toRoll == 1){
    		pool->dice[i].nrOnFace = rollDice();
    	}
    }
}

//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice) {

	int sum = 0;

	for(int i = 0; i < numberOfDice; i++)
	{
		sum += diceArray[i].nrOnFace;
	}

	return sum;
}
void resetDiceThrows(DicePool* pool){
	for(int i = 0;i<pool->numberOfDice;i++){
		pool->dice[i].toRoll = 1;
	}
}

//Function to loop through Dicepool to count all values of dices
int subpoolOfDice(DicePool* pool, int faceValue)
{
	int counting;

	for (int i = 0; i < pool->numberOfDice; i++) {
		if (pool->dice[i].nrOnFace == faceValue)
			counting++;
	}
	return counting;
}

// A bubble sorting, from smallest to biggest
void soringSmallBig (DicePool *pool) {
    int i, j;
    Dice temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-1-i; j++) {
            if (pool->dice[j].nrOnFace > pool->dice[j+1].nrOnFace) {
                temp = pool->dice[j].nrOnFace;
                pool->dice[j].nrOnFace = pool->dice[j+1].nrOnFace;
                pool->dice[j+1].nrOnFace = temp;
            }
        }
    }
}

// A bubble sorting, from biggest to smallest
void sortingBigSmall(DicePool *pool) {
    int i, j;
    Dice temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-1-i; j++) {
            if (pool->dice[j].nrOnFace < pool->dice[j+1].nrOnFace) {
                temp = pool->dice[j].nrOnFace;
                pool->dice[j].nrOnFace = pool->dice[j+1].nrOnFace;
                pool->dice[j+1].nrOnFace = temp;
            }
        }
    }
}

// Funktion to see if we have a full house or not
int findFullHouse(DicePool* pool) {
	int Pair = 0;
	int threePair = 0;
	for (int i = 0; i < pool.numberOfDice - 2; i++) {
		for (int j = i + 1; j < pool.numberOfDice -1; j++) {
			for (int k = j + 1; k < pool.numberOfDice; k++) {
				if (pool.dice[i] == pool.dice[j] == pool.dice[k]) {
					if (pool.dice[i] >= threePair) {
						Pair = threePair;
						threePair = pool.dice[i];
					} else if (pool.dice[i] >= Pair) {
						Pair = pool.dice[i];
					}
				}
			}
		}
		if (Pair == 0) {
			return 0;
		} else {
			return threePair + Pair;
		}
	}
	/
	return findFullHouse;
}

