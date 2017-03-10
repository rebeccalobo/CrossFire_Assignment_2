#ifndef SLOT_H
#define SLOT_H /* ifndef and endif pre-processors checks the functions condition - "if the following is not defined"*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include "capabilities.h"


void slot_type(int slot_cnt);
void slot_assign(int slot_cnt, int player_cnt);

void slot_type(int slot_cnt){

	srand(time(NULL)); /* a function to create a list of randomly generated values*/
	int i;
	int random;

	/* the int value random is assigned a random number from 0 to 2 (length 3) whilst the number of slots is incremented...*/
	for(i=1;i<=slot_cnt;i++){
		random = rand() % 3;

		if(random == 0){
			slots[i].slot = 0;
		}
		else if(random == 1){
			slots[i].slot = 1;
		}
		else{
			slots[i].slot = 2;
		}
		/*...which corresponds to the enum slottype (in other words - LevelGround, Hill or City)*/
	}
}

void slot_assign(int slot_cnt, int player_cnt){

	srand(time(NULL));
	int i, j, r, temp[7]; /* a temporary array of size 7*/

	for(i=0;i<player_cnt;++i){
		r = (rand() % slot_cnt)+1; /* the int value r stores a random value within the size of the number of slots*/
		for(j=0;j<player_cnt;++j){
			do{
				r = rand() % slot_cnt + 1; /*this is incremented when the temporary array of size j is directly equal to the value of r at that time*/
			}
					while(temp[j] == r);
		}
		players[i].slotNum = r; /* the number of the slot that the player is on is also incremented so the player can continue to move*/
		temp[i] = r;
	}
}



#endif /* relates to SLOT_H */
