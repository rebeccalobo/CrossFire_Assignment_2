#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>

void capabilities(int count);

int main(void)
{
	int playersize=7, i, Opt;

	struct players p;

	printf("Please enter the number of players:\n");
	fflush(stdout);
	scanf("%d", &playersize);

	p.playersize=playersize;

	for(i=0;i<playersize;i++){
	    printf("Player %d Please enter your name: ", i+1);
		fflush(stdout);
		scanf("%s", &players[i].playername);

		printf("1 = Elf\n");
		printf("2 = Human\n");
		printf("3 = Ogre\n");
		printf("4 = Wizard\n");
		printf("Enter a number to choose your class: \n");
		fflush(stdout);
		while(Opt<1 || Opt>4){
			scanf("%d", &Opt);
		}

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

	int lifepts = 100;

	capabilities(i);

	printf("Player %d -> %s (%d , %d)\n", i+1, players[i].playername, players[i].class , lifepts);
	fflush(stdout);
	}


	return 0;
}



