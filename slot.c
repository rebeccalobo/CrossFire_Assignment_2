#ifndef SLOT_H
#define SLOT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void slot_type(int slot_cnt){
	srand(time(NULL));
	int i;
	int random;

	for(i=0;i<slot_cnt;++i){
		random = rand() % 3;

		switch(random){
		case (0): players[i].type = 0;
		break;
		case (1): players[i].type = 1;
		break;
		case (2): players[i].type = 2;
		break;
		}
	}
}

void slot_assign(int slot_cnt, int player_cnt){

	srand(time(NULL));
	int i, j, r, temp[7];

	for(i=0;i<player_cnt;++i){
		r = rand() % slot_cnt;
		for(j=0;j<player_cnt;++j){
			do{
				r = rand() % slot_cnt + 1;
			}
					while(temp[j] == r);
		}
		players[i].slotNum = r + 1;
		temp[i] = r;
	}
}

#endif /* relates to SLOT_H */
