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
	if(slots[players[i].slotNum].slot == LevelGround){
		printf("  Level Ground\n");
	}

	if(slots[players[i].slotNum].slot == Hill){
		printf("  Hill\n\n");
	}
	if(slots[players[i].slotNum].slot == City){
		printf("  City\n\n");
	}
	//Call the function to check if any effects need to be removed or applied
	CAP_CHANGES(i);
}

#endif
