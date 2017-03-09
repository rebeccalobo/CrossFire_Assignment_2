#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include "slot.h"
#include "attack.h"
#include "capabilities.h"


void CAP_CHANGES(int slot_cnt, int player_cnt, struct player players[], int i);
void capabilities(int count);
void slot_type(int slot_cnt);
void slot_assign(int slot_cnt, int player_cnt);
//void move();

int main(){
	int player_cnt=0, slot_cnt=0, i;
	int lifepts = 100;
	int Opt_class = 0;

	printf("Please enter the number of players between 1-6: ");
	fflush(stdout);
	while(player_cnt<1 || player_cnt>6){
		scanf("%d", &player_cnt);
	}

	printf("Please enter the number of board slots you would like between 1-20: ");
	fflush(stdout);
	while(slot_cnt<1 || slot_cnt>20){
		scanf("%d", &slot_cnt);
	}

	for(i=0;i<player_cnt;i++){
		Opt_class=0;
	    printf("Player %d Please enter your name: ", i+1);
		fflush(stdout);
		scanf("%s", &players[i].playername);

		printf("1 = Elf\n");
		printf("2 = Human\n");
		printf("3 = Ogre\n");
		printf("4 = Wizard\n");
		printf("Enter a number to choose your class: ");
		fflush(stdout);
		while(Opt_class<1 || Opt_class>4){
			scanf("%d", &Opt_class);
		}

		players[i].class = --Opt_class;

		puts("");
				printf("Player %d -> %s \n", i+1, players[i].playername);

				if(players[i].class == Elf){
				printf("(Elf , %d)\n", lifepts);
				fflush(stdout);
				}
				else if(players[i].class == Human){
					printf("(Human , %d)\n", lifepts);
					fflush(stdout);
				}
				else if(players[i].class == Ogre){
					printf("(Ogre , %d)\n", lifepts);
					fflush(stdout);
				}
				else if(players[i].class == Wizard){
					printf("(Wizard , %d)\n", lifepts);
					fflush(stdout);
				}
		capabilities(Opt_class);
	}

	slot_type(slot_cnt);
	slot_assign(slot_cnt, player_cnt);
	CAP_CHANGES(slot_cnt, player_cnt, players, i);

	for(i=0;i<player_cnt;++i){
		puts("");
		printf("Player %d -> %s \n", i+1, players[i].playername);

		if(players[i].class == Elf){
		printf("(Elf , %d)\n", lifepts);
		fflush(stdout);
		}
		else if(players[i].class == Human){
			printf("(Human , %d)\n", lifepts);
			fflush(stdout);
		}
		else if(players[i].class == Ogre){
			printf("(Ogre , %d)\n", lifepts);
			fflush(stdout);
		}
		else if(players[i].class == Wizard){
			printf("(Wizard , %d)\n", lifepts);
			fflush(stdout);
		}

		printf("%s is at %d ->", players[i].playername, players[i].slotNum);

		if(players[i].type == LevelGround){
			printf("  Level Ground\n");
		}

		if(players[i].type == Hill){
			printf("  Hill\n");
		}
		if(players[i].type == City){
			printf("  City\n");
		}
		puts("");
	}

	return 0;
}

void CAP_CHANGES(int slot_cnt, int player_cnt, struct player players[], int i){

	while(players[i].type == Hill){
		if(players[i].dexterity < 50){
			players[i].strength -= 10;
		}

		else if(players[i].dexterity >= 60 && players[i].strength <=90){
	 		players[i].strength += 10;
	 	}
	}

	while(players[i].type == City){
		if(players[i].intelligence > 60 && players[i].magic <=90){
			players[i].magic += 10;
		}

		else if(players[i].intelligence <= 50){
			players[i].dexterity -= 10;
		}

	}
}
