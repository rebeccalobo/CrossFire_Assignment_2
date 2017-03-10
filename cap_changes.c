#ifndef CAP_CHANGES_H
#define CAP_CHANGES_H

#include <stdio.h>
#include "struct.h"

void CAP_CHANGES(int i){ /* including the content of the function which allows abilities to change based on the slot type the player is on */

	//Hill
	if(players[i].type == Hill){
		//Heffect makes sure the effect is not already applied
		if(players[i].dexterity < 50 && players[i].Heffect == 0){
			//If the players strength is too low, we can assign the current strength to 1
			//The original value gets stored in strtemp to be reassigned later
			if(players[i].strength < 11){
				players[i].strtemp = players[i].strength;
				players[i].strength = 1;
			}
			else{
				players[i].strength -= 10;
			}
			//Let Heffect=1 so we know not to re-apply the effect
			players[i].Heffect = 1;
			//Print the new strength
			printf("%s's strength is now %0.0f\n", players[i].playername, players[i].strength);
		}

		else if(players[i].dexterity >= 60 && players[i].Heffect == 0){
			//If the players strength will go over 100, the strength is set to 100
			//The original value gets stored in strtemp to be reassigned later
			if(players[i].strength > 90){
				players[i].strtemp = players[i].strength;
				players[i].strength = 100;
			}
			else{
				players[i].strength += 10;
			}
			players[i].Heffect = 1;
			printf("%s's strength is now %0.0f\n", players[i].playername, players[i].strength);
	 	}

		//Remove old effects which no longer apply
		if(players[i].Ceffect == 1){
			//Set the effect=0 so it can re-applied later on
			players[i].Ceffect=0;
			if(players[i].intelligence > 60){
				//We assigned magtemp = 0 earlier on too avoid the case where the original value for magic = 100
				//If it wasn't for this case we could use the simpler if(players[i].magtemp == 100)
				//But 100 would become 90
				if(players[i].magtemp != 0){
					players[i].magic = players[i].magtemp;
					players[i].magtemp = 0;
				}

				else{
					players[i].magic -= 10;
				}
			}

			else if(players[i].intelligence <= 50){
				if(players[i].dextemp != 0){
					players[i].dexterity = players[i].dextemp;
					players[i].dextemp = 0;
				}

				else{
					players[i].dexterity += 10;
				}
			}
		}
	}






	//City
	//Applying the same techniques from above to the city setting
	if(players[i].type == City){
		if(players[i].intelligence > 60 && players[i].Ceffect == 0){
			if(players[i].magic > 90){
				players[i].magtemp = players[i].magic;
				players[i].magic = 100;
			}
			else{
				players[i].magic += 10;
			}
			players[i].Ceffect = 1;

			printf("%s's magic skills are now %d", players[i].playername, players[i].magic);
		}

		else if(players[i].intelligence <= 50 && players[i].Ceffect == 0){
			if(players[i].dexterity < 11){
				players[i].dextemp = players[i].dexterity;
				players[i].dexterity = 1;
			}
			else{
				players[i].dexterity -= 10;
			}
			players[i].Ceffect = 1;
			printf("%s's dexterity is now %d\n", players[i].playername, players[i].dexterity);
		}

		//Remove old effects which no longer apply
		if(players[i].Heffect == 1){
			players[i].Heffect=0;
			if(players[i].dexterity < 50){
				if(players[i].strtemp != 0){
					players[i].strength = players[i].strtemp;
					players[i].strtemp = 0;
				}

				else{
					players[i].strength -= 10;
				}
			}

			else if(players[i].dexterity >= 60){
				if(players[i].strtemp != 0){
					players[i].strength = players[i].strtemp;
					players[i].strtemp = 0;
				}

				else{
					players[i].strength += 10;
				}
			}
		}
	}

	//Level ground is purely to remove effects as their are no impacts to capabilities here
	if(players[i].type == LevelGround){
		//Remove old effects which no longer apply
		//Remove City effect
		if(players[i].Ceffect == 1){
			players[i].Ceffect=0;
			if(players[i].intelligence > 60){
				if(players[i].magtemp != 0){
					players[i].magic = players[i].magtemp;
					players[i].magtemp = 0;
				}

				else{
					players[i].magic -= 10;
				}
			}

			else if(players[i].intelligence <= 50){
				if(players[i].dextemp != 0){
					players[i].dexterity = players[i].dextemp;
					players[i].dextemp = 0;
				}

				else{
					players[i].dexterity += 10;
				}
			}
			printf("City effects have been removed");
		}

		//Remove Hill effect
		if(players[i].Heffect == 1){
			players[i].Heffect=0;
			if(players[i].dexterity < 50){
				if(players[i].strtemp != 0){
					players[i].strength = players[i].strtemp;
					players[i].strtemp = 0;
				}

				else{
					players[i].strength -= 10;
				}
			}

			else if(players[i].dexterity >= 60){
				if(players[i].strtemp != 0){
					players[i].strength = players[i].strtemp;
					players[i].strtemp = 0;
				}

				else{
					players[i].strength += 10;
				}
			}
			printf("Hill effects have been removed");
		}
	}
}

#endif

