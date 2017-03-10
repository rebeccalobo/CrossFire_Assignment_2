#ifndef ATTACK_H
#define ATTACK_H

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>

int attack(int no, int playersize, int remainingplayers){
	int plarray[playersize][3];
	int i=0;
	int store=0;

	//Set up array
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
			plarray[i][2] = -1*plarray[i][2];
		}
		printf("%d", plarray[i][2]);
		i++;
	}

	i=0;
	//Set =25 since max is 20
	int smallestdist=25;
	//Find the closest player/s to the attacker
	while(i<playersize){
		//also make sure not to check the distance from the attacker to the attacker (i != no)
		if(smallestdist > plarray[i][2] && i != no){
			smallestdist = plarray[i][2];
		}
		i++;
	}

	i=0;
	int array[playersize-1];
	int count=0;
	//See if any players at same distance
	//Since players same distance from attacker both get attacked
	while(i<playersize){
		if(smallestdist == plarray[i][2]){
			//Store who is closest in array in case of multiple
			array[count]=plarray[i][0];
			count++;
		}
		i++;
	}

	int damage=0;
	//Calculate attack
	if(players[no].strength >= 70){
		damage = 0.5*players[no].strength;
	}
	else{
		//Weaker attack
		damage = 0.3*players[no].strength;
	}

	i=0;
	while(i<count){
		//Implement the attack
		players[array[i]].lifepts -= damage;
		//Check if anyone died
		if(players[array[i]].lifepts > 0){
			printf("%s's life points are now: %0.2f \n", players[array[i]].playername, players[array[i]].lifepts);
		}
		else{
			printf("%s has been killed by %s\n", players[array[i]].playername, players[no].playername);
			remainingplayers--;
		}
		i++;
	}
	//Return how many players are left in order to see when the game is over
	return remainingplayers;
}
#endif
