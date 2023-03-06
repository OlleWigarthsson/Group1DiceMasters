#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main(){

	int choice = 0;
	printGameMenu();
	scanf("%d", &choice);
	if(choice == 1){
		printSinglePlayerMenu();
	}
	else if(choice == 2){
		printMultiplayerMenu();
	}
}
