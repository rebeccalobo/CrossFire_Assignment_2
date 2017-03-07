#ifndef STRUCT_H
#define STRUCT_H

enum playerclass{
	Elf, Human, Ogre, Wizard
};

enum slottype{
	LevelGround, Hill, City
};

int playersize=0;


struct player{
	char playername[20];
	enum playerclass class;
	enum slottype type;
	int  slotNum;
	int  lifepts;
	int capabilities;
	int  intelligence;
	int  strength;
	int  magic;
	int luck;
	int dexterity;
	int playersize;
	int distance;
}players[7];



#endif /* relates to STRUCT_H */
