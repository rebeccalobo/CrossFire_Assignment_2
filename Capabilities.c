#ifndef CAPABILITIES_H
#define CAPABILITIES_H

#include <stdio.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>
#include "slot.h"

void capabilities(int i){
	
    int rerun=0;
    int luckIntcheck=0;
    srand(time(NULL));

    //Elf
    if(players[i].class == 1){
    	while(rerun<1){
	    //dexterity
    	    players[i].dexterity = (rand() % 101);
    	    //intelligence
    	    players[i].intelligence = (rand() % 31)+70;
            //luck
    	    players[i].luck = (rand() % 41)+60;
    	    //magic
    	    players[i].magic = (rand() % 29)+51;
    	    //strength
    	    players[i].strength = (rand() % 51);
		
            players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;
		
	    if(players[i].capabilities>0){
		    rerun+=1;
    		}
	}
    }

    //Human
    else if(players[i].class == 2){
    	while(rerun<1){
	    //dexterity
    	    players[i].dexterity = (rand() % 101);
            //intelligence
            players[i].intelligence = (rand() % 101);
            //luck
            players[i].luck = (rand() % 101);
            //magic
            players[i].magic = (rand() % 101);
            //strength
            players[i].strength = (rand() % 101);

            players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

            if(players[i].capabilities > 0 && players[i].capabilities < 300){
            	rerun+=1;
            }
    	}
    }

    //Ogre
    else if(players[i].class == 3){
    	while(rerun<1){
    	    //dexterity
            players[i].dexterity = (rand() % 21)+80;
            //intelligence
            players[i].intelligence = (rand() % 21);
            //luck
            players[i].luck = (rand() % 100)+80;
            //magic
            players[i].magic = 0;
            //strength
            players[i].strength = (rand() % 101);

            players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

            luckIntcheck= players[i].intelligence + players[i].luck;

            if(players[i].capabilities > 0 && luckIntcheck < 51){
            	rerun+=1;
            }
    	}
    }

    //Wizard
    else{
    	while(rerun<1){
		//dexterity
    		players[i].dexterity = (rand() % 101);
    		//intelligence
    		players[i].intelligence = (rand() % 10)+90;
    		//luck
    		players[i].luck = (rand() % 50)+50;
    		//magic
    		players[i].magic = (rand() % 20)+80;
    		//strength
    		players[i].strength = (rand() % 20);

    		players[i].capabilities = players[i].dexterity + players[i].intelligence + players[i].luck + players[i].magic + players[i].strength;

    		if(players[i].capabilities > 0){
    			rerun+=1;
    		}
    	}
    }

    printf("Player %d \n", i+1);
    printf("Dexterity: %d \n", players[i].dexterity);
    printf("Intelligence: %d \n", players[i].intelligence);
    printf("Luck: %d \n", players[i].luck);
    printf("Magic: %d \n", players[i].magic);
    printf("Strength: %d \n", players[i].strength);
    printf("Total Stats: %d \n", players[i].capabilities);
    i++;


}
#endif
