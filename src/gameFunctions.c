#include "diceFunctions.h"
#include "gameFunctions.h"
void singlePlayerGame(){
	DicePool *dicePool = (DicePool*)malloc(sizeof(DicePool));
	dicePool->numberOfDice = 0;
	ScoreboardColumn scoreBoard;
	for(int i = 0;i<5;i++){
		addDice(dicePool);
	}
	int choice = -1;
	int choices = 0;
	//Ones
	printf("Rolling for 1's\n");
	playRound(dicePool);

	//Save score

	//Reset Dice
	resetDiceThrows(dicePool);

	//Twos
	printf("Rolling for 2's\n");
	playRound(dicePool);

	//Save Score

	//Reset Dice



}
//Main function to play a round with 3 throws
void playRound(DicePool* dicePool){
	int choices = 0;
	int choice = -1;
	rollPool(dicePool);
	printDicePool(dicePool);
	for(int i = 0;i<2;i++){
		printf("Enter dice you don't want to roll (0 to continue): \n");
		choices = 0;
		while(choice != 0 && choices <= 4){
			scanf("%d", &choice);
			dicePool->dice[choice-1].toRoll = 0;
			choices++;
		}
		printf("Roll: \n");
		rollPool(dicePool);
		printDicePool(dicePool);
		//printf("\e[1;1H\e[2J");
		choice = -1;
		//if(choice == 0) break;
	}
}
