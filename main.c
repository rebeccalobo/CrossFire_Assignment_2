#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include "slot.h" /* inclusion of my header files where my code has been sectioned off according to certain requirements for the game.*/
#include "attack.h"
#include "capabilities.h"


void CAP_CHANGES(int slot_cnt, int player_cnt, struct player players[], int i); /* functions are initialised which need variables such as slot and player counting from the header files*/
void capabilities(int count);
void slot_type(int slot_cnt);
void slot_assign(int slot_cnt, int player_cnt);
//void move();

int main(){
	int player_cnt=0, slot_cnt=0, i;
	int lifepts = 100; /* each player is being given 100% health at the start of the game*/
	int Opt_class = 0;

	printf("Please enter the number of players between 1-6: "); /* program is asking the user the name of players he/she wants in the game*/
	fflush(stdout);
	while(player_cnt<1 || player_cnt>6){ //
		scanf("%d", &player_cnt);
	}

	printf("Please enter the number of board slots you would like between 1-20: "); /* the program allows the user the make the decision on how big the board game is*/
	fflush(stdout);
	while(slot_cnt<1 || slot_cnt>20){ //
		scanf("%d", &slot_cnt);
	}

	for(i=0;i<player_cnt;i++){
		Opt_class=0;
	    printf("Player %d Please enter your name: ", i+1); /* as the number of players is being incremented to the user's max number, the names of the players are being assigned to each number and stored within an array*/
		fflush(stdout);
		scanf("%s", &players[i].playername);

		printf("1 = Elf\n");
		printf("2 = Human\n"); /* Options for the player's class are clearly printed with a corresponding integer value which will be inputed by the user and compared to the player class enumeration in struct.h*/
		printf("3 = Ogre\n");
		printf("4 = Wizard\n");
		printf("Enter a number to choose your class: ");
		fflush(stdout);
		while(Opt_class<1 || Opt_class>4){ //
			scanf("%d", &Opt_class);
		}

		players[i].class = --Opt_class; //

		puts("");
				printf("Player %d -> %s \n", i+1, players[i].playername);

				if(players[i].class == Elf){ /* I have manually printed out the class type by going through, with if statements, the types of enum playerclass values*/
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
		capabilities(Opt_class); /* I am calling upon my capabilities function to print out each player's abilities from the capabilities.h file*/
	}
/*This section of code allows me to assign a specific starting slot to each player and change their abilities depending on which slot they move to next*/
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

		if(players[i].type == LevelGround){ /* prints the type of slot according to the slottype enumeration in struct.h*/
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

void CAP_CHANGES(int slot_cnt, int player_cnt, struct player players[], int i){ /* including the content of the function which allows abilities to change based on the slot type the player is on */

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
