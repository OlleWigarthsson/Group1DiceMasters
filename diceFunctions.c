//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice) {
	
	int sum = 0;
	
	for(int i = 0; i < numberOfDice; i++)
	{
		sum += diceArray[i]; 
	}
		
	return sum;
}