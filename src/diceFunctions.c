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


void printScoreBoard(ScoreboardColumn* column)
{
	printf("This is your score:")

	if(column->ones != -1)
	{
		printf("Ones: %d\n", column->ones);
	}
	if(column->twos != -1)
	{
		printf("Twos: %d\n", column->twos);
	}
	if(column->threes != -1)
	{
		printf("Threes: %d\n", column->threes);
	}
	if(column->fours != -1)
	{
		printf("Fours: %d\n", column->fours);
	}
	if(column->fives != -1)
	{
		printf("Fives: %d\n", column->fives);
	}
	if(column->sixes != -1)
	{
		printf("Sixes: %d\n", column->sixes);
	}
	if(column->bonus != -1)
	{
		printf("Bonus: %d\n", column->bonus);
	}
	if(column->pair != -1)
	{
		printf("Pair: %d\n", column->pair);
	}
	if(column->twoPair != -1)
	{
		printf("Two pair: %d", column->twoPair)
	}
	if(column->threeOfAKind != -1)
	{
		printf("Three of a kind: %d\n", column->threeOfAKind);
	}
	if(column->fourOfAKind != -1)
	{
		printf("Four of a kind: %d\n", column->fourOfAKind);
	}
	if(column->smallStraight != -1)
	{
		printf("Small straight: %d\n", column->smallStraight);
	}
	if(column->largeStraight != -1)
	{
		printf("Large straight: %d\n", column->largeStraight);
	}
	if(column->fullHouse != -1)
	{
		printf("Full house: %d\n", column->fullHouse);
	}
	if(column->chance != -1)
	{
		printf("Chance: %d\n", column->chance);
	}
	if(column->yatzy != -1)
	{
		printf("Yatzy: %d\n", column->yatzy);
	}
	if(column->sum != -1)
	{
		printf("Total score: %d\n", column->sum);
	}
}





