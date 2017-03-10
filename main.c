#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
/* inclusion of my header files where my code has been sectioned off according to certain requirements for the game.*/
//#include "slot.h"
//#include "attack.h"
//#include "capabilities.h"

/* functions are initialized which need variables such as slot and player counting from the header files*/
void capabilities(int count, int i);
void slot_type(int slot_cnt);
void slot_assign(int slot_cnt, int player_cnt);
int attack(int no, int playersize, int remainingplayers);
void movement(int i, int direction);

int main(){
	int player_cnt=0, slot_cnt=0, i;
	int Opt_class = 0;

	printf("Please enter the number of players between 1-6: "); /* program is asking the user the name of players he/she wants in the game*/
	fflush(stdout);
	while(player_cnt<1 || player_cnt>6){ //Make sure the player chooses a valid number of players
		scanf("%d", &player_cnt);
	}

	printf("Please enter the number of board slots you would like between %d-20: ", player_cnt); /* the program allows the user the make the decision on how big the board game is*/
	fflush(stdout);
	while(slot_cnt<player_cnt || slot_cnt>20){ //Make sure the player chooses a valid number of slots
		scanf("%d", &slot_cnt);
	}

	for(i=0;i<player_cnt;i++){
		//Assign temps for later use in ensure capabilities outside boundaries are not reached.
		players[i].dextemp=0;
		players[i].strtemp=0;
		players[i].magtemp=0;
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
		while(Opt_class<1 || Opt_class>4){ //Make sure the player chooses a valid number in order to select a class
			scanf("%d", &Opt_class);
		}

		players[i].class = --Opt_class; //Assign each player the correct class, using their input, and the enum from struct.h
		players[i].lifepts = 100; /* each player is being given 100% health at the start of the game*/
		puts("");
				printf("Player %d -> %s \n", i+1, players[i].playername);

				if(players[i].class == Elf){
				printf("(Elf , %0.0f)\n", players[i].lifepts);
				fflush(stdout);
				}
				else if(players[i].class == Human){
					printf("(Human , %0.0f)\n", players[i].lifepts);
					fflush(stdout);
				}
				else if(players[i].class == Ogre){
					printf("(Ogre , %0.0f)\n", players[i].lifepts);
					fflush(stdout);
				}
				else if(players[i].class == Wizard){
					printf("(Wizard , %0.0f)\n", players[i].lifepts);
					fflush(stdout);
				}
			capabilities(Opt_class, i); /* Calling the capabilities function to print out each player's abilities*/
	}

	/*This section of code allows me to assign a specific starting slot to each player and change their abilities depending on which slot they move to next*/
	slot_type(slot_cnt);
	slot_assign(slot_cnt, player_cnt);

	for(i=0;i<player_cnt;++i){
		puts("");
		printf("Player %d -> %s \n", i+1, players[i].playername);

		if(players[i].class == Elf){ /* I have manually printed out the class type by going through, with if statements, the types of enum playerclass values*/
		printf("(Elf , %0.0f)\n", players[i].lifepts);
		fflush(stdout);
		}
		else if(players[i].class == Human){
			printf("(Human , %0.0f)\n", players[i].lifepts);
			fflush(stdout);
		}
		else if(players[i].class == Ogre){
			printf("(Ogre , %0.0f)\n", players[i].lifepts);
			fflush(stdout);
		}
		else if(players[i].class == Wizard){
			printf("(Wizard , %0.0f)\n", players[i].lifepts);
			fflush(stdout);
		}

		printf("%s is at %d ->", players[i].playername, players[i].slotNum);

		if(slots[players[i].slotNum].slot == LevelGround){ /* prints the type of slot according to the slottype enumeration in struct.h*/
			printf("  Level Ground\n");
		}

		if(slots[players[i].slotNum].slot == Hill){
			printf("  Hill\n");
		}
		if(slots[players[i].slotNum].slot == City){
			printf("  City\n");
		}
		puts("");
	}

	//Game Mechanics

	int remainingplayers = player_cnt;
	int action = 0;
	i=0;
	//Loop until only one remains
	while(remainingplayers != 1){
		//Loop through all the players, letting each one take a turn
		while(i<player_cnt){
			//Check if the player is still alive
			if(players[i].lifepts > 0){
				printf("%s, Please choose an action: \n", players[i].playername);
				//All possible actions
				printf("1 = Attack \n2 = Move Left \n3 = Move Right \n");
				scanf("%d", &action);
				//Using a do while loop as needs to be edited while in the loop
				//If the player has reach the end of the slots, we need to tell them and give them another choice
				do{
					if(action == 1){
						//Call the attack function and check if anyone died
						remainingplayers = attack(i, player_cnt, remainingplayers);
					}
					else if(action == 2){
						//If the player can't move any further left, notify them and give them another chance
						if(players[i].slotNum <= 1){
							printf("You cannot move any further left, Please choose a different action:\n");
							i--;
							action=0;
						}
						else{
							//Call the movement function
							movement(i, action);
						}
					}
					else if(action == 3){
						if(players[i].slotNum >= slot_cnt){
							printf("You cannot move any further right, Please choose a different action:\n");
							i--;
							action=0;
						}
						else{
							movement(i, action);
						}
					}
					else{
						scanf("%d", &action);
					}
				}while(action<1 && action>3);

			}
			i++;
		}
		//reset i to go through the loop again
		i=0;
	}

	i=0;
	while(i<player_cnt){
		//Find which player is still alive, at this point there should only be one
		if(players[i].lifepts > 0){
			//Print who won
			printf("Game Over! %s Wins", players[i].playername);
		}
		i++;
	}
	return 0;
}

