#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to add a dice to a dice pool
void addDice(DicePool *pool, Dice dice) {
    pool->dice = realloc(pool->dice, (pool->numberOfDice + 1) * sizeof(Dice));
    pool->dice[pool->numberOfDice] = dice;
    pool->numberOfDice++;
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
        pool->dice[i].nrOnFace = rollDice();
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

//Looking for highest 3 of same kind and returns if found, else return 0
DicePool* findHighestThreeOfSame(DicePool *pool)
{
	int countNrOnFace[6] = {0};

	// Counting nr of each kind (1-6)
	for (int i = 0; i < pool->numberOfDice; i++)
	{
		countNrOnFace[pool->dice[i].nrOnFace-1]++;
	}

	//Finding value on the dice with 3 same
	int faceValueof3Same = 0;
	for (int i = 0; i < 6; i++)
	{
		if(countNrOnFace[i] >= 3)
			faceValueof3Same = i+1;
	}

	DicePool *subPool = malloc(sizeof(DicePool));
	subPool->numberOfDice = 3;

	// Check if value is x and store sub-pool
	int foundCount = 0;
	//subPool->dice = malloc(sizeof(Dice) * subPool->numberOfDice);
	for (int i = 0; i < pool->numberOfDice && foundCount < 3; i++)
	{
	    if (pool->dice[i].nrOnFace == faceValueof3Same)
	    {
	        subPool->dice[foundCount++] = pool->dice[i];

	    }
	}

	if (foundCount == 3)
	{
	    return subPool;
	}
	else
	{
	    //free(subPool->dice); // Free allocated memory for dice array
	    free(subPool); // Free allocated memory for sub-pool
	    return NULL;
	}
}
