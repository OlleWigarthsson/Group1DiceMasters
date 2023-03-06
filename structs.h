//
typedef struct Dice{
	int nrOnFace;
}Dice;


typedef struct DicePool{
	int numberOfDice;
	Dice *dice;
}DicePool;

// A struct for all the stops i on game of random dice
typedef struct ScoreboardColumn {
    int ones;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int bonus;
    int pair;
    int twoPair;
    int threeOfAKind;
    int fourOfAKind;
    int smallStraight;
    int largeStraight;
    int fullHouse;
    int chance;
    int yatzy;
    int sum;
}ScoreboardColumn;

// A struct to for evry player. How is in the game
typedef struct ScoreBoard{
	char playerName[20];
	ScoreboardColumn *column;
}ScoreBoard;
