#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include "slot.h"
void CAP_CHANGES(int slot_cnt, int player_cnt, struct player players[], int i);



int main(){

	int player_cnt, slot_cnt, i;

	int Opt_class = 0;


	printf("Please enter the number of players:\n");
	fflush(stdout);
	printf("NB: You can only have a maximum of 6 players.\n");
	fflush(stdout);
	scanf("%d", &player_cnt);
	printf("Please enter the number of board slots you would like:\n");
	fflush(stdout);
	printf("NB: You can only have a maximum of 20 slots.\n");
	fflush(stdout);
	scanf("%d", &slot_cnt);




	for(i=0;i<player_cnt;i++){


    printf("Please enter your names:");
	fflush(stdout);
	scanf("%s", &players[i].playername);


	printf("Please choose your classes in the order that your names were announced.\n");
	printf("0 - Elf.\n");
	printf("1 - Human.\n");
	printf("2- Ogre.\n");
	printf("3- Wizard.\n");
	fflush(stdout);

	scanf("%d", &Opt_class);
	switch(Opt_class){
	case (0):{ players[i].class = 0;
	break;}
	case (1):{ players[i].class = 1;
	break;}
	case (2):{ players[i].class = 2;
	break;}
	case (3):{ players[i].class = 3;
	break;}
	}

	}

	slot_type(slot_cnt);
	slot_assign(slot_cnt, player_cnt, players);
	CAP_CHANGES(slot_cnt, player_cnt, players, i);



	int lifepts = 100;

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





