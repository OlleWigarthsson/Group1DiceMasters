#include "headers.h"
#include "structs.h"
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
	//TODO CHANGE NAME
	int counting;

	for (int i = 0; i < pool->numberOfDice; i++) {
		if (pool->dice[i].nrOnFace == faceValue)
			counting++;
	}
	return counting;
}
//Returns a subpool with all dices with faceValue
DicePool* getSubpoolOfDice(DicePool* pool, int faceValue){
	DicePool* subPool = (DicePool*)malloc(sizeof(DicePool));
	subPool->numberOfDice = 0;
	for(int i = 0;i<pool->numberOfDice;i++){
		if(pool->dice[i].nrOnFace == faceValue){
			subPool->dice = realloc(subPool->dice, (subPool->numberOfDice + 1) * sizeof(Dice));
			subPool->dice[subPool->numberOfDice++] = pool->dice[i];
		}
	}
	printf("%d\n", subPool->dice[0].nrOnFace);
	return subPool;
}
void lockSubpoolThrows(DicePool* pool){
	for(int i = 0;i<pool->numberOfDice;i++){
		pool->dice[i].toRoll = 0;
	}
}

//Function to check for small straight
int subpoolOfSmallStraight(DicePool* pool)
{
	int smallStraight[6] = {0};
	for (int i = 0; i < pool->numberOfDice; i++) {
		smallStraight[pool->dice[i].nrOnFace-1] = 1;
	}
	for (int i = 0; i < 5; i++) {
		if(smallStraight[i] == 0) {
			return 0;
		}
	}
	return 1;
}

//Function to check for large straight
int subpoolOfLargeStraight(DicePool* pool)
{
	int largeStraight[6] = {0};
	for (int i = 0; i < pool->numberOfDice; i++) {
		largeStraight[pool->dice[i].nrOnFace -1] = 1;
	}
	for (int i = 1; i < 6; i++) {
		if(largeStraight[i] == 0) {
			return 0;
		}
	}
	return 1;
}

