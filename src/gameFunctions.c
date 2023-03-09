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
	scoreBoard.twos = amountOfSubpoolDices(dicePool, 2) * 2;
	//Reset Dice
	resetDiceThrows(dicePool);

	//Threes
	printf("Rolling for 3's\n");
	playRound(dicePool, 3);

	//Save score
	scoreBoard.threes = amountOfSubpoolDices(dicePool, 3) * 3;
	//Reset Dice
	resetDiceThrows(dicePool);

	//Fours
	printf("Rolling for 4's\n");
	playRound(dicePool, 4);

	//Save score
	scoreBoard.fours = amountOfSubpoolDices(dicePool, 4) * 4;
	//Reset Dice
	resetDiceThrows(dicePool);

	//Fives
	printf("Rolling for 5's\n");
	playRound(dicePool, 5);

	//Save score
	scoreBoard.fives = amountOfSubpoolDices(dicePool, 5) * 5;
	//Reset Dice
	resetDiceThrows(dicePool);

	//Sixes
	printf("Rolling for 6's\n");
	playRound(dicePool, 6);

	//Save score
	scoreBoard.sixes = amountOfSubpoolDices(dicePool, 6) * 6;
	//Reset Dice
	resetDiceThrows(dicePool);

	//BONUS
	calcBonus(&scoreBoard);

	//Pair
	printf("Rolling for pair: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.pair = findHighestSinglePair(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);
	//Two Pair
	printf("Rolling for two pairs: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.twoPair = findHighestTwoPairs(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Three of a kind
	printf("Rolling for three of a kind: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.threeOfAKind = findHighestThreeOfSame(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Four of a kind
	printf("Rolling for four of a kind: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.fourOfAKind = findHighestFourOfSame(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Small Straight
	printf("Rolling for small straight: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.smallStraight = subpoolOfSmallStraight(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Large Straight
	printf("Rolling for large straight: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.largeStraight = subpoolOfLargeStraight(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Full House
	printf("Rolling for full house: \n");
	playRoundWithPause(dicePool);

	//Save Score
	//TODO MERGE AND REPLACE FUNCTION
	scoreBoard.fullHouse = findFullHouse(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Chance
	printf("Rolling for chance: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.chance = calcChance(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);

	//Yatzy
	printf("Rolling for yatzy: \n");
	playRoundWithPause(dicePool);

	//Save Score
	scoreBoard.yatzy = subpoolOfYatzy(dicePool);

	//Reset Dice
	resetDiceThrows(dicePool);
	//Sum
	calcSum(&scoreBoard);

	printScoreBoard(&scoreBoard);

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
void playRoundWithPause(DicePool* dicePool){
	int choices = 0;
	int choice = -1;
	rollPool(dicePool);
	printDicePool(dicePool);
	for(int i = 0;i<2;i++){
		printf("Enter dice you don't want to roll (0 to continue): \n");
		choices = 0;
		while(choice != 0 && choices <= 5){
			scanf("%d", &choice);
			dicePool->dice[choice -1].toRoll = 0;
			choices++;
		}
		printf("Roll: \n");
		rollPool(dicePool);
		printDicePool(dicePool);
		choice = -1;
		//if(choice == 0) break;
	}
}
