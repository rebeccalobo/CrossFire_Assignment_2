#include <stdio.h>
#include <struct.h>
#include "struct.h"
#include <stdlib.h>
#include <time.h>

void capabilities(int count){
		struct players p;
    	int rerun=0;
    	int luckIntcheck=0;
    
    	srand(time(NULL));
    
    	//Elf
            if(players[count].class == 1){
                while(rerun<1){
                    //dexterity
                    players[count].dexterity = (rand() % 101);
                    //intelligence
                    players[count].intelligence = (rand() % 31)+70;
                    //luck
                    players[count].luck = (rand() % 41)+60;
                    //magic
                    players[count].magic = (rand() % 29)+51;
                    //strength
                    players[count].strength = (rand() % 51);

                    players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

                    if(players[count].capabilities>0){
                        rerun+=1;
                    }
                }
            }

            //Human
            else if(players[count].class == 2){
                while(rerun<1){
                    //dexterity
                    players[count].dexterity = (rand() % 101);
                    //intelligence
                    players[count].intelligence = (rand() % 101);
                    //luck
                    players[count].luck = (rand() % 101);
                    //magic
                    players[count].magic = (rand() % 101);
                    //strength
                    players[count].strength = (rand() % 101);

                    players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

                    if(players[count].capabilities > 0 && players[count].capabilities < 300){
                        rerun+=1;
                    }
                }
            }

            //Ogre
            else if(players[count].class == 3){
                while(rerun<1){
                    //dexterity
                    players[count].dexterity = (rand() % 21)+80;
                    //intelligence
                    players[count].intelligence = (rand() % 21);
                    //luck
                    players[count].luck = (rand() % 100)+80;
                    //magic
                    players[count].magic = 0;
                    //strength
                    players[count].strength = (rand() % 101);

                    players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

                    luckIntcheck= players[count].intelligence + players[count].luck;

                    if(players[count].capabilities > 0 && luckIntcheck < 51){
                        rerun+=1;
                    }
                }
            }

            //Wizard
            else{
                while(rerun<1){
                    //dexterity
                    players[count].dexterity = (rand() % 101);
                    //intelligence
                    players[count].intelligence = (rand() % 10)+90;
                    //luck
                    players[count].luck = (rand() % 50)+50;
                    //magic
                    players[count].magic = (rand() % 20)+80;
                    //strength
                    players[count].strength = (rand() % 20);

                    players[count].capabilities = players[count].dexterity + players[count].intelligence + players[count].luck + players[count].magic + players[count].strength;

                    if(players[count].capabilities > 0){
                        rerun+=1;
                    }
                }
            }

        printf("Player %d \n", count+1);
        printf("Dexterity: %d \n", players[count].dexterity);
        printf("Intelligence: %d \n", players[count].intelligence);
        printf("Luck: %d \n", players[count].luck);
        printf("Magic: %d \n", players[count].magic);
        printf("Strength: %d \n", players[count].strength);
        printf("Total Stats: %d \n", players[count].capabilities);
        count++;
}