#include "headers.h"
//diceFunctions
void addDice(DicePool *pool);
void mergePools(DicePool *pool1, DicePool pool2);
int rollDice();
void rollPool(DicePool *pool);
int subpoolOfDice(DicePool* pool, int faceValue);

//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice);

// A bubble sorting, from smallest to biggest
void soringSmallBig (DicePool *pool);

// A bubble sorting, from biggest to smallest
void sortingBigSmall(DicePool *pool);

// Funktion to see if we have a full house or not
int findFullHouse(DicePool *pool);

