#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include "slot.h"



int main(){

	int playersize, i;

	int Opt = 0;

	printf("Please enter the number of players:\n");
	fflush(stdout);
	scanf("%d", &playersize);



	for(i=0;i<playersize;i++){


    printf("Please enter your names:");
	fflush(stdout);
	scanf("%s", &players[i].playername);


	printf("Please choose your classes in the order that your names were announced.\n");
	printf("0 - Elf.\n");
	printf("1 - Human.\n");
	printf("2- Ogre.\n");
	printf("3- Wizard.\n");
	fflush(stdout);

	scanf("%d", &Opt);
	switch(Opt){
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

	int lifepts = 100;

	for(i=0;i<playersize;++i){
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
		puts("");
	}

	return 0;
}










	 /* THIS IS THE END OF PART A*/

/*PART B GOES HERE*/

/*THIS IS THE END OF PART B*/

/*PART C STARTS HERE*/










