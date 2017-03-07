#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>
#include "slot.h"

void elf(int count);
void human(int count);
void ogre(int count);
void wizard(int count);

void capabilities(int count){
	srand(time(NULL));
    
	//Elf
		if(players[count].class == 1){
			elf(count);
		}

	//Human
		else if(players[count].class == 2){
			human(count);
		}

	//Ogre
		else if(players[count].class == 3){
			ogre(count);
		}

	//Wizard
		else{
			wizard(count);
		}

	printf("Player %d \n", count+1);
	printf("Dexterity: %d \n", players[count].dexterity);
	printf("Intelligence: %d \n", players[count].intelligence);
	printf("Luck: %d \n", players[count].luck);
	printf("Magic: %d \n", players[count].magic);
	printf("Strength: %d \n", players[count].strength);
	printf("Total Stats: %d \n", players[count].capabilities);
	puts("");
}

void elf(int count){
	int rerun=0;
	while(rerun<1){
		//dexterity
		players[count].dexterity = (rand() % 100)+1;
		//intelligence
		players[count].intelligence = (rand() % 31)+70;
		//luck
		players[count].luck = (rand() % 41)+60;
		//magic
		players[count].magic = (rand() % 29)+51;
		//strength
		players[count].strength = (rand() % 50)+1;

		players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

		if(players[count].capabilities>0){
			rerun+=1;
		}
	}
}

void human(int count){
	int rerun=0;
	while(rerun<1){
		//dexterity
		players[count].dexterity = (rand() % 100)+1;
		//intelligence
		players[count].intelligence = (rand() % 100)+1;
		//luck
		players[count].luck = (rand() % 100)+1;
		//magic
		players[count].magic = (rand() % 100)+1;
		//strength
		players[count].strength = (rand() % 100)+1;

		players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

		if(players[count].capabilities > 0 && players[count].capabilities < 300){
			rerun+=1;
		}
	}
}

void ogre(int count){
	int rerun=0;
	int luckIntcheck=0;

	while(rerun<1){
		//dexterity
		players[count].dexterity = (rand() % 21)+80;
		//intelligence
		players[count].intelligence = (rand() % 20)+1;
		//luck
		players[count].luck = (rand() % 50)+1;
		//magic
		players[count].magic = 0;
		//strength
		players[count].strength = (rand() % 21)+80;

		players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

		luckIntcheck= players[count].intelligence + players[count].luck;

		if(players[count].capabilities > 0 && luckIntcheck < 51){
			rerun+=1;
		}
	}
}

void wizard(int count){
	int rerun=0;

    while(rerun<1){
        //dexterity
        players[count].dexterity = (rand() % 100)+1;
        //intelligence
        players[count].intelligence = (rand() % 10)+90;
        //luck
        players[count].luck = (rand() % 50)+50;
        //magic
        players[count].magic = (rand() % 20)+80;
        //strength
        players[count].strength = (rand() % 20)+1;

        players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

        if(players[count].capabilities > 0){
            rerun+=1;
        }
    }
}

#endif
