// Find the highest pair in a dice pool

int findHighestPair(DicePool pool) {
    int maxPair = 0;
    for (int i = 0; i < pool.numDice - 1; i++) {
        for (int j = i + 1; j < pool.numDice; j++) {
            if (pool.dice[i] == pool.dice[j]) {
                if (pool.dice[i] > maxPair) {
                    maxPair = pool.dice[i];
                }
            }
        }
    }
    return maxPair;
}

// Find the highest two pairs in a dice pool

int findHighestTwoPairs(DicePool pool) {
    int maxPair = 0;
    int secondMaxPair = 0;
    for (int i = 0; i < pool.numDice - 1; i++) {
        for (int j = i + 1; j < pool.numDice; j++) {
            if (pool.dice[i] == pool.dice[j]) {
                if (pool.dice[i] >= maxPair) {
                    secondMaxPair = maxPair;
                    maxPair = pool.dice[i];
                } else if (pool.dice[i] >= secondMaxPair) {
                    secondMaxPair = pool.dice[i];
                }
            }
        }
    }
    if (secondMaxPair == 0) {
        return 0;
    } else {
        return maxPair + secondMaxPair;
    }
}



//diceFunctions
void addDice(DicePool *pool, Dice dice);
void mergePools(DicePool *pool1, DicePool pool2);
int rollDice();
void rollPool(DicePool *pool);

//Function to sum dices
int sumOfDicepool(Dice diceArray[], int numberOfDice);

