#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>

int main(void)
{
	int playersize, i;

	printf("Please enter the number of players:\n");
	fflush(stdout);
	scanf("%d", &playersize);
	if(playersize>6)
	perror("The maximum number of players you can have is 6.");


	for(i=1;i<=playersize;++i){


    printf("Please enter your names:\n");
	fflush(stdout);
	scanf("%s", &players[i].playername);

	printf("Please choose your classes in the order that your names were announced\n");
	fflush(stdout);
	scanf("%s", &players[i].playerclass);
	break;


	int lifepts = 100;

	return 0;

}



