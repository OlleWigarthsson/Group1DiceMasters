#include "diceFunctions.h"
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
int amountOfSubpoolDices(DicePool* pool, int faceValue)
{
	//TODO CHANGE NAME
	int counting;

	for (int i = 0; i < pool->numberOfDice; i++) {
		if (pool->dice[i].nrOnFace == faceValue)
			counting++;
	}
	return counting;
}
//Returns a subpool with all dices with faceValue
void getSubpoolOfDice(DicePool* pool, DicePool* subPool, int faceValue){
	subPool = (DicePool*)malloc(sizeof(DicePool));
	subPool->dice = (Dice*)malloc(sizeof(Dice));
	subPool->numberOfDice = 0;
	for(int i = 0;i<pool->numberOfDice;i++){
		if(pool->dice[i].nrOnFace == faceValue){
			pool->dice[i].toRoll = 0;
//			subPool->dice = realloc(subPool->dice, (subPool->numberOfDice + 1) * sizeof(Dice));
//			subPool->dice[subPool->numberOfDice++] = pool->dice[i];
//			//*subPool->numberOfDice++;
		}
	}
	printf("%d\n", subPool->numberOfDice);
	//return subPool;
}
void lockSubpoolThrows(DicePool* pool, int value){
	for(int i = 0;i<pool->numberOfDice;i++){
		if(pool->dice[i].nrOnFace == value){
			pool->dice[i].toRoll = 0;
		}
	}
}
