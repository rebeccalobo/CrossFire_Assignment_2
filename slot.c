#ifndef SLOT_H
#define SLOT_H /* ifndef and endif pre-processors checks the functions condition - "if the following is not defined"*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void slot_type(int slot_cnt, char slotArr[100][20]);
void slot_assign(int slot_cnt, int player_cnt, char slotArr[100][20]);

void slot_type(int slot_cnt, char slotArr[100][20]){

	srand(time(NULL)); /* a function to create a list of randomly generated values*/
	int i;
	int random;


	for(i=0;i<slot_cnt;++i){ /* the int value random is assigned a random number from 0 to 2 (length 3) whilst the number of slots is incremented...*/
		random = rand() % 3;

		switch(random){
		case (0): players[i].type = 0; /*...which corresponds to the enum slottype (in other words - LevelGround, Hill or City)*/
		break;
		case (1): players[i].type = 1;
		break;
		case (2): players[i].type = 2;
		break;
		}
	}
}

void slot_assign(int slot_cnt, int player_cnt, char slotArr[100][20]){

	srand(time(NULL));
	int i, j, r, temp[player_cnt]; /* a temporary array based on the size of the number of players*/
	int dup = 1;

	while(dup == 1){
		for(i=0;i<player_cnt;i++){
			r = rand() % slot_cnt;
			temp[i] = r;
		}
		dup = 0;
		for(i=0;i<player_cnt;++i){
			for(j=0;j<player_cnt;++j){
				if(temp[i] == temp[j]){
					dup = 1;
					break;
				}
			}
		}
		if(!dup){
			break;
		}
	}

	for(i=0;i<player_cnt;i++){
		players[i].slotNum = temp[i] + 1;

		if(slotArr[i] == "LevelGround"){
			players[i].type = 0;
		}
		else if(slotArr[i] == "Hill"){
			players[i].type = 1;
		}
		else if(slotArr[i] == "City"){
			players[i].type = 2;
		}
	}
}




#endif /* relates to SLOT_H */
