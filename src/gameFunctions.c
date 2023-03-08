#include "gameFunctions.h"
void singlePlayerGame(){
	DicePool *dicePool = (DicePool*)malloc(sizeof(DicePool));
	dicePool->numberOfDice = 0;
	ScoreboardColumn scoreBoard = {-1};
	for(int i = 0;i<5;i++){
		addDice(dicePool);
	}
	int choice = -1;
	int choices = 0;
	//Ones
	printf("Rolling for 1's\n");
	playRound(dicePool, 1);

	//Save score
	scoreBoard.ones = amountOfSubpoolDices(dicePool, 1);
	//Reset Dice
	resetDiceThrows(dicePool);

	//Twos
	printf("Rolling for 2's\n");
	playRound(dicePool, 2);

	//Save score
	scoreBoard.twos = amountOfSubpoolDices(dicePool, 2);
	//Reset Dice
	resetDiceThrows(dicePool);

	//Threes
	printf("Rolling for 3's\n");
	playRound(dicePool, 3);

	//Save score
	scoreBoard.threes = amountOfSubpoolDices(dicePool, 3);
	//Reset Dice
	resetDiceThrows(dicePool);

	//Fours
	printf("Rolling for 4's\n");
	playRound(dicePool, 4);

	//Save score
	scoreBoard.fours = amountOfSubpoolDices(dicePool, 4);
	//Reset Dice
	resetDiceThrows(dicePool);

	//Fives
	printf("Rolling for 5's\n");
	playRound(dicePool, 5);

	//Save score
	scoreBoard.fives = amountOfSubpoolDices(dicePool, 5);
	//Reset Dice
	resetDiceThrows(dicePool);

	//Sixes
	printf("Rolling for 6's\n");
	playRound(dicePool, 6);

	//Save score
	scoreBoard.sixes = amountOfSubpoolDices(dicePool, 6);
	//Reset Dice
	resetDiceThrows(dicePool);



}
//Main function to play a round with 3 throws
void playRound(DicePool* dicePool, int value){
	int choices = 0;
	int choice = -1;
	DicePool* subPool = (DicePool*)malloc(sizeof(DicePool));
	subPool->numberOfDice = 0;
	rollPool(dicePool);
	printDicePool(dicePool);
	for(int i = 0;i<2;i++){
		printf("Enter dice you don't want to roll (0 to continue): \n");
		lockSubpoolThrows(dicePool, value);
		printf("Roll: \n");
		rollPool(dicePool);
		printDicePool(dicePool);
		choice = -1;
		//if(choice == 0) break;
	}
}
