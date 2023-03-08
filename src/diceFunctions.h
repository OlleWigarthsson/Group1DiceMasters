#include "headers.h"
#include "structs.h"
//diceFunctions
void addDice(DicePool *pool);
void mergePools(DicePool *pool1, DicePool pool2);
int rollDice();
void rollPool(DicePool *pool);
int subpoolOfDice(DicePool* pool, int faceValue);
int subpoolOfSmallStraight(DicePool* pool);
int subpoolOfLargeStraight(DicePool* pool);


//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice);

