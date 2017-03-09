#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>

void attack(int no, int playersize){
	int plarray[playersize][3];
	int i=0;
	int store=0;

	while(i<playersize){
		plarray[i][0]=i;
		plarray[i][1]=players[i].slotNum;
		if(plarray[i][0]==no){
			store=i;
		}
		i++;
	}

	i=0;
	//Find distance to the attacker
	while(i<playersize){
		plarray[i][2] = plarray[store][1]-plarray[i][1];
		if(plarray[i][2] < 0){
			plarray[i][2] = -plarray[i][2];
		}
		i++;
	}

	i=0;
	int smallestdist=20;
	//Sort to get players closest to attacker
	while(i<playersize){
		if(smallestdist > plarray[i][2] && plarray[i][2] != 0){
			smallestdist = plarray[i][2];
		}
		i++;
	}

	i=0;
	int array[playersize-1];
	int count=0;
	//See if any players at same distance
	while(i<playersize){
		if(smallestdist == plarray[i][2]){
			array[count]=plarray[i][0];
			count++;
		}
		i++;
	}

	int damage;
	//Calculate attack
	if(players[no].strength >= 70){
		damage = 0.5*players[no].strength;
	}
	else{
		damage = 0.5*players[no].strength;
	}

	i=0;
	while(i<count){
		players[i].lifepts -= damage;
		printf("Player %d life points is now: %d \n", i, players[i].lifepts);
		i++;
	}
}
