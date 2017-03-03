#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int playersize, i, Opt;

	printf("Please enter the number of players:\n");
	fflush(stdout);
	scanf("%d", &playersize);



	for(i=0;i<playersize;i++){


    printf("Please enter your names:");
	fflush(stdout);
	scanf("%s", &players[i].playername);

	printf("Please choose your classes in the order that your names were announced.\n");
	printf("1 - Elf.\n");
	printf("2 - Human.\n");
	printf("3- Ogre.\n");
	printf("4- Wizard.\n");
	fflush(stdout);
	scanf("%d", &Opt);


	switch(Opt){
		case 1:{ players[i].class = 1;
		break;
		}
		case 2:{ players[i].class = 2;
		break;
		}
		case 3:{ players[i].class = 3;
		break;
		}
		case 4:{ players[i].class = 4;
		break;
		}

		}

	}




	int lifepts = 100;
	for(i=0;i<playersize;++i){
		printf("Player %d -> %s (%d , %d)\n", i+1, players[i].playername, players[i].class , lifepts);
		fflush(stdout);

	}



	return 0;

}



