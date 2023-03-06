
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to add a dice to a dice pool
void addDice(DicePool *pool, Dice dice) {
    pool->dice = realloc(pool->dice, (pool->numDice + 1) * sizeof(Dice));
    pool->dice[pool->numDice] = dice;
    pool->numDice++;
}

// Function to merge two dice pools
void mergePools(DicePool *pool1, DicePool pool2) {
    pool1->dice = realloc(pool1->dice, (pool1->numDice + pool2.numDice) * sizeof(Dice));
    for (int i = 0; i < pool2.numDice; i++) {
        pool1->dice[pool1->numDice + i] = pool2.dice[i];
    }
    pool1->numDice += pool2.numDice;
}

// Function to roll a single die
int rollDice() {
    return rand() % 6 + 1;
}

// Function to roll a dice pool
void rollPool(DicePool *pool) {
    for (int i = 0; i < pool->numDice; i++) {
        pool->dice[i].value = rollDice();
    }
}

//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice) {
	
	int sum = 0;
	
	for(int i = 0; i < numberOfDice; i++)
	{
		sum += diceArray[i]; 
	}
		
	return sum;
}

