#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdio.h>
#include "struct.h"

void CAP_CHANGES(int i);

void movement(int i, int direction){
	//Change the position of the player
	if(direction == 2){
		players[i].slotNum -= 1;
		printf("%s is now at %d ->", players[i].playername, players[i].slotNum);
	}

	else{
		players[i].slotNum += 1;
		printf("%s is now at %d ->", players[i].playername, players[i].slotNum);
	}

	//Print which area the player is in
	if(players[i].type == LevelGround){
		printf("  Level Ground\n");
	}

	if(players[i].type == Hill){
		printf("  Hill\n");
	}
	if(players[i].type == City){
		printf("  City\n");
	}
	//Call the function to check if any effects need to be removed or applied
	CAP_CHANGES(i);
}

#endif
