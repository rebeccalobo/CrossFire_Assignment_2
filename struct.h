#ifndef STRUCT_H
#define STRUCT_H

enum playerclass{ /* all the class types for this game are declared in an enum function*/
	Elf, Human, Ogre, Wizard
};

enum slottype{ /* all the slot types for this game are declared in an enum function*/
	LevelGround, Hill, City
};

struct player{ /* this struct allows the information (in the form of characters, integers and enumerations) to be declared here and has been called upon by functions in main.c*/
	char playername[20];
	enum playerclass class;
	enum slottype type;
	int  slotNum;
	float  lifepts;
	int capabilities;
	int  intelligence;
	int  strength;
	int  magic;
	int luck;
	int dexterity;
	int playersize;
	//Check to see who is closest to the attacking player
	int distance;
	//Used to check if player is impacted by Hill or City effect
	int Heffect;
	int Ceffect;
	//Used to ensure capabilties do not exceed max or min
	int dextemp;
	int strtemp;
	int magtemp;
}players[7]; /* an array size of 7 has been initialised for the number of players within it*/



#endif /* relates to STRUCT_H */
