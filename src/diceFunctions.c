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
