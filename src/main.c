#include "menu.h"
#include "gameFunctions.h"

int main(){
	srand(time(0));
	//bool playing = false;
	int choice = 0;
	printGameMenu();
	scanf("%d", &choice);
	if(choice == 1){
		printSinglePlayerMenu();
		scanf("%d", &choice);
		if(choice == 1){
			//Play game
			singlePlayerGame();

		}
	}
	else if(choice == 2){
		printMultiplayerMenu();
		scanf("%d", &choice);
		if(choice == 1){
			multiPlayerGame();
		}
	}
	else if(choice == 3){
		printSettingsMenu();
	}
}
