#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>

//Declare functions
void elf(int count);
void human(int count);
void ogre(int count);
void wizard(int count);

void capabilities(int count, int i){
	srand(time(NULL));
	//I used 1-100 instead of 0-100 for player capabilities, as a player with 0 attack cannot win, whereas a player with 1 at least has a slight chance
    
	//Elf
		if(count == 0){
			elf(i);
		}

	//Human
		else if(count == 1){
			human(i);
		}

	//Ogre
		else if(count == 2){
			ogre(i);
		}

	//Wizard
		else{
			wizard(i);
		}

	//Print stats
	printf("Dexterity: %d \n", players[i].dexterity);
	printf("Intelligence: %d \n", players[i].intelligence);
	printf("Luck: %d \n", players[i].luck);
	printf("Magic: %d \n", players[i].magic);
	printf("Strength: %0.0f \n", players[i].strength);
	printf("Total Stats: %d \n", players[i].capabilities);
	puts("");
}

//Each function generates random values based on the given parameters in the question
void elf(int i){
	int rerun=0;
	while(rerun<1){
		//dexterity
		players[i].dexterity = (rand() % 100)+1;
		//intelligence
		players[i].intelligence = (rand() % 31)+70;
		//luck
		players[i].luck = (rand() % 41)+60;
		//magic
		players[i].magic = (rand() % 29)+51;
		//strength
		players[i].strength = (rand() % 50)+1;

		players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

		if(players[i].capabilities>0){
			rerun+=1;
		}
	}
}

void human(int i){
	int rerun=0;
	while(rerun<1){
		//dexterity
		players[i].dexterity = (rand() % 100)+1;
		//intelligence
		players[i].intelligence = (rand() % 100)+1;
		//luck
		players[i].luck = (rand() % 100)+1;
		//magic
		players[i].magic = (rand() % 100)+1;
		//strength
		players[i].strength = (rand() % 100)+1;

		players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

		if(players[i].capabilities > 0 && players[i].capabilities < 300){
			rerun+=1;
		}
	}
}

void ogre(int i){
	int rerun=0;
	int luckIntcheck=0;

	while(rerun<1){
		//dexterity
		players[i].dexterity = (rand() % 20)+80;
		//intelligence
		players[i].intelligence = (rand() % 20)+1;
		//luck
		players[i].luck = (rand() % 50)+1;
		//magic
		players[i].magic = 0;
		//strength
		players[i].strength = (rand() % 21)+80;

		players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

		luckIntcheck= players[i].intelligence + players[i].luck;

		if(players[i].capabilities > 0 && luckIntcheck < 51){
			rerun+=1;
		}
	}
}

void wizard(int i){
	int rerun=0;

    while(rerun<1){
        //dexterity
        players[i].dexterity = (rand() % 100)+1;
        //intelligence
        players[i].intelligence = (rand() % 10)+90;
        //luck
        players[i].luck = (rand() % 50)+50;
        //magic
        players[i].magic = (rand() % 20)+80;
        //strength
        players[i].strength = (rand() % 20)+1;

        players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

        if(players[i].capabilities > 0){
            rerun+=1;
        }
    }
}

#endif
